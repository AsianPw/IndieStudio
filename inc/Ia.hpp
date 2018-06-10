/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Ia.hpp
*/
#ifndef BOMBERMAN_IA_HPP
#define BOMBERMAN_IA_HPP

#include "../inc/IPlayer.hpp"
#include <iostream>
#include <vector>

class Ia : public IPlayer{
public:
	void	moveLeft();
	void	moveRight();
	void	moveUp();
	void	moveDown();
	void	letBomb();

private:
	char	name;
	int	life;
	std::vector<std::vector<char>>	map;
};

#endif //BOMBERMAN_IA_HPP
