#include "Point2D.h"

Point2D::Point2D() : x(0), y(0) {};

Point2D::Point2D(int otherX, int otherY) : x(otherX), y(otherY) {};
Point2D::Point2D(Point2D& other) : x(other.x), y(other.y) {};

void Point2D::Add(Point2D& other) {
	x += other.x;
	y += other.y;
}

void Point2D::Add(int otherX, int otherY) {
	this->x += otherX;
	this->y += otherY;
}

Point2D& Point2D::GetTopPosition() {
	Point2D moved(0, 1);
	moved.Add(*this);

	return moved;
}
Point2D& Point2D::GetBottomPosition() {
	Point2D moved(0, -1);
	moved.Add(*this);

	return moved;
}
Point2D& Point2D::GetLeftPosition() {
	Point2D moved(-1, 0);
	moved.Add(*this);

	return moved;
}
Point2D& Point2D::GetRightPosition() {
	Point2D moved(1, 0);
	moved.Add(*this);

	return moved;
}

bool Point2D::IsEqual(Point2D& other) {
	if (x == other.x && y == other.y) {
		return true;
	}
	return false;
}