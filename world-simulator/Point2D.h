#pragma once
#include "utlis.h"

#include "Comparable.h"

class Point2D : Comparable
{
public:
	int x;
	int y;

	Point2D();

	Point2D(int otherX, int otherY);

	Point2D(const Point2D& other);

	Point2D& operator=(Point2D& other);


	// FIX - free space
	// start, end - coordinate boundaries (inclusive)
	// If not specified - assumes world borders
	static Point2D& Random(Point2D& start, Point2D& end);

	void Add(Point2D& other);

	void Add(int otherX, int otherY);

	Point2D& GetTopPosition();
	Point2D& GetBottomPosition();
	Point2D& GetLeftPosition();
	Point2D& GetRightPosition();

	bool IsEqual(Point2D& other);
};

