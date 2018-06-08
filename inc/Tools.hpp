/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_TOOLS_HPP
#define BOMBERMAN_TOOLS_HPP

#include <string>
#include <irr/vector3d.h>
#include "Position.hpp"

namespace Tools {
	bool	cmpPos(Position &, Position &);
	irr::core::vector3df	posToVec(Position &);
	void	displayVebose(bool, std::string const &);
}

#endif //BOMBERMAN_TOOLS_HPP
