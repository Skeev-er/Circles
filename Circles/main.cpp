#include <iostream>
#include "Framework.h"
#include <vector>
#include "Circle.cpp"

// Screen dimensions
int gScreenWidth{ 800 };
int gScreenHeight{ 600 };

// Delay to slow things down
int gTimeDelayMS{ 10 };

using namespace std;

int main()
{
	srand(time(0)); // Sets seed

	vector<Circle> CircleVector; // Make the vector
	CircleVector.push_back(Circle()); // Add the new circle to the back of the vector

	int maxSize = 175; // Maximum size for CircleVector

	while (UpdateFramework())
	{
		for (int i = 0; i < CircleVector.size(); i++)
		{
			CircleVector[i].Draw(); // Draws the circle at position [i] in the vector
			CircleVector[i].Update(); // Handles movement and wall collision
		}

		if (IsButtonPressed(EButton::eRight) && IsButtonPressed(EButton::eLeft) && CircleVector.size() < maxSize)
		{
			CircleVector.push_back(Circle()); // Add the new circle to the back of the vector
		}
	}
	return 0;
}

