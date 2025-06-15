#include"Arro.h"
using namespace cv;

Arros::Arros(Point StP, Point EnP, int thick, Scalar colr) : Shap(thick, colr), Start(StP), End(EnP)
{
    Count++;
}

Point Arros::getStart()
{
    return Start;
}



Point Arros::getEnd()
{
    return End;
}

void Arros::setStart(Point St)
{
    Start = St;
}

void Arros::setEnd(Point En)
{
    End = En;
}
void Arros::draw(Mat MCANV)
{
    arrowedLine(MCANV, getStart(), getEnd(), getClr(), getThick());
}


int Arros::Count = 0;
int Arros::getCount()
{
    std::cout << "ArrowLine: ";
    return Count;
}


Arros::~Arros()
{
    Count--;
}