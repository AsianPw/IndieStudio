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
#include "IScene.hpp"
#include "GenerateMap.hpp"
#include "Position.hpp"

typedef enum {NONE, LEFT, RIGHT, UP, DOWN} dir_use_bomb;

class PlayerMove : public IPlayer {
	private:
		char				_name;
		int				life;
		Position			pos;
		bool				ver_explosion = false;
		bool				hor_explosion = false;
		bool				locked = false;
		dir_use_bomb			bomb_dir = RIGHT;
		std::vector<std::vector<char>>	&_map;

	public:
		~PlayerMove();
		PlayerMove(char name, std::vector<std::vector<char>> &map);
		void		moveLeft();
		void		moveRight();
		void		moveUp();
		void		moveDown();
		void		putBomb();
		Position	getPlayerPlace();
		bool		getStatus();
};

#endif //CPP_INDIE_STUDIO_PLAYERMOVE_HPP
