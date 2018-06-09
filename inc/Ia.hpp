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
	void	moveLeft(std::vector<std::vector<char>> &);
	void	moveRight(std::vector<std::vector<char>> &);
	void	moveUp(std::vector<std::vector<char>> &);
	void	moveDown(std::vector<std::vector<char>> &);
	void	letBomb(std::vector<std::vector<char>> &);

private:
	char	name;
	int	life;
	std::vector<std::vector<char>>	map;
};

#endif //BOMBERMAN_IA_HPP
