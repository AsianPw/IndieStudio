/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by j-f,
*/

#include "GenerateMap.hpp"

int	GenerateMap::get_width(void)
{
	return width;
}

int	GenerateMap::get_height(void)
{
	return height;
}

int	GenerateMap::get_nbrwall(void)
{
	return nbr_wall;
}

std::vector<std::vector<char>>	GenerateMap::getMap(void)
{
	return BombermanMap;
}

GenerateMap::~GenerateMap()
{
	std::cout<<"Map destroyed"<<std::endl;
}

t_coord	GenerateMap::get_ia_place()
{
	return ia_place;
}

t_coord	GenerateMap::get_player_place()
{
	return player_place;
}

void	GenerateMap::print_map(void)
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			std::cout<<BombermanMap[i][j];
		}
	}
}

void	GenerateMap::InitMap(void)
{
	BombermanMap.resize(height, std::vector<char>(width));
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			BombermanMap[i][j] = '*';
			if (j == width - 1)
				BombermanMap[i][j] = '\n';
		}
	}
}

void	GenerateMap::place_unbrokable_wall_width(void)
{
	for (int i = 0; i < width; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j < height - 2; j++) {
				BombermanMap[i][j] = ' ';
				if (j == width - 1)
					BombermanMap[i][j] = '\n';
			}
		}
	}
}

void	GenerateMap::place_unbrokable_wall_height(void)
{
	for (int i = 1; i < width - 2 ; i++) {
		for (int j = 0; j < height - 2; j++) {
			if (j % 2 != 0 ) {
				BombermanMap[i][j] = ' ';
			}
			BombermanMap[i][height - 3] = ' ';
		}
	}
}

void	GenerateMap::place_taget_wall(void)
{
	int	i, j;

	srand(time(NULL));
	for (int z = 0; z <= nbr_wall; z++) {
		i = rand() % (width - 1);
		j = rand() % (height - 1);
		while (BombermanMap[i][j] && BombermanMap[i][j] != ' ') {
			i = rand() % (width - 1);
			j = rand() % (height - 1);
		}
		BombermanMap[i][j] = '#';
	}
}

void	GenerateMap::set_place_for_players(void)
{
	BombermanMap[1][1] = ' ';
	BombermanMap[1][2] = ' ';
	BombermanMap[2][1] = ' ';
	BombermanMap[2][2] = ' ';
	BombermanMap[width - 2][height - 3] = ' ';
	BombermanMap[width - 2][height - 4] = ' ';
	BombermanMap[height - 4][width - 3] = ' ';
	BombermanMap[width - 3][height - 3] = ' ';
}

void	GenerateMap::place_player(void)
{
	player_place.x = 1;
	player_place.y = 1;
	BombermanMap[player_place.x][player_place.y] = 'P';
}

void	GenerateMap::place_ia(void)
{
	ia_place.x = width - 2;
	ia_place.y = height - 3;
	BombermanMap[ia_place.x][ia_place.y] = 'I';
}

GenerateMap::GenerateMap(void)
{
	InitMap();
	place_unbrokable_wall_width();
	place_unbrokable_wall_height();
	place_taget_wall();
	set_place_for_players();
	place_player();
	place_ia();
}

/*int	main(void)
{
	GenerateMap	map;

	map.print_map();
}*/