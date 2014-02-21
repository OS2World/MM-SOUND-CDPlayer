#include "cdglobal.h"
#include "cddevice.h"
#include "cdmsg.h"
#include "cdprf.h"
#include "cdvolume.h"

static BOOL VolChannelIndependent;
static BOOL VolChannelSwap;
static USHORT CurrVolLeft;
static USHORT CurrVolRight;
static USHORT OldVolLeft;
static USHORT OldVolRight;
static ULONG VolSliderPixels;

_Inline USHORT ScaleValue(USHORT Value, USHORT CurrScale, USHORT ReqScale)
{
    return (USHORT)(((ULONG)Value * ReqScale + CurrScale/2) / CurrScale);
}

BOOL EnableVolume(BOOL Enable, USHORT DevID, CDAUDIO_DRIVERINFO *DriverInfo)
{
    ULONG VolLeft, VolRight;
    BOOL bResult;

    if ( Enable && DriverInfo->CanSetVolume ) {
        WinEnableWindow(hwndChannelSwap, DriverInfo->CanSwapChannels);        

        if ( CDPrfLoadVolume(&VolLeft, &VolRight) ) {
            bResult = CDSetVolume(DevID, VolLeft, VolRight);
            // CDOptError(bResult, hwnd, ERR_DEVICE_SETVOLUME);
            }
        else {
            VolLeft = VolRight = 100;
            bResult = CDQueryVolume(DevID, &VolLeft, &VolRight);
            // CDOptError(bResult, hwnd, ERR_DEVICE_QUERYVOLUME);
            }

        CurrVolLeft = VolLeft;
        CurrVolRight = VolRight;

        if ( VolLeft == VolRight ) {
            VolChannelIndependent = FALSE;
            WinSendMsg(hwndChannelIndependent, BM_SETCHECK, MPFROMSHORT(0), NULL);
            }
        else {
            VolChannelIndependent = TRUE;
            WinSendMsg(hwndChannelIndependent, BM_SETCHECK, MPFROMSHORT(1), NULL);
            }

        OldVolLeft = ScaleValue(VolLeft, 100, VolSliderPixels-1);
        OldVolRight = ScaleValue(VolRight, 100, VolSliderPixels-1);
        SliderSet = TRUE;
        WinSendMsg(hwndVolumeLeft, SLM_SETSLIDERINFO,
            MPFROM2SHORT(SMA_SLIDERARMPOSITION, SMA_RANGEVALUE),
            MPFROMSHORT(OldVolLeft));
        WinSendMsg(hwndVolumeRight, SLM_SETSLIDERINFO,
            MPFROM2SHORT(SMA_SLIDERARMPOSITION, SMA_RANGEVALUE),
            MPFROMSHORT(OldVolRight));
        SliderSet = FALSE;
        }
    else {
        SliderSet = TRUE;
        WinSendMsg(hwndVolumeLeft, SLM_SETSLIDERINFO,
            MPFROM2SHORT(SMA_SLIDERARMPOSITION, SMA_RANGEVALUE),
            MPFROMSHORT(VolSliderPixels-1));
        WinSendMsg(hwndVolumeRight, SLM_SETSLIDERINFO,
            MPFROM2SHORT(SMA_SLIDERARMPOSITION, SMA_RANGEVALUE),
            MPFROMSHORT(VolSliderPixels-1));
        SliderSet = FALSE;
 
        WinSendMsg(hwndChannelIndependent, BM_SETCHECK, MPFROMLONG(0), NULL);
        WinSendMsg(hwndChannelSwap, BM_SETCHECK, MPFROMLONG(0), NULL);
        WinEnableWindow(WinWindowFromID(hwndDlg, ID_GROUP_OUTPUT), FALSE);
        WinEnableWindow(hwndVolumeLeft, FALSE);
        WinEnableWindow(hwndVolumeRight, FALSE);
        WinEnableWindow(hwndChannelIndependent, FALSE);
        WinEnableWindow(hwndChannelSwap, FALSE);
        WinEnableWindow(hwndMute, FALSE);
        }

    return TRUE;
}

BOOL InitVolume(HWND hwndDlg)
{
    WNDPARAMS WndParams;
    SLDCDATA SliderData;
    BOOL bResult;

    hwndVolumeLeft = WinWindowFromID(hwndDlg, ID_VOLUME_LEFT);
    hwndVolumeRight = WinWindowFromID(hwndDlg, ID_VOLUME_RIGHT);
    hwndChannelIndependent = WinWindowFromID(hwndDlg, ID_CHANNEL_INDEPENDENT);
    hwndChannelSwap = WinWindowFromID(hwndDlg, ID_CHANNEL_SWAP);
    hwndMute = WinWindowFromID(hwndDlg, ID_MUTE);

    VolSliderPixels = SHORT2FROMMR(WinSendMsg(hwndVolumeLeft, SLM_QUERYSLIDERINFO,
        MPFROM2SHORT(SMA_SLIDERARMPOSITION, SMA_RANGEVALUE), NULL));
    WndParams.fsStatus = WPM_CTLDATA;
    WndParams.cbCtlData = sizeof(SLDCDATA);
    WndParams.pCtlData = &SliderData;
    SliderData.cbSize = sizeof(SLDCDATA);
    SliderData.usScale1Increments = VolSliderPixels;
    SliderData.usScale2Increments = VolSliderPixels;
    SliderData.usScale1Spacing = 1;
    SliderData.usScale2Spacing = 1;
    bResult = LONGFROMMR(WinSendMsg(hwndVolumeLeft, WM_SETWINDOWPARAMS,
        MPFROMP(&WndParams), NULL));
    bResult = LONGFROMMR(WinSendMsg(hwndVolumeRight, WM_SETWINDOWPARAMS,
        MPFROMP(&WndParams), NULL));

    WinSendMsg(hwndMute, GBM_SETBITMAPINDEX, MPFROMSHORT(GB_DISABLE),
        MPFROMSHORT(1));
    WinSendMsg(hwndMute, GBM_SETBITMAPINDEX, MPFROMSHORT(GB_DOWN),
        MPFROMSHORT(2));

    VolChannelSwap = FALSE;

    return TRUE;
}

BOOL ResetVolume(USHORT DevID)
{
    return CDSetVolume(DevID, CurrVolLeft, CurrVolRight);
}

MRESULT SetLeftVolume(USHORT DevID, MPARAM mp1, MPARAM mp2)
{
    USHORT NewVolume, VolumeScaled;
    BOOL bResult;

    if ( ( SHORT2FROMMP(mp1) == SLN_CHANGE ||
           SHORT2FROMMP(mp1) == SLN_SLIDERTRACK ) && ! SliderSet ) {
        NewVolume = SHORT1FROMMR(WinSendMsg(hwndVolumeLeft, SLM_QUERYSLIDERINFO,
            MPFROM2SHORT(SMA_SLIDERARMPOSITION, SMA_RANGEVALUE), NULL));

        if ( NewVolume != OldVolLeft ) {
            VolumeScaled = ScaleValue(NewVolume, VolSliderPixels-1, 100);

            if ( ! VolChannelIndependent ) {
                CurrVolLeft = VolumeScaled;
                CurrVolRight = VolumeScaled;

                OldVolLeft = OldVolRight = NewVolume;
                SliderSet = TRUE;
                WinSendMsg(hwndVolumeRight, SLM_SETSLIDERINFO,
                    MPFROM2SHORT(SMA_SLIDERARMPOSITION, SMA_RANGEVALUE),
                    MPFROMSHORT(NewVolume));
                SliderSet = FALSE;
                bResult = CDSetVolume(DevID, VolumeScaled, VolumeScaled);
                // CDOptError(bResult, hwnd, ERR_DEVICE_SETVOLUME);
                }
            else {
                CurrVolLeft = VolumeScaled;

                OldVolLeft = NewVolume;
                bResult = CDSetVolume(DevID, VolumeScaled, -1);
                // CDOptError(bResult, hwnd, ERR_DEVICE_SETVOLUME);
                }

            if ( SaveVolume ) {
                bResult = CDPrfSaveVolume(CurrVolLeft, CurrVolRight);
                }
            }
        }

    return NULL;
}

MRESULT SetRightVolume(USHORT DevID, MPARAM mp1, MPARAM mp2)
{
    USHORT NewVolume, VolumeScaled;
    BOOL bResult;

    if ( ( SHORT2FROMMP(mp1) == SLN_CHANGE ||
           SHORT2FROMMP(mp1) == SLN_SLIDERTRACK ) && ! SliderSet ) {
        NewVolume = SHORT1FROMMR(WinSendMsg(hwndVolumeRight, SLM_QUERYSLIDERINFO,
            MPFROM2SHORT(SMA_SLIDERARMPOSITION, SMA_RANGEVALUE), NULL));

        if ( NewVolume != OldVolRight ) {
            VolumeScaled = ScaleValue(NewVolume, VolSliderPixels-1, 100);

            if ( ! VolChannelIndependent ) {
                CurrVolLeft = VolumeScaled;
                CurrVolRight = VolumeScaled;

                OldVolLeft = OldVolRight = NewVolume;
                SliderSet = TRUE;
                WinSendMsg(hwndVolumeLeft, SLM_SETSLIDERINFO,
                    MPFROM2SHORT(SMA_SLIDERARMPOSITION, SMA_RANGEVALUE),
                    MPFROMSHORT(NewVolume));
                SliderSet = FALSE;
                bResult = CDSetVolume(DevID, VolumeScaled, VolumeScaled);
                // CDOptError(bResult, hwnd, ERR_DEVICE_SETVOLUME);
                }
            else {
                CurrVolRight = VolumeScaled;

                OldVolRight = NewVolume;
                bResult = CDSetVolume(DevID, -1, VolumeScaled);
                // CDOptError(bResult, hwnd, ERR_DEVICE_SETVOLUME);
                }

            if ( SaveVolume ) {
                bResult = CDPrfSaveVolume(CurrVolLeft, CurrVolRight);
                }
            }
        }

    return NULL;
}

MRESULT MuteVolume(USHORT DevID, MPARAM mp1, MPARAM mp2)
{
    BOOL bResult;

    if ( SHORT2FROMMP(mp1) == GBN_BUTTONDOWN ) {
        bResult = CDMuteVolume(DevID, TRUE);
        // CDOptError(bResult, hwnd, ERR_DEVICE_MUTEVOLUME);
        WinSendMsg(MainMenu, MM_SETITEMTEXT, MPFROMSHORT(ID_MUTE),
            MPFROMP(MuteOnText));
        WinSendMsg(sysSubmenu, MM_SETITEMTEXT, MPFROMSHORT(ID_MUTE),
            MPFROMP(MuteOnText));
        }
    else if ( SHORT2FROMMP(mp1) == GBN_BUTTONUP ) {
        bResult = CDMuteVolume(DevID, FALSE);
        // CDOptError(bResult, hwnd, ERR_DEVICE_MUTEVOLUME);
        WinSendMsg(MainMenu, MM_SETITEMTEXT, MPFROMSHORT(ID_MUTE),
            MPFROMP(MuteOffText));
        WinSendMsg(sysSubmenu, MM_SETITEMTEXT, MPFROMSHORT(ID_MUTE),
            MPFROMP(MuteOffText));
        }

    return NULL;
}

MRESULT ChannelIndependent(MPARAM mp1, MPARAM mp2)
{
    VolChannelIndependent = (BOOL)SHORT1FROMMR(WinSendMsg(hwndChannelIndependent,
        BM_QUERYCHECK, NULL, NULL));

    return NULL;
}

MRESULT ChannelSwap(MPARAM mp1, MPARAM mp2)
{
    VolChannelSwap = (BOOL)SHORT1FROMMR(WinSendMsg(hwndChannelSwap,
        BM_QUERYCHECK, NULL, NULL));

    return NULL;
}


