/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#include <iostream>
#include "../inc/Menu.hpp"
#include "../inc/Tools.hpp"
#include "../inc/keyCodes.hpp"
#include "../inc/vector3d.hpp"
#include "../inc/PlayerMove.hpp"
#include "../inc/Bomberman.hpp"

Menu::Menu(bool verbose)
	: _change(false), _verbose(verbose), _scene(nullptr), _cameraPos({195.0f, 150.0f, 71.0f}), _cameraRot({ 50.0f, 0.0f, 75.0f}), _sens(false), _map(1, 3)
{
	_models.insert({"player", { {20, 20}, {0, 180}, "texture/characters/ziggs.png", "texture/characters/ziggs.md3", irr::scene::EMAT_STAND, false }});
	_models.insert({"player2", { {20, 220}, {0, 0}, "texture/characters/ziggs_general.png", "texture/characters/ziggs_general.md3", irr::scene::EMAT_STAND, false }});
	_guis.insert({"singleplayer", { {420, 200}, {0, 180}, "", "SinglePlayer", irr::scene::EMAT_STAND, true }});
	_guis.insert({"Versus", { {470, 400}, {0, 180}, "", "1 vs. 1", irr::scene::EMAT_STAND, true }});
	_guis.insert({"Settings", { {460, 600}, {0, 180}, "", "Settings", irr::scene::EMAT_STAND, true }});
	_guis.insert({"backToMenu", { {0, 0}, {0, 0}, "", "M: Back To Menu", irr::scene::EMAT_STAND, false }});
	_guis.insert({"GoSettings", { {0, 40}, {0, 0}, "", "P: Go To Settings", irr::scene::EMAT_STAND, false }});
	_guis.insert({"Quit", { {0, 80}, {0, 0}, "", "Echap: Quit Game", irr::scene::EMAT_STAND, false }});
}

std::map<std::string, Data> &Menu::getModels()
{
	return _models;
}

//y => hauteur
void Menu::compute(std::pair<int, std::string> &keyCode)
{
	if (_sens) {
		_cameraPos.z += 1;
	} else {
		_cameraPos.z -= 1;
	}
	if (_cameraPos.z >= 150 || _cameraPos.z <= -150) {
		_sens = !_sens;
	}
}

IScene *Menu::newScene()
{
	return _scene;
}

void Menu::checkEvents(std::pair<int, std::string> &keyCode)
{
	if (keyCode.second == "singleplayer") {
		_scene = new Bomberman(_verbose, 1, 3);
	} else if (keyCode.second == "Versus") {
		_scene = new Bomberman(_verbose, 2, 0);
	}
}

std::map<std::string, Data> &Menu::getGuis()
{
	return _guis;
}

std::vector<std::vector<char>> &Menu::getMap()
{
	return _map.getMap();
}

Tools::vector3d	&Menu::getCameraPos()
{
	return _cameraPos;
}

Tools::vector3d	&Menu::getCameraRot()
{
	return _cameraRot;
}
