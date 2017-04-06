#include "stdafx.h"
#include "Engine.h"

bool Engine::CheckCell(int x,int y)
{
	int neighbours = 0;
	int tempx = x - 1;
	if (tempx >= 0)
	{
		if (y - 1 >= 0)
			if (board[state][tempx][y-1])
				neighbours++;
		if (board[state][tempx][y])
			neighbours++;
		if (y + 1 < height)
			if (board[state][tempx][y+1])
				neighbours++;
	}
	tempx = x + 1;
	if (tempx < width)
	{
		if (y - 1 >= 0)
			if (board[state][tempx][y-1])
				neighbours++;
		if (board[state][tempx][y])
			neighbours++;
		if (y + 1 < height)
			if (board[state][tempx][y+1])
				neighbours++;
	}
	if (y - 1 >= 0)
		if (board[state][x][y - 1])
			neighbours++;
	if (y + 1 < height)
		if (board[state][x][y + 1])
			neighbours++;
	if (board[state][x][y])
	{
		if (neighbours == 2 || neighbours == 3)
			return true;
		else
			return false;
	}
	else
	{
		if (neighbours == 3)
			return true;
		else
			return false;
	}
}

Engine::Engine(int w, int h) : width(w), height(h)
{
	state = 0;
	board[state] = new bool *[width];
	for (int i = 0; i < width; i++)
	{
		board[state][i] = new bool[height];
		for (int j = 0; j < height; j++)
			board[state][i][j] = false;
	}
	state = 1;
	board[state] = new bool *[width];
	for (int i = 0; i < width; i++)
	{
		board[state][i] = new bool[height];
		for (int j = 0; j < height; j++)
			board[state][i][j] = false;
	}
	state = 0;
	steps = 0;
}

Engine::Engine()
{
	state = 0;
	board[state] = new bool *[2];
	for (int i = 0; i < 2; i++)
	{
		board[state][i] = new bool[2];
		for (int j = 0; j < 2; j++)
			board[state][i][j] = false;
	}
	state = 1;
	board[state] = new bool *[2];
	for (int i = 0; i < 2; i++)
	{
		board[state][i] = new bool[2];
		for (int j = 0; j < 2; j++)
			board[state][i][j] = false;
	}
	state = 0;
	steps = 0;
}


Engine::~Engine()
{
	for (int i = 0; i < height; i++)
	{
		delete [] board[0][i];
		delete[] board[1][i];
	}
	delete[] board;
}

void Engine::Step()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			board[!state][i][j] = CheckCell(i, j);
		}
	}
	state = !state;
	steps++;
}

bool ** Engine::GetBoard() const
{
	return board[state];
}

void Engine::SetCell(int x, int y)
{
	if(x >= 0 && x < width && y >= 0 && y < height)
		board[state][x][y] = true;
}

void Engine::ClearCell(int x, int y)
{
	board[state][x][y] = false;
}

void Engine::Display()
{
	using namespace std;
	cout << "+";
	for (int i = 0; i < width; i++)
		cout << "-";
	cout << "+\n";
	for (int i = 0; i < width; i++)
	{
		cout << "|";
		for (int j = 0; j < height; j++)
			if (board[state][i][j])
				cout << "O";
			else
				cout << " ";
		cout << "|\n";
	}
	cout << "+";
	for (int i = 0; i < width; i++)
		cout << "-";
	cout << "+\n";
}
