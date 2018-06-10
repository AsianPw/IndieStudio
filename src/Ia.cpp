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
		dir = 2;
	else if (pos.x - 1 >= 49 && pos.x - 1 <= 51)
		dir = 0;
	else if (pos.y + 1 >= 49 && pos.y + 1 <= 51)
		dir = 1;
	else if (pos.y - 1 >= 49 && pos.y - 1 <= 51)
		dir = 3;
	else
		dir = 5;
};

void	Ia::start()
{
	int	x;

	while(life >= 0)
	{
		x = rand() % 4;
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
	_map[pos.x][pos.y] = '1';
}