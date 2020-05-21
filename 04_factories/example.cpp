/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : example.cpp
 * Created on    : Sunday 19 April 2020 10:38:22 AM IST
 * Last modified : Tuesday 21 April 2020 04:20:46 PM IST
 * Description   : 
 * ***********************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

enum class PointType{
	cartesian,
	polar
};

struct Point
{
	float x; 
	float y;

	// not sure wether its cartesian or polar form
	// Point(float x, float y) : x(x), y(y) {}
	
	Point(float a, float b, PointType type = PointType::cartesian)
	{
		if(type == PointType::cartesian){
			x = a;
			y = b;
		}
		else{
			x = a * cos(b);    // x or rho
			y = a * sin(b);    // y or theta
		}
};

int main()
{
	Point p(10, 20, PointType::polar);
	return 0;
}
