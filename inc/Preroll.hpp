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

class Preroll : public IScene {
public:
	explicit Preroll(bool);
	~Preroll() override = default;
	std::map<std::string, Data> &getModels() override;
	void compute(std::pair<int, std::string> &) override;
	IScene	*newScene() override;
	void checkEvents(std::pair<int, std::string> &) override;
	std::map<std::string, Data> &getGuis() override;
	std::vector<std::vector<char>> &getMap() override;

private:
	std::map<std::string, Data>	_models;
	std::map<std::string, Data>	_guis;
	std::vector<std::vector<char>>	_map;
	bool	_change;
	bool	_verbose;
};

#endif //BOMBERMAN_PREROLL_HPP
