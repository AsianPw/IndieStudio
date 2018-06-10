/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Irrlicht
*/

#include <irr/irrlicht.h>
#include <stdexcept>
#include <iostream>
#include <irr/driverChoice.h>
#include "../inc/Irrlicht.hpp"
#include "../inc/Data.hpp"
#include "../inc/Tools.hpp"
#include "../inc/PlayerMove.hpp"

Irrlicht::Irrlicht(std::unique_ptr<Params> &params) :
	_resolution({(irr::u32)params->getResolution().first, (irr::u32)params->getResolution().second}),
	_verbose(params->getVerbose()),
	_deviceReceiver(params->getVerbose())
{
	_device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d(_resolution.first, _resolution.second), 32, params->getFullscreen(), false, params->getVsync(), &_deviceReceiver);
	if (_device == nullptr)
		throw std::runtime_error("Couldn't find any device !");
	_device->setWindowCaption(L"Bomberman");
	_driver = _device->getVideoDriver();
	if (_driver == nullptr)
		throw std::runtime_error("Couldn't get any video driver !");
	_sceneManager = _device->getSceneManager();
	_gui = _device->getGUIEnvironment();
	_font = _gui->getFont("texture/bigfont.png");
	if (_font == nullptr)
		throw std::runtime_error("Couldn't load font !");
	_camera = _sceneManager->addCameraSceneNode(nullptr, irr::core::vector3df(100.0f, .0f, 20.0f), irr::core::vector3df(0.0f, 0.0f, 0.0f));
	_sceneManager->setAmbientLight(irr::video::SColorf(1.0,1.0,1.0,0.0));
	_gui->getSkin()->setFont(_font, irr::gui::EGDF_BUTTON);
	_gui->getSkin()->setFont(_font, irr::gui::EGDF_DEFAULT);
}

Irrlicht::~Irrlicht()
{
	_device->drop();
}

void	Irrlicht::clear()
{
	_guiElement.clear();
	_sceneElement.clear();
	_sceneManager->clear();
	_gui->clear();
	_textElement.clear();
	_sceneCube.clear();
	_camera = _sceneManager->addCameraSceneNode(nullptr, irr::core::vector3df(100.0f, .0f, 20.0f), irr::core::vector3df(0.0f, 0.0f, 0.0f));
	_sceneManager->setAmbientLight(irr::video::SColorf(1.0,1.0,1.0,0.0));
}

void	Irrlicht::display()
{
	irr::video::SColor	color(255, 0, 0, 0);

	if (_deviceReceiver.IsKeyDown(irr::KEY_ESCAPE)) {
		_device->closeDevice();
	}
	_driver->beginScene(true, true, color);
	_sceneManager->drawAll();
	_gui->drawAll();
	_driver->endScene();
}

bool	Irrlicht::isOpen() const
{
	return _device->run();
}

void	Irrlicht::getEvents(std::pair<int, std::string> &keyCode)
{
	std::string	btnName = "";

	for (auto const &btn : _guiElement) {
		if (btn.second->isPressed()) {
			btnName = btn.first;
		}
	}
	keyCode.first = _deviceReceiver.getKey();
	keyCode.second = btnName;
}

bool	Irrlicht::isEvent() const
{
	for (auto const &btn : _guiElement) {
		if (btn.second->isPressed()) {
			return true;
		}
	}
	return _deviceReceiver.isEvent();
}

void Irrlicht::loadModels(std::map<std::string, Data> &models)
{
	_sceneData = models;
	for (auto const &model : models) {
		_sceneElement.insert({model.first, _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh(model.second.modelPath.c_str()))});
		if (_sceneElement[model.first] == nullptr) {
			continue;
		}
		_sceneElement[model.first]->setMD2Animation(model.second.animationType);
		_sceneElement[model.first]->setPosition(irr::core::vector3df(model.second.pos.x, 0.0f, model.second.pos.y));
		_sceneElement[model.first]->setRotation(irr::core::vector3df(model.second.rot.x, model.second.rot.y, .0f));
		if (!model.second.texturePath.empty()) {
			_sceneElement[model.first]->setMaterialTexture(0, _driver->getTexture(model.second.texturePath.c_str()));
		}
	}
}

void Irrlicht::updateModels(std::map<std::string, Data> &models)
{
	Data	tmpData;

	for (auto const &currentModel : _sceneData) {
		tmpData = models[currentModel.first];
		if (tmpData.animationType != currentModel.second.animationType
			|| !Tools::cmpPos(tmpData.pos, _sceneData[currentModel.first].pos) ) {
			_sceneElement[currentModel.first]->setMD2Animation(tmpData.animationType);
			_sceneElement[currentModel.first]->setPosition(Tools::posToVec(tmpData.pos));
			//Tools::displayVerbose(_verbose, "Update \"" + currentModel.first + "\" model.");
			_sceneData[currentModel.first] = tmpData;
		}
	}
}

void Irrlicht::loadGuis(std::map<std::string, Data> &guis)
{
	std::wstring	tmpString;
	irr::gui::IGUIStaticText	*tmpText;
	irr::gui::IGUIButton		*tmpBtn;
	irr::core::dimension2d<irr::u32>	textSize;
	irr::core::rect<irr::s32>	rect;

	for (auto const &gui : guis) {
		Tools::displayVerbose(_verbose, "Add GUI element: " + gui.first);
		tmpString = std::wstring(gui.second.modelPath.begin(), gui.second.modelPath.end());
		textSize = _font->getDimension(tmpString.c_str());
		rect = irr::core::rect<irr::s32>(gui.second.pos.x, gui.second.pos.y, gui.second.pos.x + textSize.Width + 5, gui.second.pos.y + textSize.Height + 5);
		if (gui.second.isBnt) {
			tmpBtn = _gui->addButton(rect, nullptr, -1, tmpString.c_str());
			_guiElement.insert({ gui.first, tmpBtn });
		} else {
			_textElement.insert({ gui.first, _gui->addStaticText(tmpString.c_str(), rect, _verbose, true, nullptr, -1, false) });
			tmpText = (irr::gui::IGUIStaticText *)_textElement[gui.first];
			tmpText->setOverrideColor(irr::video::SColor(255, 255, 255, 255));
		}
	}
}

void Irrlicht::getMap(std::vector<std::vector<char>> &map)
{
	size_t	x = 0;
	size_t	y = 0;

	generateGround();
	if (map.empty()) {
		return;
	}
	for (auto const &line : map) {
		x = 0;
		for (auto const &element : line) {
			Tools::displayVerbose(_verbose,std::string(1, element), false);
			if (element != '*' && element != '#') {
				x++;
				continue;
			}
			_sceneCube.push_back(_sceneManager->addCubeSceneNode(_cubeSize));
			_sceneCube.back()->setPosition(irr::core::vector3df(x * _cubeSize, 0, y * _cubeSize));
			if (element == '#')
				_sceneCube.back()->setMaterialTexture(0, _driver->getTexture("texture/cobble.png"));
			else
				_sceneCube.back()->setMaterialTexture(0, _driver->getTexture("texture/wall.png"));
			x++;
		}
		y++;
		Tools::displayVerbose(_verbose, "");
	}
	Tools::displayVerbose(_verbose, "\n");
}

void	Irrlicht::changeCameraPosition(Tools::vector3d &pos, Tools::vector3d &rot)
{
	auto cameraPos = _camera->getPosition();
	auto cameraRot = _camera->getRotation();

	if (cameraPos.X != pos.x || cameraPos.Y != pos.y || cameraPos.Z != pos.z) {
		_camera->setPosition(irr::core::vector3df(pos.x, pos.y, pos.z));
		//Tools::displayVerbose(_verbose, "Update Position of camera.");
	}
	if (cameraRot.X != rot.x || cameraRot.Y != rot.y || cameraRot.Z != rot.z) {
		if (!_sceneCube.empty()) {
			_camera->setTarget(irr::core::vector3df(rot.x, rot.y, rot.z));
			//Tools::displayVerbose(_verbose, "Update Rotation of camera.");
		}
	}
}

void Irrlicht::generateGround()
{
	for (auto y = -70; y < 70; y++) {
		for (auto x = -70; x < 40; x++) {
			_sceneCube.push_back(_sceneManager->addCubeSceneNode(_cubeSize));
			_sceneCube.back()->setPosition(irr::core::vector3df(x * _cubeSize, -_cubeSize, y * _cubeSize));
			_sceneCube.back()->setMaterialTexture(0, _driver->getTexture("texture/téléchargement.jpeg"));
		}
	}
	_sceneManager->addSkyDomeSceneNode(_driver->getTexture("texture/dom.jpg"));
}