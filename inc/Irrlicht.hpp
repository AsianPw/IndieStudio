/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Irrlicht
*/
#ifndef IRRLICHT_HPP
#define IRRLICHT_HPP

#include <cstddef>
#include <irr/irrlicht.h>
#include <vector>
#include <map>
#include "IDisplay.hpp"
#include "Position.hpp"

class Irrlicht : public IDisplay {
public:
	explicit Irrlicht(std::pair<size_t, size_t> res);
	~Irrlicht() override;
	void	display() const override;
	bool	isOpen() const override;
	char	getEvents() const override;
	bool	isEvent() const override;
	void loadModels(std::map<std::string, Position> &) override;
private:
	std::pair<irr::u32, irr::u32>	_resolution;
	irr::SKeyMap			keys[5];
	irr::IrrlichtDevice		*_device;
	irr::video::IVideoDriver	*_driver;
	irr::gui::IGUIEnvironment	*_gui;
	std::vector<irr::gui::IGUIElement>	_guiElement;
	std::map<std::string, irr::scene::IAnimatedMeshSceneNode *>	_sceneElement;
	irr::scene::ISceneManager	*_sceneManager;
};

#endif //BOMBERMAN_IRRLICHT_HPP
