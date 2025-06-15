#pragma once
#ifndef Rects_H
#define Rects_H
#include<opencv2/opencv.hpp>
#include<iostream>
#include"Shape.h"

using namespace cv;

class Rectangles :public Shap
{



public:
    Rectangles(Point StP, Point EnP, int thick, Scalar colr);

    Point getStart();

    Point getEnd();
    void setStart(Point St);
    void setEnd(Point En)override;
    void draw(Mat MCANV) override;
    int getCount() override;
    ~Rectangles() override;




private:
    Point Start;
    Point End;
    static int Count;
};
#endif