/* b_spin.h - class declarations for the spin object */

/* Copyright 2004 Wind River Systems, Inc. */

/*
modification history
--------------------
01a,07oct04,f_b   added
*/

#include "b_ball.h"

/****************************************************************
    A spinnin ball deflects the incoming ball and turns it. 
****************************************************************/
class SPIN : public BALL
{
public:
    int Collide();
    virtual char Show();
    virtual POINT Bounce( POINT & );
};
