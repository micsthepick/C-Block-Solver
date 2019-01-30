#pragma once
#include <vector>
#include <array>

typedef int PointScalarType;

// defines an arbitrary dimesional point
template<PointScalarType DIMENSION> class Point
{
private:
	int coordinates[DIMENSION] = {};

public:

	// Create a point at the origin ({ 0, 0, ..., 0 })
	Point()
	{
		for (int i = 0; i < DIMENSION; ++i)
		{
			coordinates[i] = 0;
		}
		//coordinates = {};
	}

	// Create a point from coordinates stored in a vector (must have correct length)
	Point(std::vector<PointScalarType>& predefinedCoordinates)
	{
		if (DIMENSION != predefinedCoordinates.size())
		{
			Point(this);
			return;
		}
		for (int i = 0; i < DIMENSION; ++i)
		{
			coordinates[i] = predefinedCoordinates[i];
		}
	}

	// Create a point from coordinates stored in an array.
	Point(PointScalarType predefinedCoordinates[DIMENSION])
	{
		for (int i = 0; i < DIMENSION; ++i)
		{
			coordinates[i] = predefinedCoordinates[i];
		}
	}

	// create a 2D point
	Point(int x, int y)
	{
		static_assert(DIMENSION == 2, "Template incorrect dimension for constructor");
		coordinates[0] = x;
		coordinates[1] = y;
	}

	// create a 3D point
	Point(int x, int y, int z)
	{
		static_assert(DIMENSION == 3, "Template incorrect dimension for constructor");
		coordinates[0] = x;
		coordinates[1] = y;
		coordinates[2] = z;
	}

	// delete this point
	~Point() 
	{

	}

	// return the specified coordinate
	PointScalarType& operator[] (int const i)
	{
		return coordinates[i];
	}

	// get a specified coordinate
	PointScalarType const operator[] (int const i) const
	{
		return coordinates[i];
	}

	// add a point's coordinates to an existing point.
	void operator+= (Point const& rhsPoint)
	{
		for (int i = 0; i < DIMENSION; ++i)
		{
			coordinates[i] += rhsPoint[i];
		}
	}

	// take a point's coordinates to an existing point.
	void operator-= (Point const& rhsPoint)
	{
		for (int i = 0; i < DIMENSION; ++i)
		{
			coordinates[i] -= rhsPoint[i];
		}
	}

	// add two points elementwise.
	friend Point operator+ (Point const& leftPoint, Point const& rightPoint)
	{
		Point output(leftPoint);

		output += rightPoint;
		return output;
	}

	// get difference of two points elementwise.
	friend Point operator- (Point const& leftPoint, Point const& rightPoint)
	{
		Point output(leftPoint);

		output -= rightPoint;
		return output;
	}

	bool operator== (Point const& otherPoint) const
	{
		for (int i = 0; i < DIMENSION; ++i)
		{
			if ((*this)[i] != otherPoint[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator!= (Point const& otherPoint) const
	{
		return !(this != otherPoint);
	}
};

typedef Point<2> Point2D;
typedef Point<3> Point3D;

