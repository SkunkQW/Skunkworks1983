/* ctors and dtors arrays -- to be used by runtime system */
/*   to call static constructors and destructors          */
/*                                                        */
/* NOTE: Use a C compiler to compile this file. If you    */
/*       are using GNU C++, be sure to use compile this   */
/*       file using a GNU compiler with the               */
/*       -fdollars-in-identifiers flag.                   */


void _GLOBAL__I__ZN10C1983DriveC2Ev();

void _GLOBAL__I__ZN9PewPewBotC2Ev();

extern void (*_ctors[])();
void (*_ctors[])() =
    {
    _GLOBAL__I__ZN10C1983DriveC2Ev,
    _GLOBAL__I__ZN9PewPewBotC2Ev,
    0
    };

void _GLOBAL__D__ZN10C1983DriveC2Ev();

void _GLOBAL__D__ZN9PewPewBotC2Ev();

extern void (*_dtors[])();
void (*_dtors[])() =
    {
    _GLOBAL__D__ZN10C1983DriveC2Ev,
    _GLOBAL__D__ZN9PewPewBotC2Ev,
    0
    };
