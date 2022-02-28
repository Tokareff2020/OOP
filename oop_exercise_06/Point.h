#pragma once
#include <iostream>

class Point {
public:
	Point();
	Point(std::istream& is);
	Point(double x, double y);

	double dist(const Point& other);

	friend std::istream& operator>>(std::istream& is, Point& p);
	friend std::ostream& operator<<(std::ostream& os, Point& p);
	bool operator==(const Point& p);
	Point& operator=(const Point& p);

private:
	double x_;
	double y_;
};
