#pragma once
#ifndef FreLines_H
#define FreLines_H
#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
#include"Shape.h"
using namespace cv;
using namespace std;

class FreLines :public Shap
{


public:
    FreLines(Point StP, int thick, Scalar colr);

    Point getStart();
    Point getPoint1(int i);

    vector<Point> getPoint2();
    void setEnd(Point En)override;
    void draw(Mat MCANV) override;
    int getCount() override;
    ~FreLines() override;
private:
    Point Start;
    vector<Point> VPoint;
    static int Count;
};
#endif