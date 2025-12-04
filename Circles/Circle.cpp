#include "Circle.h"
#include <stdlib.h>

void Circle::Draw()
{
	ChangeColour(red, green, blue, alpha);
	DrawCircle(x, y, radius);
}

void Circle::Update()
{
	x += xDir; // Add direction (speed) to x and y
	y += yDir;

	if (x >= 800 - diameter) // Right wall
	{
		xDir = -xDir;
	}
	else if (x < 0) // Left wall
	{
		xDir = -xDir;
	}
	else if (y >= 600 - diameter) // Bottom wall
	{
		y -= 10; // Prevents circles getting stuck in the wall
		yDir = -yDir;
	}
	else if (y < 0) // Top wall
	{
		y += 10; // Prevents circles getting stuck in the wall
		yDir = -yDir;
	}
}

Circle::Circle()
{
	radius = 20 + rand() % 30; // Random size; // Initialising variables
	diameter = radius * 2;
	x = 40 + (rand() % (800 - diameter) - 40); // Random starting position (border of 40)
	y = 40 + (rand() % (600 - diameter) - 40);
	xDir = -6 + rand() % 12; // Random directions/speeds between -6 and +6
	yDir = -6 + rand() % 12;

	if (xDir == 0 && yDir == 0) // Ensure that no circles are completely stationary
	{
		xDir = 3; // Arbitrary numbers
		yDir = -4;
	}

	red = rand() % 255; // Colours
	green = rand() % 255;
	blue = rand() % 255;
	alpha = 100 + rand() % 155;
}

