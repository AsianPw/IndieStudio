/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/

#include "../inc/Preroll.hpp"
#include "../inc/GenerateMap.hpp"
#include "../inc/Menu.hpp"
#include "../inc/keyCodes.hpp"

Preroll::Preroll(bool verbose) : _change(false), _verbose(verbose)
{
	_models.insert({"player", { {0, -150}, {0, 180}, "texture/characters/ziggs.png", "texture/characters/ziggs.md3", irr::scene::EMAT_STAND, false }});
	_guis.insert({"pass", { {370, 500}, {0, 180}, "", "Press M to pass", irr::scene::EMAT_STAND, false }});
}

void	Preroll::compute(std::pair<int, std::string> &keyCode)
{
	_models["player"].animationType = irr::scene::EMAT_RUN;
	_models["player"].pos.y++;
	if (_models["player"].pos.y > 150) {
		_change = true;
	}
}

std::vector<std::vector<char>>	&Preroll::getMap()
{
	return _map;
}

void	Preroll::checkEvents(std::pair<int, std::string> &keyCode)
{
}

std::map<std::string, Data> &Preroll::getGuis()
{
	return _guis;
}

std::map<std::string, Data>	&Preroll::getModels()
{
	return _models;
}

IScene*	Preroll::newScene()
{
	return !_change ? nullptr : new Menu(_verbose);
}