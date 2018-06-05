/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#include "../inc/Core.hpp"
#include "../inc/Irrlicht.hpp"
#include "../inc/Preroll.hpp"

Core::Core(std::unique_ptr<Params> &params)
{
	try {
		_display = std::make_unique<Irrlicht>(params->getResolution());
		_scene = std::make_unique<Preroll>();
	} catch (const std::runtime_error &e) {
		throw;
	}
}

Core::~Core()
{
}

void	Core::compute()
{
	while (_display->isOpen()) {
		_display->loadModels(_scene->getModels());
		_display->display();
	}
}

void Core::changeScene()
{
}