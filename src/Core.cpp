/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#include <iostream>
#include "../inc/Core.hpp"
#include "../inc/Irrlicht.hpp"
#include "../inc/Preroll.hpp"
#include "../inc/Tools.hpp"
#include "../inc/keyCodes.hpp"
#include "../inc/Menu.hpp"
#include "../inc/PlayerMove.hpp"

Core::Core(std::unique_ptr<Params> &params) : _verbose(params->getVerbose())
{
	try {
		_display = std::make_unique<Irrlicht>(params);
		_scene = std::make_unique<Preroll>(params->getVerbose());
		_display->loadModels(_scene->getModels());
		_display->loadGuis(_scene->getGuis());
		_display->getMap(_scene->getMap());
	} catch (const std::runtime_error &e) {
		throw;
	}
}

Core::~Core()
{
}

void	Core::compute()
{
	IScene	*scene;
	std::pair<int, std::string>	keyCode;

	while (_display->isOpen()) {
		_change = false;
		keyCode.first = -1;
		keyCode.second = "";
		if (_display->isEvent()) {
			_display->getEvents(keyCode);

			if (keyCode.first == 38) {
				std::cout << "Up direction" << std::endl;
				// TO DO MOVMNT PLAYER
			}
			if (keyCode.first == 39) {
				std::cout << "Right Direction" << std::endl;
				// TO DO MOVMNT PLAYER
			}
			if (keyCode.first == 40) {
				std::cout << "Down direction" << std::endl;
				// TO DO MOVMNT PLAYER
			}
			if (keyCode.first == 37) {
				std::cout << "Left Direction" << std::endl;
				// TO DO MOVMNT PLAYER OR
			}
			if (keyCode.first == 32) {
				std::cout << "Use bomb option" << std::endl;
				// TO DO USING OF BOMB
			}
			std::cerr << keyCode.first << " " << keyCode.second << std::endl;
			if (keyCode.first == KeyCode::KEY_M) {
				keyCode.first = -1;
				changeScene(new Menu(_verbose));
			}
			_scene->checkEvents(keyCode);
		}
		_scene->compute(keyCode);
		_display->updateModels(_scene->getModels());
		_display->display();
		scene = _scene->newScene();
		if (scene != nullptr) {
			changeScene(scene);
		}
	}
}

void	Core::changeScene(IScene *newScene)
{
	Tools::displayVerbose(_verbose, "CHANGE SCENE:\n\tClear scene data...");
	_display->clear();
	Tools::displayVerbose(_verbose, "\tLoad new scene...");
	_scene.reset(newScene);
	Tools::displayVerbose(_verbose, "\tLoad Model...");
	_display->loadModels(_scene->getModels());
	Tools::displayVerbose(_verbose, "\tLoad Gui...");
	_display->loadGuis(_scene->getGuis());
	Tools::displayVerbose(_verbose, "\tLoad Map...");
	_display->getMap(_scene->getMap());
}