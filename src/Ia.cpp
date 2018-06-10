/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Ia.cpp
*/

#include "../inc/Ia.hpp"

Ia::Ia(char name, std::vector<std::vector<char>> &map)
	: _name(name), _map(map)
{
}

Ia::~Ia()
{
}

void	Ia::checkDir()
{
	pos = getPlayerPlace();
	if (pos.x + 1 >= 49 && pos.x + 1 <= 51)
		opp = 2;
	else if (pos.x - 1 >= 49 && pos.x - 1 <= 51)
		opp = 0;
	else if (pos.y + 1 >= 49 && pos.y + 1 <= 51)
		opp = 1;
	else if (pos.y - 1 >= 49 && pos.y - 1 <= 51)
		opp = 3;
	else
		opp = 5;
};

void	Ia::move(int x)
{
	if (x == 0)
		moveUp();
	else if (x == 1)
		moveRight();
	else if (x == 2)
		moveDown();
	else
		moveLeft();
	dir = x;
}

void	Ia::canMove()
{
	pos = getPlayerPlace();
	if (dir == 0) {
		if (_map[pos.x + 1][pos.y] != ' ')
			dir = (rand() * _name) % 4;
	}
	else if (dir == 1) {
		if (_map[pos.x][pos.y + 1] != ' ')
			dir = (rand() * _name) % 4;
	}
	else if (dir == 2) {
		if (_map[pos.x - 1][pos.y] != ' ')
			dir = (rand() * _name) % 4;
	}
	else if (dir == 3) {
		if (_map[pos.x][pos.y - 1] != ' ')
			dir = (rand() * _name) % 4;
	}
}

void	Ia::start()
{
	int	x;

	if (dir < 0 || dir > 3)
		dir = (rand() * _name) % 4;
	srand(time(NULL));
	checkDir();
	x = (rand() * _name) % 4;
	if (opp != 5) {
		while (x == opp)
			x = (rand() * _name) % 4;
		move(x);
	}
	else
	{
		canMove();
		move(dir);
	}
}

Position	Ia::getPlayerPlace()
{
	int	i = 0;
	int	j;

	while (i < 15) {
		j = 0;
		while (j < 15) {
			if (_map[i][j] == _name) {
				pos.x = i;
				pos.y = j;
				return pos;
			}
			j++;
		}
		i++;
	}
}

void	Ia::moveLeft()
{
	pos = getPlayerPlace();
	if (_map[pos.x][pos.y - 1] && _map[pos.x][pos.y - 1] == ' ') {
		_map[pos.x][pos.y - 1] = _name;
		_map[pos.x][pos.y] = ' ';
		pos.x = pos.x - 1;
	}
}

void	Ia::moveRight()
{
	pos = getPlayerPlace();
	if (_map[pos.x][pos.y + 1] && _map[pos.x][pos.y + 1] == ' ') {
		_map[pos.x][pos.y + 1] = _name;
		_map[pos.x][pos.y] = ' ';
		pos.x = pos.x + 1;
	}
}

void	Ia::moveUp()
{
	pos = getPlayerPlace();
	if (_map[pos.x - 1][pos.y] && _map[pos.x - 1][pos.y] == ' ') {
		_map[pos.x - 1][pos.y] = _name;
		_map[pos.x][pos.y] = ' ';
		pos.y = pos.y - 1;
	}
}

void	Ia::moveDown()
{
	pos = getPlayerPlace();
	if (_map[pos.x + 1][pos.y] && _map[pos.x + 1][pos.y] == ' ') {
		_map[pos.x + 1][pos.y] = _name;
		_map[pos.x][pos.y] = ' ';
		pos.y = pos.y + 1;
	}
}

void	Ia::putBomb()
{
	pos = getPlayerPlace();
	if ((dir == 1) && _map[pos.x][pos.y + 1]  && _map[pos.x][pos.y + 1] == ' ') {
		_map[pos.x][pos.y + 1] = '1';
	}
	else if (dir == 3 && _map[pos.x][pos.y - 1] && _map[pos.x][pos.y - 1] == ' ') {
		_map[pos.x][pos.y - 1] = '1';
	}
	else if ((dir == 0) && _map[pos.x - 1][pos.y] && _map[pos.x - 1][pos.y] == ' ') {
		_map[pos.x - 1][pos.y] = '1';
	}
	else if ((dir == 2) && _map[pos.x + 1][pos.y] && _map[pos.x + 1][pos.y] == ' ') {
		_map[pos.x + 1][pos.y] = '1';
	}
}