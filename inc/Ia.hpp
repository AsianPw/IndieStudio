/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Ia.hpp
*/
#ifndef BOMBERMAN_IA_HPP
#define BOMBERMAN_IA_HPP

#include <iostream>
#include <vector>
#include "IPlayer.hpp"
#include "Position.hpp"

class Ia : public IPlayer{
public:
	~Ia();
	Ia(char name, std::vector<std::vector<char>>	&map);
	void		moveLeft();
	void		moveRight();
	void		moveUp();
	void		moveDown();
	void		putBomb();
	void		start();
	Position	getPlayerPlace();
	void		checkDir();
	void		move(int);

private:
	char				_name;
	int				dir;
	int				life;
	Position			pos;
	std::vector<std::vector<char>>	&_map;
};

#endif //BOMBERMAN_IA_HPP
