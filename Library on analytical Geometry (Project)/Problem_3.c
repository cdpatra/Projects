/*Looking at an above image, actually that image is zoomed up version of pdf file.

As we see there is ‘A’ shaped character, it has three vertices which has coordinates

Project 3: Problem Statement 3
(20.077,
11.598) , (26.526, 90.138) , (23.674, 32.579).

We have to cover the area under ‘A’ shaped character and colour it black.
Calculate area under ‘A’ shaped character*/
#include "library.h"
#include "library.c"
void main()
{
    struct Coordinate c1 = {20.077, 11.598}, c2 = {26.526, 90.138}, c3 = {23.674, 32.579};
    double area_under_A;
    area_under_A = find_area(c1, c2, c3);
    printf("Area to be coloured black: %lf sq units", area_under_A);
}