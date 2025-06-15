#include "Head.h"


int main()
{
    try
    {
        paint SustaPaint(500, 400);

        SustaPaint.Ran();
    }
    catch (...)
    {
        cout << "\nA problem has been found. Closing the app";
    }

    return 0;
}