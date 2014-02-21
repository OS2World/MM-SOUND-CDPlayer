#if !(defined(_CDVOLUME_INCLUDED))
#define _CDVOLUME_INCLUDED

BOOL EnableVolume(BOOL Enable, USHORT DevID, CDAUDIO_DRIVERINFO *DriverInfo);
BOOL InitVolume(HWND hwndDlg);
BOOL ResetVolume(USHORT DevID);
MRESULT SetLeftVolume(USHORT DevID, MPARAM mp1, MPARAM mp2);
MRESULT SetRightVolume(USHORT DevID, MPARAM mp1, MPARAM mp2);
MRESULT MuteVolume(USHORT DevID, MPARAM mp1, MPARAM mp2);
MRESULT ChannelIndependent(MPARAM mp1, MPARAM mp2);
MRESULT ChannelSwap(MPARAM mp1, MPARAM mp2);

#endif // !(defined(_CDVOLUME_INCLUDED))
