/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by j-f,
*/

#include "../inc/GenerateMap.hpp"

GenerateMap::GenerateMap(size_t nbrplayer, size_t nbria)
{
	InitMap();
	place_unbreakable_wall_width();
	place_unbreakable_wall_height();
	place_target_wall();
	set_place_for_players();
	setPlayeronMap(nbria);
	setIaonMap(nbrplayer);
}

GenerateMap::~GenerateMap()
{
}

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

void	GenerateMap::print_map(void)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout<<BombermanMap[i][j];
		}
	}
}

void	GenerateMap::InitMap(void)
{
	BombermanMap.resize(height, std::vector<char>(width));
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			BombermanMap[i][j] = '*';
		}
	}
}

void	GenerateMap::place_unbreakable_wall_height(void)
{
	for (int i = 0; i < height; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j < width - 1; j++) {
				BombermanMap[i][j] = ' ';
			}
		}
	}
}

void	GenerateMap::place_unbreakable_wall_width(void)
{
	for (int i = 1; i < height - 2 ; i++) {
		for (int j = 0; j < width - 1; j++) {
			if (j % 2 != 0 ) {
				BombermanMap[i][j] = ' ';
			}
		}
	}
}

void	GenerateMap::place_target_wall(void)
{
	int	i, j;

	srand(time(NULL));
	for (int z = 0; z <= nbr_wall; z++) {
		i = rand() % (height - 1);
		j = rand() % (width - 1);
		while (BombermanMap[i][j] && BombermanMap[i][j] != ' ') {
			i = rand() % (height - 1);
			j = rand() % (width - 1);
		}
		BombermanMap[i][j] = '#';
	}
}

void	GenerateMap::set_place_for_players(void)
{
	int	x = 0;
	int	y = 0;

	while (x != height)
	{
		y = 0;
		while (y != width)
		{
			if (BombermanMap[x][y] >= 65 && BombermanMap[x][y] <= 68)
			{
				if (BombermanMap[x - 1][y] != '*')
					BombermanMap[x - 1][y] = ' ';
				if (BombermanMap[x + 1][y] != '*')
					BombermanMap[x + 1][y] = ' ';
				if (BombermanMap[x][y - 1] != '*')
					BombermanMap[x][y - 1] = ' ';
				if (BombermanMap[x][y + 1] != '*')
					BombermanMap[x][y + 1] = ' ';
			}
			y++;
		}
		x++;
	}
}

void	GenerateMap::setPlayeronMap(int nbrPlayer)
{
	if (nbrPlayer >= 1)
		BombermanMap[1][1] = 'A';
	if (nbrPlayer >= 2)
		BombermanMap[1][width - 2] = 'B';
	if (nbrPlayer >= 3)
		BombermanMap[height - 2][1] = 'C';
	if (nbrPlayer >= 4)
		BombermanMap[height - 2][width - 2] = 'D';
}

void	GenerateMap::setIaonMap(int nbrIa)
{
	if (nbrIa >= 1)
		BombermanMap[1][width - 2] = 'B';
	if (nbrIa >= 2)
		BombermanMap[height - 2][1] = 'C';
	if (nbrIa == 3)
		BombermanMap[height - 2][width - 2] = 'D';
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
