
/* Copyright 1984-2005 Wind River Systems, Inc. */

#include <iostream>

#include "complexlib/Complex.h"
#include "iolib/iolib.h"

using namespace std;

int main()
{
	float re, im;
	Complex a, b;
	char do_quit='n';

	cout << "Values for first number..." << endl;

	re = get_re();
	im = get_im();

	a.Set(re, im);

	cout << "Values for second number..." << endl;

	re = get_re();
	im = get_im();

	b.Set(re, im);

	a.Print();
	b.Print();

	cout << "Press q + RETURN to quit..." << endl;

	while (do_quit!='q') {
		cin >> do_quit;
	}

	return 0;
}
