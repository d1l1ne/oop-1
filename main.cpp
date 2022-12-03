#include <iostream>
#include <string>
#include "Point.h"
#include "Triangle.h"
#include <vector>

using namespace std;

bool isPointInCircle(Point a, double R);
void PointInput(Point& a);
void PointOutput(Point a);
double IsOk(char coor);
bool isEqualSquare(Triangle q, Triangle w);
void tOutput(Triangle q);

int main() {

	cout << "Point: " << endl << endl;
	vector <Point> PointArray;
	int temp(0);

	while (true) {

		cout << temp << ":" << endl;
		double x = IsOk('X');
		double y = IsOk('Y');
		PointArray.push_back(Point(x, y));
		if (PointArray.at(temp).getX() == 0 && PointArray.at(temp).getY() == 0)break;
		temp++;

	}

	if (isPointInCircle(PointArray.at(0), 1)) {
		cout << "Point 0 is in a circle" << endl;
	}
	else {
		cout << "Point 0 is not in this circle" << endl;
	}

	cout << "Point 0: " << endl;
	PointOutput(PointArray.at(0));

	PointArray.at(0).setX(40);
	PointArray.at(0).setY(40);

	cout << "Point 0 after setx and sety:" << endl;
	PointOutput(PointArray.at(0));

	try {
		if (PointArray.at(0).isEqual(PointArray.at(1))) {
			cout << "Points 0 and 1 are equal" << endl;
		}
		else {
			cout << "Points 0 and 1 are not equal" << endl;
		}
	}
	catch (exception) {
		cout << "Not enough points in array" << endl;
	}

	try {
		cout << "Distance between points 0 and 1: " << PointArray.at(0).getDistance(PointArray.at(1)) << endl;
	}
	catch (exception) {
		cout << "Not enough points in array" << endl;
	}

	PointArray.at(0).move(1.1);
	cout << "Point 0 after move:" << endl;
	PointOutput(PointArray.at(0));

	PointInput(PointArray.at(0));
	cout << "Point 0 after changing:" << endl;
	PointOutput(PointArray.at(0));

	Point clonedP;
	clonedP = PointArray.at(0);
	cout << "Cloned point 0:" << endl;
	PointOutput(clonedP);

	cout << "Triangle:" << endl << endl;

	Triangle t1, t2, t3;
	t1.setA(1, 1);
	t1.setB(5, 13);
	t1.setC(8, 4);
	t2.setA(1, 1);
	t2.setB(5, 13);
	t2.setC(8, 4);
	t3.setA(4, 3);
	t3.setB(11, 5);
	t3.setC(3, -1);
	cout << "t1: ";
	tOutput(t1);
	cout << endl;
	cout << "t2: ";
	tOutput(t2);
	cout << endl;
	cout << "t3: ";
	tOutput(t3);
	cout << endl;

	if (t1.isTriangle()) {
		cout << "t1 is a triangle" << endl;
	}
	else {
		cout << "t1 isnt a triangle" << endl;
	}
	cout << "t1 perimeter: " << t1.getPerimeter() << endl;

	if (t1.isEqual(t2)) {
		cout << "t1 and t2 are equal" << endl;
	}
	else {
		cout << "t1 and t2 arent equal" << endl;
	}
	if (t1.isEqual(t3)) {
		cout << "t1 and t3 are equal" << endl;
	}
	else {
		cout << "t1 and t3 arent equal" << endl;
	}
	if (t2.isEqual(t3)) {
		cout << "t3 and t2 are equal" << endl;
	}
	else {
		cout << "t3 and t2 arent equal" << endl;
	}
	t1.move(1.1);
	cout << "t1 after moving: ";
	tOutput(t1);
	cout << endl;
	if (isEqualSquare(t1, t2)) {
		cout << "t1 and t2 have equal squares" << endl;
	}
	else {
		cout << "t1 and t2 have different squares" << endl;
	}
	if (isEqualSquare(t1, t3)) {
		cout << "t1 and t3 have equal squares" << endl;
	}
	else {
		cout << "t1 and t3 have different squares" << endl;
	}
	if (isEqualSquare(t3, t2)) {
		cout << "t3 and t2 have equal squares" << endl;
	}
	else {
		cout << "t3 and t2 have different squares" << endl;
	}

	system("pause");
	return 0;

}
//Funcs
bool isPointInCircle(Point a, double R) {

	if (a.getX() * a.getX() + a.getY() * a.getY() <= R * R) {
		return true;
	}
	else {
		return false;
	}

}
void PointInput(Point& a) {
	a.setX(IsOk('X'));
	a.setY(IsOk('Y'));
}
void PointOutput(Point a) {
	cout << "X: " << a.getX() << endl;
	cout << "Y: " << a.getY() << endl;
}
double IsOk(char coor) {

	string input;
	double result;
	while (true) {
		cout << "Enter " << coor << ": ";
		cin >> input;
		try {
			result = stof(input);
		}
		catch (exception) {
			cout << "Invalid value" << endl;
			continue;
		}
		break;
	}
	cout << endl;
	return result;
}
bool isEqualSquare(Triangle q, Triangle w) {
	double qsq = sqrt(q.getPerimeter() / 2 * (q.getPerimeter() / 2 - q.getAB()) * (q.getPerimeter() / 2 - q.getBC()) * (q.getPerimeter() / 2 - q.getCA()));
	double wsq = sqrt(w.getPerimeter() / 2 * (w.getPerimeter() / 2 - w.getAB()) * (w.getPerimeter() / 2 - w.getBC()) * (w.getPerimeter() / 2 - w.getCA()));
	return qsq == wsq;
}
void tOutput(Triangle q) {
	q.getA();
	q.getB();
	q.getC();
}

//Point
Point::Point() {
	x_ = 0;
	y_ = 0;
}
Point::Point(double x, double y) {
	x_ = x;
	y_ = y;
}
Point::Point(const Point& reference) {
	x_ = reference.x_;
	y_ = reference.y_;
}
Point::~Point() {
}

double Point::getX() {
	return x_;
}
double Point::getY() {
	return y_;
}
void Point::setX(double x) {
	x_ = x;
}
void Point::setY(double y) {
	y_ = y;
}
bool Point::isEqual(Point b) {
	if (x_ == b.getX() && y_ == b.getY()) {
		return true;
	}
	else {
		return false;
	}
}
double Point::getDistance(Point b) {
	return sqrt((b.getX() - x_) * (b.getX() - x_) + (b.getY() - y_) * (b.getY() - y_));
}
void Point::move(double k) {
	x_ += k;
	y_ += k;
}
//Triangle
Triangle::Triangle() {
	a_.setX(0);
	a_.setY(0);
	b_.setX(0);
	b_.setY(0);
	c_.setX(0);
	c_.setY(0);
}
Triangle::Triangle(double ax, double ay, double bx, double by, double cx, double cy) {
	a_.setX(ax);
	a_.setY(ay);
	b_.setX(bx);
	b_.setY(by);
	c_.setX(cx);
	c_.setY(cy);
}
Triangle::Triangle(const Triangle& reference) {
	a_ = reference.a_;
	b_ = reference.b_;
	c_ = reference.c_;
}
Triangle::~Triangle() {

}

void Triangle::setA(double x, double y) {
	a_.setX(x);
	a_.setY(y);
}
void Triangle::setB(double x, double y) {
	b_.setX(x);
	b_.setY(y);
}
void Triangle::setC(double x, double y) {
	c_.setX(x);
	c_.setY(y);
}
void Triangle::getA() {
	cout << "A: " << a_.getX() << ", " << a_.getY() << endl;
}
void Triangle::getB() {
	cout << "B: " << b_.getX() << ", " << b_.getY() << endl;
}
void Triangle::getC() {
	cout << "C: " << c_.getX() << ", " << c_.getY() << endl;
}
bool Triangle::isTriangle() {
	if ((c_.getX() - a_.getX()) / (b_.getX() - a_.getX()) == (c_.getY() - a_.getY()) / (b_.getY() - a_.getY())) {
		return false;
	}
	else {
		return true;
	}
}
bool Triangle::isEqual(Triangle t2) {
	if (((a_.getX() == t2.a_.getX()&& a_.getY() == t2.a_.getY())&&(((b_.getX() == t2.b_.getX() && b_.getY() == t2.b_.getY())&& (c_.getX() == t2.c_.getX() && c_.getY() == t2.c_.getY()))|| ((b_.getX() == t2.c_.getX() && b_.getY() == t2.c_.getY()) && (c_.getX() == t2.b_.getX() && c_.getY() == t2.b_.getY()))))||
		((a_.getX() == t2.b_.getX() && a_.getY() == t2.b_.getY()) && (((b_.getX() == t2.a_.getX() && b_.getY() == t2.a_.getY()) && (c_.getX() == t2.c_.getX() && c_.getY() == t2.c_.getY())) || ((b_.getX() == t2.c_.getX() && b_.getY() == t2.c_.getY()) && (c_.getX() == t2.a_.getX() && c_.getY() == t2.a_.getY()))))||
		((a_.getX() == t2.c_.getX() && a_.getY() == t2.c_.getY()) && (((a_.getX() == t2.a_.getX() && a_.getY() == t2.a_.getY()) && (b_.getX() == t2.b_.getX() && b_.getY() == t2.b_.getY())) || ((a_.getX() == t2.b_.getX() && a_.getY() == t2.b_.getY()) && (b_.getX() == t2.a_.getX() && b_.getY() == t2.a_.getY()))))) {
		return true;
	}
	else {
		return false;
	}
}
double Triangle::getPerimeter() {
	return a_.getDistance(b_) + b_.getDistance(c_) + c_.getDistance(a_);
}
void Triangle::move(double k) {
	a_.setX(a_.getX() + k);
	a_.setY(a_.getY() + k);
	b_.setX(b_.getX() + k);
	b_.setY(b_.getY() + k);
	c_.setX(c_.getX() + k);
	c_.setY(c_.getY() + k);
}
double Triangle::getAB() {
	return a_.getDistance(b_);
}
double Triangle::getBC() {
	return b_.getDistance(c_);
}
double Triangle::getCA() {
	return c_.getDistance(a_);
}