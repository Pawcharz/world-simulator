#pragma once
#include "Comparable.h"

class Point2D : Comparable
{
public:
	int x;
	int y;

	Point2D();

	Point2D(int otherX, int otherY);
	Point2D(Point2D& other);
	//Point2D& operator=(Point2D& other);

	void Add(Point2D& other);

	void Add(int otherX, int otherY);

	Point2D& GetTopPosition();
	Point2D& GetBottomPosition();
	Point2D& GetLeftPosition();
	Point2D& GetRightPosition();

	bool IsEqual(Point2D& other);
};

