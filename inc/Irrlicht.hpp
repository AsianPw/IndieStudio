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
#include <memory>
#include "IDisplay.hpp"
#include "Position.hpp"
#include "Params.hpp"
#include "DeviceReceiver.hpp"

class Irrlicht : public IDisplay {
public:
	explicit Irrlicht(std::unique_ptr<Params> &params);
	~Irrlicht() override;
	void	display() override;
	void	clear() override;
	bool	isOpen() const override;
	void	getEvents(std::pair<int, std::string> &keyCode) override;
	bool	isEvent() const override;
	void loadModels(std::map<std::string, Data> &) override;
	void updateModels(std::map<std::string, Data> &) override;
	void loadGuis(std::map<std::string, Data> &map) override;
	void changeCameraPosition(Tools::vector3d &, Tools::vector3d &) override;
	void getMap(std::vector<std::vector<char>> &vector) override;

private:
	void generateGround();

private:
	std::pair<irr::u32, irr::u32>	_resolution;
	irr::gui::IGUIFont		*_font;
	irr::IrrlichtDevice		*_device;
	irr::video::IVideoDriver	*_driver;
	irr::gui::IGUIEnvironment	*_gui;
	irr::scene::ICameraSceneNode	*_camera;
	float	_cubeSize = 10.0f;
	std::map<std::string, irr::gui::IGUIButton *>	_guiElement;
	std::map<std::string, irr::gui::IGUIElement *>	_textElement;
	std::map<std::string, irr::scene::IAnimatedMeshSceneNode *>	_sceneElement;
	std::vector<irr::scene::IMeshSceneNode *>	_sceneCube;
	std::map<std::string, Data>	_sceneData;
	irr::scene::ISceneManager	*_sceneManager;
	DeviceReceiver	_deviceReceiver;
	bool	_verbose;
};

#endif //BOMBERMAN_IRRLICHT_HPP
