/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Irrlicht
*/

#include <irr/irrlicht.h>
#include <stdexcept>
#include "../inc/Irrlicht.hpp"

Irrlicht::Irrlicht(std::pair<size_t, size_t> res) : _resolution({res.first, res.second})
{
	_device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d(_resolution.first, _resolution.second), 32);
	if (_device == nullptr)
		throw std::runtime_error("Couldn't find any device !");
	_device->setWindowCaption(L"Bomberman");
	_driver = _device->getVideoDriver();
	if (_driver == nullptr)
		throw std::runtime_error("Couldn't get any video driver !");
	_sceneManager = _device->getSceneManager();
	_gui = _device->getGUIEnvironment();
	keys[0].Action = irr::EKA_MOVE_FORWARD;
	keys[0].KeyCode = irr::KEY_KEY_Z;
	keys[1].Action = irr::EKA_MOVE_BACKWARD;
	keys[1].KeyCode = irr::KEY_KEY_S;
	keys[2].Action = irr::EKA_STRAFE_LEFT;
	keys[2].KeyCode = irr::KEY_KEY_Q;
	keys[3].Action = irr::EKA_STRAFE_RIGHT;
	keys[3].KeyCode = irr::KEY_KEY_D;
	keys[4].Action = irr::EKA_JUMP_UP;
	keys[4].KeyCode = irr::KEY_SPACE;
	_sceneManager->addCameraSceneNodeFPS(nullptr, 100.0f, 0.1f, -1, keys, 5);
	//_sceneManager->addCameraSceneNode(nullptr, irr::core::vector3df(100.0f, 80.0f, 100.0f), irr::core::vector3df(0.0f, 0.0f, 0.0f));
}

Irrlicht::~Irrlicht()
{
	_device->drop();
}

void	Irrlicht::display() const
{
	irr::video::SColor	color(255, 255, 255, 255);

	_driver->beginScene(true, true, color);
	_sceneManager->drawAll();
	_gui->drawAll();
	_driver->endScene();
}

bool	Irrlicht::isOpen() const
{
	return _device->run();
}

char	Irrlicht::getEvents() const
{
	return 0;
}

bool	Irrlicht::isEvent() const
{
	return false;
}

void Irrlicht::loadModels(std::map<std::string, Position> &models)
{
	// add check if not load
	for (auto const &model : models) {
		_sceneElement.insert({model.first, _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh(model.first.c_str()))});
		if (_sceneElement[model.first] == nullptr) {
			continue;
		}
		_sceneElement[model.first]->setMD2Animation(irr::scene::EMAT_STAND);
		_sceneElement[model.first]->setPosition(irr::core::vector3df(model.second.x, model.second.y, 0.0f));
		_sceneElement[model.first]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_sceneElement[model.first]->setMaterialTexture(0, _driver->getTexture("texture/assassin/textures/akai_diffuse.jpg"));
	}
}
