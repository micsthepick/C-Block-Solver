#pragma once

#include <vector>
#include "Point.h"

template<int DIMENSION> class Piece
{
private:

	typedef Point<DIMENSION> PointLikeThis;

	// unique identifier for this piece
	int id;

	// stored points
	std::vector<PointLikeThis> points;

	// piece size
	PointLikeThis extremes;

public:
	// create a piece with no points, and an id of 0
	Piece()
	{
		id = 0;

		points = std::vector<PointLikeThis>();

		extremes = PointLikeThis();
	}

	//Piece(string fileName) // import piece from file?
	// import piece from part of a pieces file?

	// Defines a piece with a vector (list) of points. Points should have non-negative integer coordinates
	Piece(std::vector<PointLikeThis> predefinedPoints, int* predefinedId = nullptr)
	{
		points = new std::vector<PointLikeThis>(predefinedPoints);
		id = predefinedId;
		Point<DIMENSION> currentPoint;
		for (typename std::vector<PointLikeThis>::iterator point = points.begin(); point != points.end(); ++point)
		{
			currentPoint = *point;
			extremes = PointLikeThis();
			for (int i = 0; i < DIMENSION; ++i)
			{
				if (currentPoint[i] > extremes[i])
				{
					extremes[i] = currentPoint[i];
				}
			}
		}
	}

	// Add a point to a piece.
	void addPoint(PointLikeThis point)
	{
		for (int i = 0; i < DIMENSION; ++i)
		{
			if (point[i] > extremes[i])
			{
				extremes[i] = point[i];
			}
		}
		this->points.push_back(point);
	}

	bool contains(PointLikeThis pointToCheck)
	{
		PointLikeThis currentPoint;
		for (typename std::vector<PointLikeThis>::iterator point = points.begin(); point != points.end(); ++point)
		{
			currentPoint = *point;
			if (currentPoint == pointToCheck)
			{
				return true;
			}
		}
		return false;
	}

	// Delete a piece (nothing happens here since no new memory is allocated).
	~Piece() {};

	// Transform a piece by inverting and swapping specific axes,
	// swaps should be a vector containing numbers 0, ..., DIMENSION-1.
	Piece pieceFromAxisTransform(std::vector<bool> reflections, std::vector<int> swaps)
	{
		Piece out = Piece();
		PointLikeThis currentPoint;
		for (typename std::vector<PointLikeThis>::iterator point = points.begin(); point != points.end(); ++point)
		{
			currentPoint = *point;
			PointLikeThis newPoint = PointLikeThis();
			for (int i = 0; i < DIMENSION; ++i)
			{
				if (reflections[swaps[i]])
				{
					newPoint[i] = extremes[swaps[i]] - currentPoint[swaps[i]];
				}
				else
				{
					newPoint[i] = currentPoint[swaps[i]];
				}
			}
			out.addPoint(newPoint);
		}
		return out;
	}
};

typedef Piece<2> Piece2D;
typedef Piece<3> Piece3D;
