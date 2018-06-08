/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by j-f,
*/
#ifndef BOMBERMAN_GENERATEMAP_HPP
#define BOMBERMAN_GENERATEMAP_HPP

#include <iostream>
#include <string.h>
#include <vector>
#include <random>
#include <stdlib.h>
#include <irr/irrlicht.h>
#include <irr/driverChoice.h>
#include "../inc/EventReceiver.hpp"

using namespace irr;

typedef struct	s_coord
{
	int	x;
	int	y;
}		t_coord;

class	GenerateMap
{
	private:
		int	width = 31;
		int	height = 31;
		int	nbr_wall = (width * height) / 2;
		std::vector<std::vector<char>>	BombermanMap;

	public:
		~GenerateMap();
		GenerateMap(size_t , size_t);
		int	getWidth();
		int	getHeight();
		int	getNbrwall();
		t_coord	getPlayerPlace();
		t_coord	getIaPlace();
		std::vector<std::vector<char>>	&getMap();
		void	InitMap();
		void	print_map();
		void	place_unbrokable_wall_width();
		void	place_unbrokable_wall_height();
		void	place_taget_wall();
		void	set_place_for_players();
		void	place_player(size_t);
		void	place_ia(size_t);
};

#endif //BOMBERMAN_GENERATEMAP_HPP
