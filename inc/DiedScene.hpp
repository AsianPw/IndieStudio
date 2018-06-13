/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_DIEDSCENE_HPP
#define BOMBERMAN_DIEDSCENE_HPP

#include "IScene.hpp"
#include "GenerateMap.hpp"

class DiedScene : public IScene {
public:
	DiedScene(bool);
	std::map<std::string, Data> &getModels() override;
	std::map<std::string, Data> &getGuis() override;
	std::vector<std::vector<char>> &getMap() override;
	Tools::vector3d &getCameraPos() override;
	Tools::vector3d &getCameraRot() override;
	void compute(std::pair<int, std::string> &pair) override;
	IScene *newScene() override;
	void checkEvents(std::pair<int, std::string> &pair) override;

private:
	bool		_verbose;
	GenerateMap	_map;
	Tools::vector3d	_cameraPos;
	Tools::vector3d	_cameraRot;
	std::map<std::string, Data>	_models;
	std::map<std::string, Data>	_guis;
};

#endif //BOMBERMAN_DIEDSCENE_HPP
