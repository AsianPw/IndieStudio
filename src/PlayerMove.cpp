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
	std::cout<<bomb_dir<<std::endl;
	if (bomb_dir == RIGHT && _map[pos.x][pos.y + 1]  && _map[pos.x][pos.y + 1] == ' ') {
		_map[pos.x][pos.y + 1] = '1';
	}
	if (bomb_dir == LEFT && _map[pos.x][pos.y - 1] && _map[pos.x][pos.y - 1] == ' ') {
		_map[pos.x][pos.y - 1] = '1';
	}
	if (bomb_dir == UP && _map[pos.x - 1][pos.y] && _map[pos.x - 1][pos.y] == ' ') {
		_map[pos.x - 1][pos.y] = '1';
	}
	if (bomb_dir == DOWN && _map[pos.x + 1][pos.y] && _map[pos.x + 1][pos.y] == ' ') {
		_map[pos.x + 1][pos.y] = '1';
	}
}

void	PlayerMove::moveRight(void)
{
	bomb_dir = RIGHT;
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
	bomb_dir = LEFT;
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
	bomb_dir = UP;
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
	bomb_dir = DOWN;
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