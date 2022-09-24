/*Suppose there are two roads,
Road 1: ABC Road, represented by equation 5x + y - 3 = 0
Road 2: XYZ Road, represented by equation 2x + 3y + 1 = 0
These two roads meet each other at a chowk, called 123 Chowk.
Determine at which angle , these two roads meet each other at chowk.
What you have to do :
Create a Program which determines angle at which these roads meet at 123 Chowk.*/
#include "library.h"
#include "library.c"
void main()
{
    struct Equation eq_1 = {5, 1, -3}, eq_2 = {2, 3, 1}; // both equations were initialized by respective coefficients of x,y and constant;
    double angle_at_chowk;
    angle_at_chowk = find_angle(eq_1, eq_2);
    printf("Angle at which these roads meets at 123 chowk is: %lf degrees\n", angle_at_chowk);
}