#ifndef Circ_H
#define Circ_H
#include <opencv2/opencv.hpp>
#include"Shape.h"
using namespace cv;

class Circles : public Shap
{

public:
    Circles(Point cent, double rad, int thick, Scalar colr);
    Point getCent();
    void setCent(Point cent);
    double getRad();
    void setEnd(Point En)override;
    void draw(Mat MCANV) override;
    int getCount() override;
    ~Circles() override;
private:
    Point Centre;
    double Radius;
    static int Count;
};
#endif

