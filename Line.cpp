#include "Line.h"
using namespace cv;

Lines::Lines(Point StP, Point EnP, int thick, Scalar colr) : Shap(thick, colr), Start(StP), End(EnP)
{
    Count++;
}

Point Lines::getStart()
{
    return Start;
}


Point Lines::getEnd()
{
    return End;
}

void Lines::setStart(Point St)
{
    Start = St;
}
void Lines::setEnd(Point En)
{
    End = En;
}
void Lines::draw(Mat MCANV)
{
    line(MCANV, getStart(), getEnd(), getClr(), getThick());
}



int Lines::Count = 0;
int Lines::getCount()
{
    std::cout << "Line: ";
    return Count;
}

Lines::~Lines()
{
    Count--;
}   