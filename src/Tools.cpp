/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/

#include <iostream>
#include "../inc/Tools.hpp"

irr::core::vector3df Tools::posToVec(Position &position)
{
	return irr::core::vector3df(position.x, .0f, position.y);
}

bool Tools::cmpPos(Position &p1, Position &p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}

void Tools::displayVerbose(bool verbose, std::string const &message, bool endl)
{
	if (!verbose)
		return;
	std::cerr << message;
	if (endl) {
		std::cerr << std::endl;
	}
}