
/* Copyright 1984-2005 Wind River Systems, Inc. */

#include <iostream>

#include "Complex.h"

using namespace std;

float Complex::GetRe()
{
	return re;
}

float Complex::GetIm()
{
	return im;
}

void Complex::Set(float r, float i)
{
	re = r;
	im = i;
}

void Complex::SetRe(float r)
{
	re = r;
}

void Complex::SetIm(float i)
{
	im = i;
}

void Complex::Print()
{
	cout << "Re=" << re << ", Im=" << im << endl;
}
