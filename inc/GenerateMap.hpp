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

typedef struct	s_coord
{
	int	x;
	int	y;
}		t_coord;

class	GenerateMap
{
	private:
		int	width = 29;
		int	height = 29;
		int	nbr_wall = (width * height) / 2;
		t_coord	player_place;
		t_coord	ia_place;
		std::vector<std::vector<char>> BombermanMap;

	public:
		~GenerateMap();
		GenerateMap();
		int	get_width();
		int	get_height();
		int	get_nbrwall();
		t_coord	get_player_place();
		t_coord	get_ia_place();
		std::vector<std::vector<char>>	getMap();
		void	InitMap();
		void	print_map();
		void	place_unbrokable_wall_width();
		void	place_unbrokable_wall_height();
		void	place_taget_wall();
		void	set_place_for_players();
		void	place_player();
		void	place_ia();
};

#endif //BOMBERMAN_GENERATEMAP_HPP
