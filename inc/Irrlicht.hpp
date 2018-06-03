/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Irrlicht
*/
#ifndef IRRLICHT_HPP
#define IRRLICHT_HPP

#include <cstddef>
#include "IDisplay.hpp"

class Irrlicht : public IDisplay {
public:
	Irrlicht(size_t width, size_t height);
	void	display() const override;
	bool	isOpen() const override;
	char	getEvents() const override;
	bool	isEvent() const override;
private:
	std::pair<irr::u32, irr::u32>	_resolution;
	irr::IrrlichtDevice	*_device;
	irr::video::IVideoDriver	*_driver;
	irr::scene::ISceneManager	*_sceneManager;
};

#endif //BOMBERMAN_IRRLICHT_HPP
