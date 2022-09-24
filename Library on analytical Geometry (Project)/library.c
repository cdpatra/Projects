double find_angle(struct Equation eq_1, struct Equation eq_2)
{
    double slope_1 = -((eq_1.coeff_x) * 1.0) / eq_1.coeff_y;
    double slope_2 = -((eq_2.coeff_x) * 1.0) / eq_2.coeff_y;
    return ((atan((slope_2 - slope_1) / (1.0 + slope_2 * slope_1))) * (180.0 / 3.14));
}
double find_distance(struct Coordinate c1, struct Coordinate c2)
{
    return sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));
}
double find_area(struct Coordinate c1, struct Coordinate c2, struct Coordinate c3)
{
    double area = (c1.x * (c2.y - c3.y) + c2.x * (c3.y - c1.y) + c3.x * (c1.y - c2.y)) * 0.5;
    if (area < 0)
        return -area;
    else
        return area;
}