
/* Copyright 1984-2005 Wind River Systems, Inc. */

class Complex
{
private:
	float re;
	float im;
public:
	float GetRe();
	float GetIm();
	void Set(float r, float i);
	void SetRe(float r);
	void SetIm(float i);
	void Print();
};
