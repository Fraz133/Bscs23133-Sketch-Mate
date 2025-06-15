#include "FreLine.h"
using namespace cv;
using namespace std;

FreLines::FreLines(Point StP, int thick, Scalar colr) : Shap(thick, colr), Start(StP)
{
    VPoint.push_back(Start);
    Count++;
}


vector<Point> FreLines::getPoint2()
{
    return VPoint;
}
Point FreLines::getPoint1(int i)
{
    return VPoint[i];
}
Point FreLines::getStart()
{
    return Start;
}
void FreLines::setEnd(Point En)
{
    VPoint.push_back(En);
}
void FreLines::draw(Mat MCANV)
{
    for (int i = 0; i + 1 < getPoint2().size(); i++)
    {
        line(MCANV, getPoint1(i), getPoint1(i + 1), getClr(), getThick());
    }
}



int FreLines::Count = 0;
int FreLines::getCount()
{
    std::cout << "FreeLine: ";
    return Count;
}


FreLines::~FreLines()
{
    Count--;
}