/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Ia.hpp
*/
#ifndef BOMBERMAN_IA_HPP
#define BOMBERMAN_IA_HPP

class Ia : public IPlayer{
public:

private:
	char	name;
	int	life;
	std::vector<std::vector<char>>	map;
};

#endif //BOMBERMAN_IA_HPP
