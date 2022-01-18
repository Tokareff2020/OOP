#ifndef TRAPEZE_H
#define TRAPEZE_H
#include <iostream>
#include "Figure.h"

class Trapeze 
{
public:
    int a1, b1, h1;
    int x1, y1;


    Trapeze() : x1(0), y1(0), a1(0), b1(0), h1(0) {


    }

    Trapeze(int x1, int y1, int a1, int b1, int h1)
    {
        this->x1 = x1;
        this->y1 = y1;
        this->a1 = a1;
        this->b1 = b1;
        this->h1 = h1;
    };

    Trapeze& operator= (Trapeze &rec)
    {
        this->x1 = rec.x1;
        this->y1 = rec.y1;
        this->a1 = rec.a1;
        this->b1 = rec.b1;
        this->h1 = rec.h1;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out,const Trapeze& rec)
    {
        out << "\n";
        out << "    B------------C" << "\n";
        out << "   /              \\ " << "\n";
        out << "  /                \\ " << "\n";
        out << " /                  \\ " << "\n";
        out << "A--------------------D" << "\n";
        out << "Координаты точки A: (" << rec.x1 << "," << rec.y1 << ")\n";
        out << "Координаты точки B: (" << 1.5 * rec.x1 - rec.a1 / 2 << "," << rec.y1 + rec.h1 << ")\n";
        out << "Координаты точки C: (" << 1.5 * rec.x1 + rec.a1 / 2 << "," << rec.y1 + rec.h1 << ")\n";
        out << "Координаты точки D: (" << rec.x1 << "," << rec.y1 << ")\n";
        return out;
    }


  


    friend std::istream& operator>>(std::istream& in, Trapeze& rec)
    {
        in >> rec.x1;
        in >> rec.y1;
        in >> rec.b1;
        in >> rec.a1;
        in >> rec.h1;
        return in;
    }

    double getSquare()
    {
        std::cout << "Площадь трапеции = \t";
        return (a1 + b1) / 2 * h1;
    }




};

#endif
