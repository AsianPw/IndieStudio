/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/

#ifndef BOMBERMAN_PREROLL_HPP
#define BOMBERMAN_PREROLL_HPP

#include <string>
#include <map>
#include "IScene.hpp"
#include "Position.hpp"

class Preroll : public IScene {
public:
	Preroll();
	~Preroll() override = default;
	std::map<std::string, Position> &getModels() override;
	void compute() override;
	void checkEvents(char event) override;
private:
	std::map<std::string, Position>	_models;
};

#endif //BOMBERMAN_PREROLL_HPP
