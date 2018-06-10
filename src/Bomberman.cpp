/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/

#include "../inc/Bomberman.hpp"
#include "../inc/keyCodes.hpp"
#include "../inc/PlayerMove.hpp"
#include "../inc/Ia.hpp"

Bomberman::Bomberman(bool _verbose, size_t nbPlayer, size_t nbIa) : _verbose(_verbose), _cameraPos({320.0f, 175.0f, 150.0f}), _cameraRot({ 120.0f, 0.0f, 150.0f}), _map(nbPlayer, nbIa)
{
	player.x = 130;
	player.y = 10;
	ia.x = 130;
	ia.y = 130;
	_models.insert({"player", { {player.x, player.y}, {0, 0}, "texture/characters/ziggs.png", "texture/characters/ziggs.md3", irr::scene::EMAT_STAND, false }});
	_models.insert({"player2", { {ia.x, ia.y}, {0, 0}, "texture/characters/ziggs_general.png", "texture/characters/ziggs_general.md3", irr::scene::EMAT_STAND, false }});
}

std::map<std::string, Data> &Bomberman::getModels()
{
	return _models;
}

std::map<std::string, Data> &Bomberman::getGuis()
{
	return _guis;
}

std::vector<std::vector<char>> &Bomberman::getMap()
{
	return _map.getMap();
}

Tools::vector3d &Bomberman::getCameraPos()
{
	return _cameraPos;
}

Tools::vector3d &Bomberman::getCameraRot()
{
	return _cameraRot;
}

void Bomberman::compute(std::pair<int, std::string> &events)
{
	Ia	B('B', _map.getMap());
	Ia	C('C', _map.getMap());
	Ia	D('D', _map.getMap());
	B.start();
	C.start();
	D.start();
}

IScene *Bomberman::newScene()
{
	return nullptr;
}

void Bomberman::checkEvents(std::pair<int, std::string> &events)
{

	PlayerMove	p('A', _map.getMap());

	if (events.first == KeyCode::KEY_Z) {
		_cameraPos.x += 1.f;
		std::cerr << _cameraPos.z << std::endl;
	}
	if (events.first == KeyCode::KEY_SPACE) {
		std::cerr << "Space button to use a bomb" << std::endl;
		p.putBomb();
		_map.print_map();
	}
	if (events.first == KeyCode::KEY_LEFT) {
		std::cerr << "Left direction" << std::endl;
		p.moveLeft();
		_models["player"].pos.y = _models["player"].pos.y - 10;
		_map.print_map();
	}
	if (events.first == KeyCode::KEY_UP) {
		std::cerr << "Up direction" << std::endl;
		p.moveUp();
		_map.print_map();
	}
	if (events.first == KeyCode::KEY_RIGHT) {
		std::cerr << "Right direction" << std::endl;
		p.moveRight();
		_models["player"].pos.y = _models["player"].pos.y + 10;
		_map.print_map();
	}
	if (events.first == KeyCode::KEY_DOWN) {
		std::cerr << "Down direction" << std::endl;
		p.moveDown();
		_map.print_map();
	}
}