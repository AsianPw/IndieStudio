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
	int	i = 0;
	int	j;

	while (i < 15) {
		j = 0;
		while (j < 15) {
			if (map[i][j] == _name) {
				pos.x = i;
				pos.y = j;
			}
			j++;
		}
		i++;
	}
}

PlayerMove::~PlayerMove()
{
}

void	PlayerMove::letBomb(void)
{
	_map[pos.x][pos.y] = 'o';
}

void	PlayerMove::moveRight(void)
{
	if (_map[pos.x + 1][pos.y] == ' ' && _map[pos.x + 1][pos.y]) {
		_map[pos.x + 1][pos.y] = _name;
		_map[pos.x][pos.y] = ' ';
		explosion_dir = true;
	}
	else
		return;
}

void	PlayerMove::moveLeft(void)
{
	if (_map[pos.x - 1][pos.y] == ' ' && _map[pos.x - 1][pos.y]) {
		_map[pos.x + 1][pos.y] = _name;
		_map[pos.x][pos.y] = ' ';
		explosion_dir = true;
	}
	else
		return;
}

void	PlayerMove::moveUp(void)
{
	if (_map[pos.x][pos.y - 1] == ' ' && _map[pos.x][pos.y - 1]) {
		_map[pos.x][pos.y - 1] = _name;
		_map[pos.x][pos.y] = ' ';
		explosion_dir = false;
	}
	else
		return;
}

void	PlayerMove::moveDown(void)
{
	if (_map[pos.x - 1][pos.y] == ' ' && _map[pos.x - 1][pos.y]) {
		_map[pos.x + 1][pos.y] = _name;
		_map[pos.x][pos.y] = ' ';
		explosion_dir = false;
	}
	else
		return;
}