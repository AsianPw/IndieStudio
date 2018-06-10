/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef CORE_HPP
#define CORE_HPP

#include <memory>
#include "IDisplay.hpp"
#include "ISound.hpp"
#include "IScene.hpp"
#include "Params.hpp"

class Core {
public:
	explicit Core(std::unique_ptr<Params> &params);
	~Core();
	void	compute();

private:
	void	changeScene(IScene *);
	void	goSetting();

private:
	std::unique_ptr<IDisplay>	_display;
	std::unique_ptr<ISound>		_sound;
	std::unique_ptr<IScene>		_scene;
	IScene				*_prevScene;
	bool	_verbose;
	bool	_change;
};

#endif //BOMBERMAN_CORE_HPP
