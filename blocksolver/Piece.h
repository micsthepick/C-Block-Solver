#pragma once

#include <vector>
#include "Point.h"
template<int DIMENSION>
class Piece
{
private:

	// unique identifier for this piece
	int id;

	// stored points
	std::vector<Point<DIMENSION>> points;

	// piece size
	Point<DIMENSION> extremes;

public:

	Piece()
	{
		id = 0;

		points = new std::vector<Point<DIMENSION>>();

		extremes = new Point<DIMENSION>();
	}

	//Piece(string fileName) // import piece from file?
	// import piece from part of a pieces file?

	// Defines a piece with a vector (list) of points.
	Piece(std::vector<Point<DIMENSION>> predefinedPoints, int* predefinedId = nullptr)
	{
		points = new std::vector<Point<DIMENSION>>(predefinedPoints);
		id = predefinedId;
	}

	~Piece();
};

typedef Piece<2> Piece2D;
typedef Piece<3> Piece3D;