#include <math.h>
#include <stdio.h>
#include <stdlib.h>
struct Equation
{
    int coeff_x, coeff_y, constant;
};
struct Coordinate
{
    double x, y;
};
double find_distance(struct Coordinate c1, struct Coordinate c2);
double find_angle(struct Equation, struct Equation);
double find_area(struct Coordinate c1, struct Coordinate c2, struct Coordinate c3);