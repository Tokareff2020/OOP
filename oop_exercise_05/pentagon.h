#pragma once
#include <iostream>
#include <math.h>


struct dot {

	float x, y;

	void set(float a, float b)
	{
		x = a;
		y = b;
	}
};


class Pentagon {
private:
	dot A;
	dot B;
	dot C;
	dot D;
	dot E;
	float line;

public:

	Pentagon(float x, float y, float liniya)
	{
		A.set(x, y);
		line = liniya;
	}

	friend std::ostream& operator<<(std::ostream& os, Pentagon& pent) {
		pent.B.x = pent.A.x - pent.line * cos(108);
		pent.B.y = pent.A.y + pent.line * sin(108);
		pent.C.x = pent.B.x + pent.line * sin(108);
		pent.C.y = pent.B.y + pent.line * cos(108);
		pent.E.x = pent.A.x + pent.line;
		pent.E.y = pent.A.y;
		pent.D.x = pent.E.x + pent.line * cos(108);
		pent.D.y = pent.E.y + pent.line * sin(108);
		os << "       C        " << std::endl;
		os << "    /     \\     " << std::endl;
		os << "   B       D    " << std::endl;
		os << "    \\     /     " << std::endl;
		os << "     A___E" << std::endl;
		os << "Координаты точки A (" << pent.A.x << "," << pent.A.y << ")" << std::endl;
		os << "Координаты точки B (" << pent.B.x << "," << pent.B.y << ")" << std::endl;
		os << "Координаты точки C (" << pent.C.x << "," << pent.C.y << ")" << std::endl;
		os << "Координаты точки D (" << pent.D.x << "," << pent.D.y << ")" << std::endl;
		os << "Координаты точки E (" << pent.E.x << "," << pent.E.y << ")" << std::endl;
		return os << "Длина стороны = " << pent.line << std::endl;
	}

	float Area()
	{
		return 1.25 * line * line * (1 / tan(90 / 5));
	}

};
