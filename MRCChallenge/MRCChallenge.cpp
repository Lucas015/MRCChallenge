// MRCChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class Rover {
public:

	static const int N = 1;
	static const int E = 2;
	static const int S = 3;
	static const int W = 4;

	int x = 5;
	int y = 5;
	int facing = N;

	Rover()
	{

	}
	void setPosition(int x, int y, int facing) {

		this->x = y;
		this->y = y;
		this->facing = facing;
	}
	void printPosition() {

		char dir = 'N';

		switch (facing) {

		case 1: dir = 'N';
			break;

		case 2: dir = 'E';
			break;

		case 3: dir = 'S';
			break;

		case 4: dir = 'W';
			break;

		Default: cout << "Enter any number between 1 and 4" << endl;
			break;
		}
		cout << x << " " << y << " " << dir << endl;

	}
	void process(string commands) {

		for (int i = 0; i < commands.length(); i++)
		{
			process(commands[i]);
		}
	}
private:

	void process(char command) {

		switch (command)
		{
		case 'L':
		case'l':
			turnLeft();
			break;
		case'R':
		case'r':
			turnRight();
			break;
		case 'M':
		case 'm':
			move();
			break;
		default: cout << command << " is not recognized, Please try again with L, R or M" << endl;
			break;
		}
	}
	void move() {

		if (facing == N && this->y <= y)
		{
			y++;
		}
		else if (facing == E && this->x <= x)
		{
			x++;
		}
		else if (facing == S && this->y <= y)
		{
			y--;
		}
		else if (facing == W && this->y <= y)
		{
			x--;
		}
	}
	void turnLeft() {

		if (N > (facing - 1))
		{
			facing = W;
		}
		else {
			facing = (facing - 1);
		}
	}
	void turnRight() {

		if (W < (facing + 1))
		{
			facing = N;
		}
		else {
			facing = (facing + 1);
		}
	}
};

int main()
{
	Rover rover;
	rover.setPosition(1, 2, Rover::E);
	rover.process("MMLMRMMRRMMML");
	rover.printPosition(); //Print 3 3 S
}


