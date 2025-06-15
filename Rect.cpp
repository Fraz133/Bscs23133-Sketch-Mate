#include "Rect.h"
using namespace cv;

Rectangles::Rectangles(Point StP, Point EnP, int thick, Scalar colr) : Shap(thick, colr), Start(StP), End(EnP)
{
    Count++;
}

Point Rectangles::getStart()
{
    return Start;
}



Point Rectangles::getEnd()
{
    return End;
}

void Rectangles::setStart(Point St)
{
    Start = St;
}
void Rectangles::setEnd(Point En)
{
    End = En;
}
void Rectangles::draw(Mat MCANV)
{
    rectangle(MCANV, getStart(), getEnd(), getClr(), getThick());
}


int Rectangles::Count = 0;
int Rectangles::getCount()
{
    std::cout << "Rect: ";
    return Count;
}

Rectangles::~Rectangles()
{
    Count--;
}