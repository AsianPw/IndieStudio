/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by j-f,
*/

#include "../inc/GenerateMap.hpp"

int	GenerateMap::getWidth(void)
{
	return width;
}

int	GenerateMap::getHeight(void)
{
	return height;
}

int	GenerateMap::getNbrwall(void)
{
	return nbr_wall;
}

std::vector<std::vector<char>>	GenerateMap::getMap(void)
{
	return BombermanMap;
}

GenerateMap::~GenerateMap()
{
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

void	GenerateMap::place_player(size_t nbrplayer)
{
	t_coord	place;
	size_t	index = 0;

	while (index < nbrplayer) {
		place.x = rand() % (width - 1);
		place.y = rand() % (height - 1);
		while (BombermanMap[place.x][place.y] == '*' ||
			BombermanMap[place.x][place.y] == 'P' ||
			BombermanMap[place.x][place.y] == 'A') {
			place.x = rand() % (width - 1);
			place.y = rand() % (height - 1);
		}
		BombermanMap[place.x][place.y] = 'P';
		index = index + 1;
	}
}

void	GenerateMap::place_ia(size_t nbria)
{
	t_coord	place;
	size_t	index = 0;

	while (index < nbria) {
		place.x = rand() % (width - 1);
		place.y = rand() % (height - 1);
		while (BombermanMap[place.x][place.y] == '*' ||
			BombermanMap[place.x][place.y] == 'P' ||
			BombermanMap[place.x][place.y] == 'A') {
			place.x = rand() % (width - 1);
			place.y = rand() % (height - 1);
		}
		BombermanMap[place.x][place.y] = 'A';
		index = index + 1;
	}
}

GenerateMap::GenerateMap(size_t nbrplayer, size_t nbria)
{
	InitMap();
	place_unbrokable_wall_width();
	place_unbrokable_wall_height();
	place_taget_wall();
	set_place_for_players();
	place_player(nbrplayer);
	place_ia(nbria);
}

