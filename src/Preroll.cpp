/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/

#include "../inc/Preroll.hpp"
#include "../inc/GenerateMap.hpp"

Preroll::Preroll()
{
	_models.insert({"texture/assassin/akai_e_espiritu.obj", {0, 0}});
	_models.insert({"texture/bb8/bb8.obj", {200, 200}});
}

void	Preroll::compute()
{
}

void	Preroll::checkEvents(char event)
{
}

std::map<std::string, Position>	&Preroll::getModels()
{
	return _models;
}
