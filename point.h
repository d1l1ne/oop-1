#pragma once
#pragma once
class Point
{

private:
	double x_, y_;

public:
	Point();
	Point(double x, double y);
	Point(const Point& reference);
	~Point();
	void setX(double x);
	void setY(double y);
	double getX();
	double getY();
	bool isEqual(Point b);
	double getDistance(Point b);
	void move(double k);

};