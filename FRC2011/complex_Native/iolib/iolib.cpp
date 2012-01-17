
/* Copyright 1984-2005 Wind River Systems, Inc. */

#include <iostream>

#include "iolib.h"

using namespace std;

float get_re()
{
	float re;

	cout << "Please insert the real part: ";
	cin >> re;

	return re;
}

float get_im()
{
	float im;

	cout << "Please insert the imaginary part: ";
	cin >> im;

	return im;
}
