/*
** EPITECH PROJECT, 2021
** cpp_indie_studio
** File description:
** Created by j-f,
*/

#include "../inc/PlayerMove.hpp"

PlayerMove::PlayerMove(char name, std::vector<std::vector<char>> &map)
	: _name(name), _map(map)
{
}

PlayerMove::~PlayerMove()
{
}

void	PlayerMove::setBombDir(int x)
{
	bomb_dir = x;
}

int	PlayerMove::getBombDir()
{
	return (bomb_dir);
}

Position	PlayerMove::getPlayerPlace()
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

void	PlayerMove::putBomb()
{
	pos = getPlayerPlace();
	if (bomb_dir == 1 && _map[pos.x][pos.y + 1]  && _map[pos.x][pos.y + 1] == ' ') {
		_map[pos.x][pos.y + 1] = '1';
	}
	else if (bomb_dir == 3 && _map[pos.x][pos.y - 1] && _map[pos.x][pos.y - 1] == ' ') {
		_map[pos.x][pos.y - 1] = '1';
	}
	else if (bomb_dir == 0 && _map[pos.x - 1][pos.y] && _map[pos.x - 1][pos.y] == ' ') {
		_map[pos.x - 1][pos.y] = '1';
	}
	else if (bomb_dir == 2 && _map[pos.x + 1][pos.y] && _map[pos.x + 1][pos.y] == ' ') {
		_map[pos.x + 1][pos.y] = '1';
	}
}

void	PlayerMove::moveRight(void)
{
	bomb_dir = 1;
	pos = getPlayerPlace();
	if (_map[pos.x][pos.y + 1]  && _map[pos.x][pos.y + 1] == ' ') {
		_map[pos.x][pos.y + 1] = _name;
		_map[pos.x][pos.y] = ' ';
		pos.x = pos.x + 1;
		ver_explosion = true;
	}
	else {
		locked = true;
		return;
	}
}

void	PlayerMove::moveLeft(void)
{
	bomb_dir = 3;
	pos = getPlayerPlace();
	if (_map[pos.x][pos.y - 1] && _map[pos.x][pos.y - 1] == ' ') {
		_map[pos.x][pos.y - 1] = _name;
		_map[pos.x][pos.y] = ' ';
		pos.x = pos.x - 1;
		ver_explosion = true;
	}
	else {
		locked = true;
		return;
	}
}

void	PlayerMove::moveUp(void)
{
	bomb_dir = 0;
	pos = getPlayerPlace();
	if (_map[pos.x - 1][pos.y] && _map[pos.x - 1][pos.y] == ' ') {
		_map[pos.x - 1][pos.y] = _name;
		_map[pos.x][pos.y] = ' ';
		pos.y = pos.y - 1;
		hor_explosion = true;
	}
	else {
		locked = true;
		return;
	}
}

void	PlayerMove::moveDown(void)
{
	bomb_dir = 2;
	pos = getPlayerPlace();
	if (_map[pos.x + 1][pos.y] && _map[pos.x + 1][pos.y] == ' ') {
		_map[pos.x + 1][pos.y] = _name;
		_map[pos.x][pos.y] = ' ';
		pos.y = pos.y + 1;
		hor_explosion = true;
	}
	else {
		locked = true;
		return;
	}
}

bool PlayerMove::getStatus()
{
	return locked;
}