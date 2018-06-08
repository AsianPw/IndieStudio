/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_ISCENE_HPP
#define BOMBERMAN_ISCENE_HPP

#include <map>
#include "Data.hpp"

class IScene {
public:
	virtual ~IScene() = default;
	virtual std::map<std::string, Data>	&getModels() = 0;
	virtual std::map<std::string, Data>	&getGuis() = 0;
	virtual void	compute(std::pair<int, std::string> &) = 0;
	virtual IScene	*newScene() = 0;
	virtual void	checkEvents(std::pair<int, std::string> &) = 0;
};

#endif //BOMBERMAN_ISCENE_HPP
