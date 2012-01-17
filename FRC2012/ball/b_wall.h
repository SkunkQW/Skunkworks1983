/* b_wall.h - class declarations for wall objects */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,07oct04,f_b   added
*/

#include "b_hard.h"

/****************************************************************
    A wall in the X direction is a vertical wall that deflects
    balls by changing the X component of their change vector.
****************************************************************/
class WALLX : public HARD
{
public:
    WALLX(int);
    POINT Bounce( POINT & );     
    char Show();
};

/****************************************************************
    A wall in the Y direction is a horizontal wall that deflects
    balls by changing the Y component of their change vector.
****************************************************************/
class WALLY : public HARD
{
public:
    WALLY(int);
    POINT Bounce( POINT & );
    char Show();
};
