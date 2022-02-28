#include "triangle.h"
#include <math.h>

Triangle::Triangle() : a_(0, 0), b_(0, 0), c_(0, 0) {}

Triangle::Triangle(Point t1_, Point t2_, Point t3_) : a_(t1_), b_(t2_), c_(t3_) {}

Triangle::Triangle(const Triangle& triangle) {
    this->a_ = triangle.a_;
    this->b_ = triangle.b_;
    this->c_ = triangle.c_;
}

Triangle::Triangle(std::istream& is) {
    std::cin >> a_ >> b_ >> c_;
}

size_t Triangle::VertexesNumber() {
    return (size_t)3;
}

double Triangle::Area() {
    double a = a_.dist(b_);
    double b = b_.dist(c_);
    double c = c_.dist(a_);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::Print(std::ostream& os) {
    std::cout << "Triangle " << a_ << b_ << c_ << std::endl;
}

std::istream& operator>>(std::istream& is, Triangle& object) {
    is >> object.a_ >> object.b_ >> object.c_;
    return is;
}

std::ostream& operator<<(std::ostream& os, Triangle object) {
    os << "a side = " << object.a_.dist(object.b_) << std::endl;
    os << "b side = " << object.b_.dist(object.c_) << std::endl;
    os << "c side = " << object.c_.dist(object.a_) << std::endl;

    return os;
}

Triangle& Triangle::operator=(const Triangle& object) {
    this->a_ = object.a_;
    this->b_ = object.b_;
    this->c_ = object.c_;
    return *this;
}

bool Triangle::operator==(const Triangle& object) {
    if (this->a_ == object.a_ && this->b_ == object.b_ && this->c_ == object.c_) {
        return true;
    }
    else return false;
}
