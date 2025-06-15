#include "Shape.h"

Shap::Shap(int thick, Scalar colr) : Thickness(thick), Clr(colr)
{

}

Shap::~Shap()
{

}

cv::Scalar Shap::getClr()  const
{
	return Clr;
}

int Shap::getThick() const
{
	return Thickness;
}

void Shap::setThick(int thick)
{
	Thickness = thick;
}
void Shap::setClr(cv::Scalar colr)
{
	Clr = colr;
}

