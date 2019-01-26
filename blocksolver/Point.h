#pragma once
#include <vector>
#include <array>

typedef int PointType;

// defines an arbitrary dimesional point
template<PointType DIMENSION> class Point
{
private:
	int coordinates[DIMENSION];

public:
	Point()
	{
		/*for (int i = 0; i < DIMENSION; i++)
		{
			coordinates[i] = 0;
		}*/
		coordinates = {};
	}

	Point(std::vector<PointType> predefinedCoordinates)
	{
		if (DIMENSION != predefinedCoordinates.size())
		{
			Point(this);
			return;
		}
		for (int i = 0; i < DIMENSION; i++)
		{
			coordinates[i] = predefinedCoordinates[i];
		}
	}

	Point(PointType predefinedCoordinates[DIMENSION])
	{
		for (int i = 0; i < DIMENSION; i++)
		{
			coordinates[i] = predefinedCoordinates[i];
		}
	}

	Point(int x, int y)
	{
		STATIC_ASSERT(DIMENSION == 2);
		coordinates[0] = x;
		coordinates[1] = y;
	}

	Point(int x, int y, int z)
	{
		STATIC_ASSERT(DIMENSION == 3);
		coordinates[0] = x;
		coordinates[1] = y;
		coordinates[2] = z;
	}

	~Point() 
	{

	}

	PointType operator[] (int const i)
	{
		return coordinates[i];
	}

	PointType const operator[] (int const i) const
	{
		return coordinates[i];
	}

	void operator+= (Point const& rhsPoint)
	{
		for (int i = 0; i < DIMENSION; i++)
		{
			coordinates[i] += rhsPoint[i];
		}
	}

	void operator-= (Point const& rhsPoint)
	{
		for (int i = 0; i < DIMENSION; i++)
		{
			coordinates[i] += rhsPoint[i];
		}
	}

	friend Point operator+ (Point const& leftPoint, Point const& rightPoint)
	{
		Point output(leftPoint);

		output += rightPoint;
		return output;
	}

	friend Point operator- (Point const& leftPoint, Point const& rightPoint)
	{
		Point output(leftPoint);

		output -= rightPoint;
		return output;
	}
};

typedef Point<2> Point2D;
typedef Point<3> Point3D;

