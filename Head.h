#pragma once

#ifndef HEAD_H
#define HEAD_H

#include"Shape.h"
#include<iostream>
#include<vector>
using namespace std;
using namespace cv;

namespace ShapTypes
{
	enum Shap
	{
		Ln, Rect, Circ, Fre, Arro
	};
}

class paint
{

public:
	paint(int hei, int wid);
	~paint();

	int getHight()const;
	int getWid()const;
	void setHight(int hei);
	void setWid(int wid);

	vector<Shap*> getShap() const;
	void Add_Shap(Shap* shap);
	ShapTypes::Shap getCurrShap()const;
	void setCurrShap(ShapTypes::Shap currSh);

	void Ran();
	static void MouseCtrlsWrap(int event, int x, int y, int flags, void* param);
	void SavCANV(const string& File);

	void IncThick(); ////
	void DecThick(); ////
	void IncClr(char clr);
	void DecClr(char clr);

private:
	vector<Shap*> shap;
	void MouseCtrls(int event, int x, int y, int flags);
	Mat MCANV;
	int Hight, Wid;
	ShapTypes::Shap CurrShap;
	int Six;
	bool isdrawing;


	Scalar CurrClr; /////
	int CurrThick; ////

};

#endif