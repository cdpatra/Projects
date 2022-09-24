/*Saurabh Sir stays in Bhopal,
Prateek Sir stays in Bangalore.
Using GPS:
Latitude and Longitude values of Bhopal as 23.259933 N, 77.412613 E.
Latitude and Longitude values of Bangalore as 12.9716 N, 77.5946 E.
Calculate distance between Saurabh Sir and Prateek Sir.*/
#include "library.h"
#include "library.c"
void main()
{
    struct Coordinate c1 = {23.259933, 77.412613}, c2 = {12.9716, 77.5946};
    double distance;
    distance = find_distance(c1, c2);
    printf("Distance between Saurabh Sir and Prateek Sir is %lf km\n", distance);
}