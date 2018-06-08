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

std::vector<std::vector<char>>	&GenerateMap::getMap(void)
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
			//if (j == width - 1)
			//	BombermanMap[i][j] = '\n';
		}
	}
}

void	GenerateMap::place_unbreakable_wall_width(void)
{
	for (int i = 0; i < width; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j < height - 1; j++) {
				BombermanMap[i][j] = ' ';
			//	if (j == width - 1)
			//		BombermanMap[i][j] = '\n';
			}
		}
	}
}

void	GenerateMap::place_unbreakable_wall_height(void)
{
	for (int i = 1; i < width - 2 ; i++) {
		for (int j = 0; j < height - 1; j++) {
			if (j % 2 != 0 ) {
				BombermanMap[i][j] = ' ';
			}
			//.BombermanMap[i][height - 3] = ' ';
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
	//BombermanMap[2][2] = ' ';
	//BombermanMap[width - 2][height - 3] = ' ';
	//BombermanMap[width - 2][height - 4] = ' ';
	//BombermanMap[height - 4][width - 3] = ' ';
	//BombermanMap[width - 3][height - 3] = ' ';
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
		BombermanMap[1][1] = 'P';
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
	place_unbreakable_wall_width();
	place_unbreakable_wall_height();
	place_taget_wall();
	set_place_for_players();
	place_player(nbrplayer);
	place_ia(nbria);
}

/*int	main()
{
	int x = 10;
	int y = x;
	int z = 70;

	GenerateMap	toto(2, 3);
	toto.print_map();
	video::E_DRIVER_TYPE	driverType;
	MyEventReceiver		receiver;
	IrrlichtDevice *device = createDevice(driverType,
		core::dimension2d<u32>(1200, 720), 16, false, false, false, &receiver);
	if (driverType==video::EDT_COUNT)
		return 84;
	if (device == 0)
		return 84;
	video::IVideoDriver *driver = device->getVideoDriver();
	scene::ISceneManager *smgr = device->getSceneManager();
	scene::ISceneNode *n = smgr->addCubeSceneNode();
	if (n) {
		n->setPosition(core::vector3df(x, y, z));
		n->setMaterialTexture(0, driver->getTexture("../breakable_wall.jpg"));
		n->setMaterialFlag(video::EMF_LIGHTING, false);
	}
	smgr->addCameraSceneNode();
	device->getCursorControl()->setVisible(false);
	// while the window is open
	while(device->run()) {
		driver->beginScene(true, true, video::SColor(255,113,113,133));
		smgr->drawAll(); // draw the 3d scene
		driver->endScene();
	}
	device->drop();
	return 0;
}*/
