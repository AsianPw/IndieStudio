/*
** EPITECH PROJECT, 2021
** cpp_indie_studio
** File description:
** Created by j-f,
*/

#ifndef CPP_INDIE_STUDIO_IPLAYER_HPP
#define CPP_INDIE_STUDIO_IPLAYER_HPP

#include <iostream>

class IPlayer {
	public:
	virtual ~IPlayer() = default;
<<<<<<< HEAD
	virtual void	IPlayer() = 0;
	virtual void	setPlayerOnMap(std::vector<std::vector<char>> &) = 0;
=======
	virtual void	setPlayeronMap(std::vector<std::vector<char>> &, int ) = 0;
	virtual void	setIaonMap(std::vector<std::vector<char>> &, int nbrIa) = 0;
>>>>>>> 6eca8f60930c71c3669d441151bda2c71b123a06
	virtual void	moveLeft(std::vector<std::vector<char>> &) = 0;
	virtual void	moveRight(std::vector<std::vector<char>> &) = 0;
	virtual void	moveUp(std::vector<std::vector<char>> &) = 0;
	virtual void	moveDown(std::vector<std::vector<char>> &) = 0;
	virtual void	letBomb(std::vector<std::vector<char>> &) = 0;
};

#endif //CPP_INDIE_STUDIO_IPLAYER_HPP
