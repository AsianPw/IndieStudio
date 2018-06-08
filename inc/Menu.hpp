/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_MENU_HPP
#define BOMBERMAN_MENU_HPP

#include "IScene.hpp"

class Menu : public IScene{
public:
	explicit Menu(bool);
	~Menu() override = default;
	std::map<std::string, Data> &getModels() override;
	std::map<std::string, Data> &getGuis() override;
	void compute(std::pair<int, std::string> &keyCode) override;
	IScene *newScene() override;
	void checkEvents(std::pair<int, std::string> &) override;

private:
	std::map<std::string, Data>	_models;
	std::map<std::string, Data>	_guis;
	bool	_verbose;
	bool	_change;
	IScene	*_scene;
};

#endif //BOMBERMAN_MENU_HPP
