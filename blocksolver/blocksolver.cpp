#include <iostream>
#include <boost/timer/timer.hpp>
#include "Piece.h"

// TODO sketch out inputs/outputs
int apply3DTransform(int input, int transform)
{
	return input + transform; // TODO
}

int main()
{
	// Program timer
	boost::timer::cpu_timer timer;

	// should define grid and pieces externally
	const int DEPTH = 4;
	const int HEIGHT = 4;
	const int WIDTH = 4;


	// Stores pieces to solve
	//Piece3D pieces[12] = Piece3D [];
	// this will have to change, as there is not always 12 pieces

	

    std::cout << "Finished definitions.\n";
	std::cout << "Time: " << timer.format();
	timer.start();

	std::cout << "Finished.\n";
	std::cout << "Time: " << timer.format();
}


// ideas: xml file for grid and pieces