#if !(defined(_CDMSG_INCLUDED))
#define _CDMSG_INCLUDED

USHORT SharewareBox(HWND Owner, PSZ Text);
USHORT YesOrNo(HWND Owner, PSZ Text);
BOOL AreYouSure(HWND Owner, PSZ Text);
void CDError(HWND Owner, ULONG ErrID);
void CDFatalError(HWND Owner, ULONG ErrID);

_Inline void CDOptError(BOOL Test, HWND Owner, ULONG ErrID)
{
    if ( ! Test )
        CDError(Owner, ErrID);
}

_Inline void CDOptFatalError(BOOL Test, HWND Owner, ULONG ErrID)
{
    if ( ! Test )
        CDFatalError(Owner, ErrID);
}

#endif  // !(defined(_CDMSG_INCLUDED))
