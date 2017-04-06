#pragma once
#include <iostream>
class Engine
{
private:
	bool ** board[2];
	int width, height;
	unsigned long int steps;
	bool state;
	bool CheckCell(int x,int y);
public:
	Engine(int w, int h);
	Engine();
	~Engine();
	void Step();
	bool ** GetBoard() const;
	void SetCell(int x, int y);
	void ClearCell(int x, int y);
	void Display();
};

