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

class Core {
public:
	Core();
	~Core();
	void	changeScene();
private:
	std::unique_ptr<IDisplay>	_display;
	std::unique_ptr<ISound>		_sound;
	std::unique_ptr<IScene>		_scene;
};

#endif //BOMBERMAN_CORE_HPP
