#include "cdglobal.h"
#include "cddevice.h"
#include "cdmsg.h"

static void EnableCDWindows(HWND Owner, USHORT Id, BOOL Enable)
{
    if ( Enable ) {
        ModalProcessing = FALSE;
        }

    if ( hwndDlg != NULLHANDLE && hwndDlg != Owner )
        WinEnableWindow(hwndDlg, Enable);

    if ( SettingsDlgInProcess && SettingsDlg != Owner )
        WinEnableWindow(SettingsDlg, Enable);
 
    if ( TitleEditorInProcess && TitleEditorDlg != Owner )
        WinEnableWindow(TitleEditorDlg, Enable);
 
    if ( ProgramEditorInProcess && ProgramEditorDlg != Owner )
        WinEnableWindow(ProgramEditorDlg, Enable);
 
    if ( InfoInProcess && Owner && InfoDlg != Owner )
        WinEnableWindow(InfoDlg, Enable);

    if ( ! Enable ) {
        CurrModalOwner = Owner;
        ModalProcessing = TRUE;
        CurrModalID = Id;
        }
}

USHORT SharewareBox(HWND Owner, PSZ Text)
{
    USHORT Result;

#if !defined(RELEASE)
    EnableCDWindows(Owner, ID_MB_SHAREWARE, FALSE);
    Result = WinMessageBox(HWND_DESKTOP, Owner, Text, ApplTitle, ID_MB_SHAREWARE,
        MB_OK | MB_HELP | MB_DEFBUTTON2 | MB_ICONEXCLAMATION | 
        MB_MOVEABLE | MB_SYSTEMMODAL);
    EnableCDWindows(Owner, ID_MB_SHAREWARE, TRUE);

    return Result;
#else
    return TRUE;
#endif
}

USHORT YesOrNo(HWND Owner, PSZ Text)
{
    USHORT Result;

    EnableCDWindows(Owner, ID_MB_YESORNO, FALSE);
    Result = WinMessageBox(HWND_DESKTOP, Owner, Text, ApplTitle, ID_MB_YESORNO,
        MB_YESNOCANCEL | MB_HELP | MB_ICONQUESTION | MB_MOVEABLE);
    EnableCDWindows(Owner, ID_MB_YESORNO, TRUE);

    return Result;
}

BOOL AreYouSure(HWND Owner, PSZ Text)
{
    USHORT Result;

    EnableCDWindows(Owner, ID_MB_AREYOUSURE, FALSE);
    Result = MBID_OK == WinMessageBox(HWND_DESKTOP, Owner, Text, ApplTitle, ID_MB_AREYOUSURE,
        MB_OKCANCEL | MB_DEFBUTTON2 | MB_HELP | MB_ICONQUESTION | MB_MOVEABLE);
    EnableCDWindows(Owner, ID_MB_AREYOUSURE, TRUE);

    return Result;
}

static void ErrBox(HWND Owner, ULONG ErrID, BOOL Fatal)
{
    USHORT Result;
    static char Buffer[1024];

    EnableCDWindows(Owner, ERRID_OFFSET + ErrID, FALSE);
    if ( ! WinLoadString(hab, NULLHANDLE, ErrID, sizeof(Buffer), Buffer) )
        Buffer[0] = 0;

    if ( ErrID >= ERR_DEVICE_MIN && ErrID <= ERR_DEVICE_MAX ) {
        strcat(Buffer, DeviceErrText);
        strcat(Buffer, "\"");
        strcat(Buffer, CDLastErrStr());
        strcat(Buffer, "\"");
        }
 
    if ( Fatal ) {
        strcat(Buffer, " ");
        strcat(Buffer, ApplKillText);
        }

    Result = WinMessageBox(HWND_DESKTOP, Owner, Buffer, ApplTitle,
        ERRID_OFFSET + ErrID,
        MB_OK | MB_HELP | MB_ERROR | MB_MOVEABLE);
    EnableCDWindows(Owner, ERRID_OFFSET + ErrID, TRUE);
}

void CDError(HWND Owner, ULONG ErrID)
{
    ErrBox(Owner, ErrID, FALSE);
}

void CDFatalError(HWND Owner, ULONG ErrID)
{
    ErrBox(Owner, ErrID, TRUE);

    if ( hwndDlg != NULLHANDLE )
        WinPostMsg(hwndDlg, WM_QUIT, NULL, NULL);
}

