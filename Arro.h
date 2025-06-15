#pragma once
#ifndef Arros_H
#define Arros_H
#include<opencv2/opencv.hpp>
#include<iostream>
#include"Shape.h"

class Arros : public Shap
{



public:
    Arros(Point Stp, Point Enp, int thick, Scalar colr);
    Point getStart();
    Point getEnd();
    void setEnd(Point En)override;
    void setStart(Point St);
    void draw(Mat MCANV) override;
    int getCount() override;
    ~Arros() override;
private:
    Point Start;
    Point End;
    static int Count;
};
#endif
