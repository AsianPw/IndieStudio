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

void	PlayerMove::letBomb(void)
{
	_map[pos.x][pos.y] = 'o';
}

void	PlayerMove::moveRight(void)
{
	pos = getPlayerPlace();
	if (_map[pos.x][pos.y + 1]  && _map[pos.x][pos.y + 1] == ' ') {
		_map[pos.x][pos.y + 1] = _name;
		_map[pos.x][pos.y] = ' ';
		pos.x = pos.x + 1;
		explosion_dir = true;
	}
	else
		return;
}

void	PlayerMove::moveLeft(void)
{
	pos = getPlayerPlace();
	if (_map[pos.x][pos.y - 1] && _map[pos.x][pos.y - 1] == ' ') {
		_map[pos.x][pos.y - 1] = _name;
		_map[pos.x][pos.y] = ' ';
		pos.x = pos.x - 1;
		explosion_dir = true;
	}
	else
		return;
}

void	PlayerMove::moveUp(void)
{
	pos = getPlayerPlace();
	if (_map[pos.x - 1][pos.y] && _map[pos.x - 1][pos.y] == ' ') {
		_map[pos.x - 1][pos.y] = _name;
		_map[pos.x][pos.y] = ' ';
		pos.y = pos.y - 1;
		explosion_dir = false;
	}
}

void	PlayerMove::moveDown(void)
{
	pos = getPlayerPlace();
	if (_map[pos.x + 1][pos.y] && _map[pos.x + 1][pos.y] == ' ') {
		_map[pos.x + 1][pos.y] = _name;
		_map[pos.x][pos.y] = ' ';
		pos.y = pos.y + 1;
		explosion_dir = true;
	}
	else
		return;
}