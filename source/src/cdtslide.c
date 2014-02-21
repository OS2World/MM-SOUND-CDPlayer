#include "cdglobal.h"
#include "cdplayer.h"
#include "cdtslide.h"

static USHORT TimeSliderPixels;
static BYTE *HasScaleText;

BOOL InitTimeSlider(HWND hwndDlg)
{
    WNDPARAMS WndParams;
    SLDCDATA SliderData;
    BOOL bResult;
    ULONG i;

    hwndTimeSlider = WinWindowFromID(hwndDlg, ID_TIME_SLIDER);

    TimeSliderPixels = SHORT2FROMMR(WinSendMsg(hwndTimeSlider, SLM_QUERYSLIDERINFO,
        MPFROM2SHORT(SMA_SLIDERARMPOSITION, SMA_RANGEVALUE), NULL));
    WndParams.fsStatus = WPM_CTLDATA;
    WndParams.cbCtlData = sizeof(SLDCDATA);
    WndParams.pCtlData = &SliderData;
    SliderData.cbSize = sizeof(SLDCDATA);
    SliderData.usScale1Increments = TimeSliderPixels;
    SliderData.usScale2Increments = TimeSliderPixels;
    SliderData.usScale1Spacing = 1;
    SliderData.usScale2Spacing = 1;
    bResult = LONGFROMMR(WinSendMsg(hwndTimeSlider, WM_SETWINDOWPARAMS,
        MPFROMP(&WndParams), NULL));

    HasScaleText = malloc(TimeSliderPixels);

    for ( i = 0; i < TimeSliderPixels; i++ )
        HasScaleText[i] = 0;

    return TRUE;
}


BOOL EnableTimeSlider(BOOL Enable)
{
    BOOL bResult;
    ULONG i;

    SliderSet = TRUE;
    WinSendMsg(hwndTimeSlider, SLM_SETSLIDERINFO,
        MPFROM2SHORT(SMA_SLIDERARMPOSITION, SMA_RANGEVALUE), MPFROMLONG(0));
    SliderSet = FALSE;
    if ( ! Enable ) {
        bResult = LONGFROMMR(WinSendMsg(hwndTimeSlider, SLM_SETTICKSIZE,
            MPFROM2SHORT(SMA_SETALLTICKS, 0), NULL));
 
        for ( i = 0; i < TimeSliderPixels; i++ )
            if ( HasScaleText[i] ) {
                bResult = LONGFROMMR(WinSendMsg(hwndTimeSlider, SLM_SETSCALETEXT,
                    MPFROMSHORT(i), NULL));
                HasScaleText[i] = 0;
                }

        }
    WinEnableWindow(hwndTimeSlider, Enable);

    return TRUE;
}

BOOL SetupTimeSlider(CDAUDIO_PLAYLIST *PlayList)
{
    ULONG DetentRatio, DetentPos;
    BOOL bResult;
    int i;
    char Buffer[8];

    bResult = LONGFROMMR(WinSendMsg(hwndTimeSlider, SLM_SETTICKSIZE,
        MPFROM2SHORT(SMA_SETALLTICKS, 0), NULL));

    for ( i = 0; i < TimeSliderPixels; i++ )
        if ( HasScaleText[i] ) {
            bResult = LONGFROMMR(WinSendMsg(hwndTimeSlider, SLM_SETSCALETEXT,
                MPFROMSHORT(i), NULL));
            HasScaleText[i] = 0;
            }

    DetentRatio = (PlayList->TotalLength + TimeSliderPixels/2) / TimeSliderPixels;
    for ( i = 0; i < PlayList->TotalTracks; i++) {
        DetentPos = (PlayList->Track[i].StartInPlayList + DetentRatio/2) / DetentRatio;
        bResult = LONGFROMMR(WinSendMsg(hwndTimeSlider, SLM_SETTICKSIZE,
            MPFROM2SHORT(DetentPos, 5), NULL));
        
        bResult = LONGFROMMR(WinSendMsg(hwndTimeSlider, SLM_SETSCALETEXT,
            MPFROMSHORT(DetentPos), MPFROMP(itoa(PlayList->Track[i].ToPlay, Buffer, 10))));

        HasScaleText[DetentPos] = 1;
        }

    return TRUE;
}

BOOL PosTimeSlider(CDAUDIO_POSITION *Position, CDAUDIO_PLAYLIST *PlayList)
{
    ULONG DetentRatio, DetentPos;

    if ( ! TimeSliderDragged ) {
        DetentRatio = (PlayList->TotalLength + TimeSliderPixels/2) / TimeSliderPixels;
        DetentPos = (Position->CDPlayed + DetentRatio / 2) / DetentRatio;
        SliderSet = TRUE;
        WinSendMsg(hwndTimeSlider, SLM_SETSLIDERINFO,
            MPFROM2SHORT(SMA_SLIDERARMPOSITION, SMA_RANGEVALUE),
            MPFROMLONG(DetentPos));
        SliderSet = FALSE;
        }

    return TRUE;
}

MRESULT TimeSliderControl(HWND hwndDlg, CDAUDIO_PLAYLIST *PlayList, 
    CDAUDIO_CONTENTS *Contents, MPARAM mp1, MPARAM mp2)
{
    ULONG NextTrack;
    MMTIME NextPosition;

    if ( ! SliderSet ) {
        if ( SHORT2FROMMP(mp1) == SLN_SLIDERTRACK ) {
            TimeSliderDragged = TRUE;
            }
        else if ( SHORT2FROMMP(mp1) == SLN_CHANGE ) {
            NextPosition = SHORT1FROMMR(WinSendMsg(hwndTimeSlider, SLM_QUERYSLIDERINFO,
                MPFROM2SHORT(SMA_SLIDERARMPOSITION, SMA_RANGEVALUE), NULL));
            NextPosition *=
                (PlayList->TotalLength + TimeSliderPixels/2) / TimeSliderPixels;
            for ( NextTrack = 0; NextTrack < PlayList->TotalTracks; NextTrack++) {
                if ( NextPosition >= PlayList->Track[NextTrack].StartInPlayList &&
                     NextPosition < PlayList->Track[NextTrack].StartInPlayList +
                        Contents->Track[PlayList->Track[NextTrack].ToPlay-1].Length )
                    break;
                }
            WinSendMsg(hwndDlg, CD_SEEK,  MPFROMLONG(NextTrack), MPFROMLONG(NextPosition));
            TimeSliderDragged = FALSE;
            }
        }
            
    return NULL;
}


