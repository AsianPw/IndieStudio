/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Irrlicht
*/

#include <irr/irrlicht.h>
#include "../inc/Irrlicht.hpp"

Irrlicht::Irrlicht(size_t width, size_t height) : _resolution({width, height})
{
	_device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d(_resolution.first, _resolution.second), 32);
	_driver = _device->getVideoDriver();
	_sceneManager = _device->getSceneManager();
}

void	Irrlicht::display() const
{
}

bool	Irrlicht::isOpen() const
{
	return false;
}

char	Irrlicht::getEvents() const
{
	return 0;
}

bool	Irrlicht::isEvent() const
{
	return false;
}
