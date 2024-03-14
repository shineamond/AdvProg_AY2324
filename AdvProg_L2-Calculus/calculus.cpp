#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x)
{
    double old_result = 0;
    double new_result = 1;
    double i = -1;
    double operand = 1;

    while (new_result - old_result >= 0.001)
    {
        old_result = new_result;
        i += 2;
        operand = operand * (-1) / i / (i + 1) * x * x;
        new_result += operand;
    }

    return new_result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double old_result = 0;
    double new_result = x;
    double i = 1;
    double operand = x;

    while(new_result - old_result >= 0.001)
    {
        old_result = new_result;
        i += 2;
        operand = operand * (-1) / (i - 1) / i * x * x;
        new_result += operand;
    }

    return new_result;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }

    double old_result = 1;
    double new_result = old_result - (old_result * old_result - x) / 2 / old_result;

    while(new_result - old_result >= 0.001)
    {
        old_result = new_result;
        new_result = old_result - (old_result * old_result - x) / 2 / old_result;
    }

    return new_result;
}
