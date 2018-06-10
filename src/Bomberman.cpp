/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#include "../inc/Bomberman.hpp"
#include "../inc/keyCodes.hpp"
#include "../inc/PlayerMove.hpp"

Bomberman::Bomberman(bool _verbose, size_t nbPlayer, size_t nbIa) : _verbose(_verbose), _cameraPos({195.0f, 150.0f, 75.8f}), _cameraRot({ 50.0f, 0.0f, 75.0f}), _map(nbPlayer, nbIa)
{
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
}

IScene *Bomberman::newScene()
{
	return nullptr;
}

void Bomberman::checkEvents(std::pair<int, std::string> &events)
{
	PlayerMove	p('A', _map.getMap());
	if (events.first == KeyCode::KEY_SPACE) {
		std::cerr << "Space button to use a bomb" << std::endl;
	}
	if (events.first == KeyCode::KEY_LEFT) {
		std::cerr << "Left direction" << std::endl;
		p.moveLeft();
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
		_map.print_map();
	}
	if (events.first == KeyCode::KEY_DOWN) {
		std::cerr << "Down direction" << std::endl;
		p.moveDown();
		_map.print_map();
	}
}