#include <iostream>
#include <math.h>
#include "windows.h"
using namespace std;


struct dot {

	float x, y;

	void set(float a, float b)
	{
		x = a;
		y = b;
	}
};


class pentagon {
private:
	dot A;
	dot B;
	dot C;
	dot D;
	dot E;
	float line;

public:
	pentagon() 
	{
		A.set(0, 0);
		B.set(0, 0);
		C.set(0, 0);
		D.set(0, 0);
		E.set(0, 0);
		line = 0;
	}
	pentagon(float x, float y, float liniya)
	{
		A.set(x, y);
		line = liniya;
	}
	~pentagon()
	{
	}

	
	void input()
	{
		cout << "       C        " << endl;
		cout << "    /     \\     " << endl;
		cout << "   B       D    " << endl;
		cout << "    \\     /     " << endl;
		cout << "     A___E" << endl;
		cout << "Введите координаты точки A:";
		cin >> A.x >> A.y;
		cout << "Введите длину стороны :";
		cin >> line;
		
	}

	void output()
	{
		B.x = A.x - line * cos(108);
		B.y = A.y + line * sin(108);
		C.x = B.x + line * sin(108);
		C.y = B.y + line * cos(108);
		E.x = A.x + line;
		E.y = A.y;
		D.x = E.x + line * cos(108);
		D.y = E.y + line * sin(108);
		cout << "       C        " << endl;
		cout << "    /     \\     " << endl;
		cout << "   B       D    " << endl;
		cout << "    \\     /     " << endl;
		cout << "     A___E" << endl;
		cout << "Координаты точки A (" << A.x << "," << A.y << ")" << endl;
		cout << "Координаты точки B (" << B.x << "," << B.y << ")" << endl;
		cout << "Координаты точки C (" << C.x << "," << C.y << ")" << endl;
		cout << "Координаты точки D (" << D.x << "," << D.y << ")" << endl;
		cout << "Координаты точки E (" << E.x << "," << E.y << ")" << endl;
		cout << "Длина стороны = " << line << endl;
	}
	void hack()
	{
		std::cout << "Russian hackers again hacked american goverment. They left a message on official page of american goverment :\n 'Здесь был Ваня Иванов'";
		/*Sleep(600);
		while (true) {
			std::cout << "ERROR" << std::endl;
			std::cout << "PUTIN VODKA BALALAYKA";
		}*/
	}


};
