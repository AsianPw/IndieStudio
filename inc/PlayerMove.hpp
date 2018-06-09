/*
** EPITECH PROJECT, 2021
** cpp_indie_studio
** File description:
** Created by j-f,
*/

#ifndef CPP_INDIE_STUDIO_PLAYERMOVE_HPP
#define CPP_INDIE_STUDIO_PLAYERMOVE_HPP

#include <iostream>
#include <vector>
#include "IPlayer.hpp"
#include "Position.hpp"

class PlayerMove : public IPlayer {
	private:
		char				_name;
		int				life;
		Position			pos;
		bool				explosion_dir;
		std::vector<std::vector<char>>	_map;

	public:
		~PlayerMove();
		PlayerMove(char name, std::vector<std::vector<char>>	&map);
		void	moveLeft();
		void	moveRight();
		void	moveUp();
		void	moveDown();
		void	letBomb();
};

#endif //CPP_INDIE_STUDIO_PLAYERMOVE_HPP
