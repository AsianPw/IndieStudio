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
#include "../inc/IrrKlang.hpp"
#include "../inc/Settings.hpp"

Core::Core(std::unique_ptr<Params> &params) : _verbose(params->getVerbose()), _prevScene(nullptr)
{
	try {
		_display = std::make_unique<Irrlicht>(params);
		changeScene(new Preroll(params->getVerbose()));
		_sound = std::make_unique<IrrKlang>();
		_sound->play("media/menu_sound.ogg");
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
			std::cerr << keyCode.first << std::endl;
			if (keyCode.first == KeyCode::KEY_M) {
				keyCode.first = -1;
				changeScene(new Menu(_verbose));
			}
			if (keyCode.first == KeyCode::KEY_P && !_prevScene) {
				keyCode.first = -1;
				goSetting();
			}
			if (keyCode.first == KeyCode::KEY_ENTER && _prevScene) {
				keyCode.first = -1;
				changeScene(_prevScene);
			}
			_scene->checkEvents(keyCode);
		}
		//_display->displayMap(_scene->getMap());
		_display->changeCameraPosition(_scene->getCameraPos(), _scene->getCameraRot());
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
	Tools::displayVerbose(_verbose, "LOAD NEW SCENE:\n\tClear scene data...");
	_display->clear();
	Tools::displayVerbose(_verbose, "\tLoad new scene...");
	_scene.reset(newScene);
	Tools::displayVerbose(_verbose, "\tLoad Model...");
	_display->loadModels(_scene->getModels());
	Tools::displayVerbose(_verbose, "\tLoad Gui...");
	_display->loadGuis(_scene->getGuis());
	Tools::displayVerbose(_verbose, "\tLoad Map...");
	_display->getMap(_scene->getMap());
	_prevScene = nullptr;
}

void	Core::goSetting()
{
	Tools::displayVerbose(_verbose, "GO SETTINGS");
	_prevScene = _scene.release();
	changeScene(new Settings(_prevScene));
}