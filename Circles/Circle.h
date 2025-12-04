#pragma once
#include "Framework.h"

class Circle
{
private:
	int red; // Initialising variables
	int green;
	int blue;
	int alpha;
	int radius; 
	int diameter;
	int x;
	int y;
	int xDir;
	int yDir;

public:

	void inline Draw(); // Functions acting on Circle
	void inline Update();

	inline Circle();
};

