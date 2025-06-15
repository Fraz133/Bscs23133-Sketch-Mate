
#include"Circ.h"
using namespace cv;

Circles::Circles(Point cent, double rad, int thick, Scalar colr) : Shap(thick, colr), Centre(cent), Radius(rad)
{
    Count++;
}
Point Circles::getCent()
{
    return Centre;
}

double Circles::getRad()
{
    return Radius;
}
void Circles::setCent(Point cent)
{
    Centre = cent;
}
void Circles::setEnd(Point En)
{
    Radius = abs(Centre.x - En.x);
}

void Circles::draw(Mat MCANV)
{
    circle(MCANV, getCent(), getRad(), getClr(), getThick());
}


int Circles::Count = 0;
int Circles::getCount()
{
    std::cout << "Circle: ";
    return Count;
}


Circles::~Circles()
{
    Count--;
}