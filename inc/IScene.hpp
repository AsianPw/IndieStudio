/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_ISCENE_HPP
#define BOMBERMAN_ISCENE_HPP

#include <map>
#include "Position.hpp"

class IScene {
public:
	virtual ~IScene() = default;
	virtual std::map<std::string, Position>	&getModels() = 0;
	virtual void	compute() = 0;
	virtual void	checkEvents(char event) = 0;
};

#endif //BOMBERMAN_ISCENE_HPP
