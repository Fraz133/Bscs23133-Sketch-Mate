#pragma once
#ifndef Shape_H
#define Shape_H
#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
using namespace cv;

class Shap
{



public:
	Shap(int thick, Scalar colr);


	Scalar getClr()const;
	int getThick()const;

	void setThick(int thick);
	void setClr(Scalar colr);

	virtual void setEnd(Point) = 0;
	virtual void draw(Mat MCANV) = 0;

	virtual ~Shap();

	virtual int getCount() = 0;

private:

	int Thickness;
	Scalar Clr;
};
#endif
