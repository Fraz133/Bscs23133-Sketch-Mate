#include "Head.h"
#include "Line.h"
#include "Rect.h"
#include "Circ.h"
#include "Arro.h"
#include "FreLine.h"

using namespace cv;
using namespace std;

paint::paint(int hei, int wid) : Hight(hei), Wid(wid)
{
    CurrShap = ShapTypes::Ln;
    MCANV = Mat(Hight, Wid, CV_8UC3, Scalar(255, 255, 255));
    namedWindow("Susta Paint", WINDOW_NORMAL);

    CurrClr = Scalar(0, 0, 0);   // Init Currclr and curr thick  ////
    CurrThick = 2;                                               ////

    setMouseCallback("Susta Paint", paint::MouseCtrlsWrap, this);
}

paint::~paint()
{
    for (auto shape : shap)
    {
        delete shape;
    }
    shap.clear();
}

int paint::getHight() const
{
    return Hight;
}

void paint::setHight(int hei)
{
    Hight = hei;
}

void paint::setCurrShap(ShapTypes::Shap currSh)
{
    CurrShap = currSh;
}

ShapTypes::Shap paint::getCurrShap() const
{
    return CurrShap;
}

int paint::getWid() const
{
    return Wid;
}

void paint::setWid(int wid)
{
    Wid = wid;
}

vector<Shap*> paint::getShap() const
{
    return shap;
}

void paint::Add_Shap(Shap* shape)
{
    shap.push_back(shape);
}

void paint::MouseCtrlsWrap(int event, int x, int y, int flags, void* param)
{
    paint* app = static_cast<paint*>(param);
    app->MouseCtrls(event, x, y, flags);
}

void paint::MouseCtrls(int event, int x, int y, int flags)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        isdrawing = true;
        if (getCurrShap() == ShapTypes::Ln)
        {
            Add_Shap(new Lines(Point(x, y), Point(x, y), CurrThick, CurrClr));
        }
        else if (getCurrShap() == ShapTypes::Rect)
        {
            Add_Shap(new Rectangles(Point(x, y), Point(x, y), CurrThick, CurrClr));
        }
        else if (getCurrShap() == ShapTypes::Circ)
        {
            Add_Shap(new Circles(Point(x, y), 0, CurrThick, CurrClr));
        }
        else if (getCurrShap() == ShapTypes::Arro)
        {
            Add_Shap(new Arros(Point(x, y), Point(x, y), CurrThick, CurrClr));
        }
        else
        {
            Add_Shap(new FreLines(Point(x, y), CurrThick, CurrClr));
        }
        return;
    }
    if (event == EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON))
    {
        shap.back()->setEnd(Point(x, y));
        return;
    }

    if (event == EVENT_LBUTTONUP && !(flags & EVENT_FLAG_SHIFTKEY))
    {
        shap.back()->draw(MCANV);
        isdrawing = false;
        return;
    }
}

void paint::SavCANV(const string& File)
{
    try
    {
        imwrite(File, MCANV);
    }
    catch (const exception& ex)
    {
        cout << "Exception has been found in save Fn" << endl;
        throw;
    }
}

void paint::IncThick()
{
    CurrThick++;
}

void paint::DecThick()
{
    if (CurrThick > 1)
        CurrThick--;
}

void paint::IncClr(char clr)
{
    switch (clr)
    {
    case 'R':
        CurrClr[2] += 10;
        break;
    case 'G':
        CurrClr[1] += 10;
        break;
    case 'B':
        CurrClr[0] += 10;
        break;
    }
}

void paint::DecClr(char clr)
{
    switch (clr)
    {
    case 'r':
        CurrClr[2] -= 10;
        break;
    case 'g':
        CurrClr[1] -= 10;
        break;
    case 'b':
        CurrClr[0] -= 10;
        break;
    }
}

void paint::Ran()
{
    while (true)
    {
        try
        {
            if (isdrawing)
            {
                Mat TCANV = MCANV.clone();
                for (int i = 0; i < shap.size(); i++)
                {
                    shap.at(i)->draw(TCANV);
                }
                imshow("Susta Paint", TCANV);
            }
            else
            {
                imshow("Susta Paint", MCANV);
            }
            char key = waitKey(1);

            switch (key)
            {
            case '5':
                setCurrShap(ShapTypes::Fre);
                break;
            case '4':
                setCurrShap(ShapTypes::Arro);
                break;
            case '3':
                setCurrShap(ShapTypes::Circ);
                break;
            case '2':
                setCurrShap(ShapTypes::Rect);
                break;
            case '1':
                setCurrShap(ShapTypes::Ln);
                break;
            case 'a':
            case 'A':
                for (int i = 0; i < shap.size(); i++)
                {
                    cout << shap.at(i)->getCount() << endl;
                }
                break;
            case 's':
            case 'S':
                //imwrite("Susta Paint.png", MCANV); //without Fn
                //SavCANV("Susta Paint.jpg"); // Correct
                SavCANV("Susta Paint"); //For Lab 9 Task 2
                break;
            case 'c':
            case 'C':
                for (auto shape : shap)
                {
                    delete shape;
                }
                shap.clear();
                MCANV = Scalar(255, 255, 255);
                break;
            case 27: // Esc
                destroyAllWindows();
                return;
            case '+':
                IncThick();
                break;
            case '-':
                DecThick();
                break;
            case 'B':
            case 'G':
            case 'R':
                IncClr(key);
                break;
            case 'b':
            case 'g':
            case 'r':
                DecClr(key);
                break;
            }
        }
        catch (...)
        {
            cout << "The app is closing now";
            for (int i = 0; i < shap.size(); i++)
            {
                delete shap.at(i);
            }
            shap.clear();
            throw;
        }
    }
}

