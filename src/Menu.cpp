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

Menu::Menu(bool verbose) : _change(false), _verbose(verbose), _scene(nullptr)
{
	_models.insert({"player", { {0, -150}, {0, 180}, "texture/characters/ziggs.png", "texture/characters/ziggs.md3", irr::scene::EMAT_STAND, false }});
	_models.insert({"player2", { {0, -200}, {0, 180}, "texture/characters/ziggs_general.png", "texture/characters/ziggs_general.md3", irr::scene::EMAT_STAND, false }});
	_guis.insert({"singleplayer", { {420, 200}, {0, 180}, "", "SinglePlayer", irr::scene::EMAT_STAND, true }});
	_guis.insert({"Versus", { {470, 400}, {0, 180}, "", "1 vs. 1", irr::scene::EMAT_STAND, true }});
}

std::map<std::string, Data> &Menu::getModels()
{
	return _models;
}

void Menu::compute(std::pair<int, std::string> &keyCode)
{
	_models["player"].pos.y++;
	_models["player2"].pos.y++;
	if (_models["player"].pos.y > 200) {
		_models["player"].pos.y = -150;
	}
	if (_models["player2"].pos.y > 150) {
		_models["player2"].pos.y = -200;
	}
}

IScene *Menu::newScene()
{
	return _scene;
}

void Menu::checkEvents(std::pair<int, std::string> &keyCode)
{
	if (keyCode.second == "singleplayer") {
		_scene = new Menu(_verbose); // change with the correct class
	} else if (keyCode.second == "Versus") {
		_scene = new Menu(_verbose); // change with the correct class
	}
}

std::map<std::string, Data> &Menu::getGuis()
{
	return _guis;
}
