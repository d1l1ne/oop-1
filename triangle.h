#pragma once
#include "Point.h"
#pragma once
class Triangle
{

private:
	Point a_, b_, c_;
public:
	Triangle();
	Triangle(double ax, double ay, double bx, double by, double cx, double cy);
	Triangle(const Triangle& reference);
	~Triangle();
	void setA(double x, double y);
	void setB(double x, double y);
	void setC(double x, double y);
	void getA();
	void getB();
	void getC();
	bool isTriangle();
	void move(double k);
	double getPerimeter();
	bool isEqual(Triangle t2);
	double getAB();
	double getBC();
	double getCA();
};