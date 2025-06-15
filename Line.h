#pragma once
#ifndef Line_H
#define Line_H

#include<opencv2/opencv.hpp>
#include<iostream>
#include"Shape.h"

using namespace cv;

class Lines :public Shap
{



public:
    Lines(Point StP, Point EnP, int thick, Scalar colr);

    Point getStart();
    void setStart(Point St);
    Point getEnd();
    void setEnd(Point En) override;
    void draw(Mat MCANV) override;
    int getCount() override;
    ~Lines() override;
private:
    Point Start;
    Point End;
    static int Count;
};
#endif
    