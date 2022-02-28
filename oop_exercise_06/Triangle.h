#pragma once
#include "figure.h"

class Triangle : public Figure {
private:
	Point a_, b_, c_;
public:
	Triangle();
	Triangle(Point t1_, Point t2_, Point t3_);
	Triangle(const Triangle& triangle);
	Triangle(std::istream& is);
	size_t VertexesNumber();
	double Area();
	void Print(std::ostream& os);
	friend std::istream& operator>>(std::istream& is, Triangle& object);
	friend std::ostream& operator<<(std::ostream& os, Triangle object);
	Triangle& operator=(const Triangle& object);
	bool operator==(const Triangle& object);

};

