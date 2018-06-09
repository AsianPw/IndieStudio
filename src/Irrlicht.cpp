/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Irrlicht
*/

#include <irr/irrlicht.h>
#include <stdexcept>
#include <iostream>
#include "../inc/Irrlicht.hpp"
#include "../inc/Data.hpp"
#include "../inc/Tools.hpp"
#include "../inc/PlayerMove.hpp"

Irrlicht::Irrlicht(std::unique_ptr<Params> &params) :
	_resolution({(irr::u32)params->getResolution().first, (irr::u32)params->getResolution().second}),
	_verbose(params->getVerbose()),
	_deviceReceiver(params->getVerbose())
{
	bool pixel_shader_support;
	bool vertex_shader_support;
	_device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d(_resolution.first, _resolution.second), 32, params->getFullscreen(), false, params->getVsync(), &_deviceReceiver);
	if (_device == nullptr)
		throw std::runtime_error("Couldn't find any device !");
	_device->setWindowCaption(L"Bomberman");
	_driver = _device->getVideoDriver();
	if (_driver == nullptr)
		throw std::runtime_error("Couldn't get any video driver !");
	pixel_shader_support = (_driver->queryFeature(irr::video::EVDF_PIXEL_SHADER_1_1) || _driver->queryFeature(irr::video::EVDF_ARB_FRAGMENT_PROGRAM_1));
	vertex_shader_support = (_driver->queryFeature(irr::video::EVDF_VERTEX_SHADER_1_1) || _driver->queryFeature(irr::video::EVDF_ARB_VERTEX_PROGRAM_1));
	if ( !pixel_shader_support || !vertex_shader_support )
		throw std::runtime_error("Shaders 1.1 aren't support on this device !");
	_gpu = _driver->getGPUProgrammingServices();
	if (!_gpu)
		throw std::runtime_error("Unable to load GPU !");
	_sceneManager = _device->getSceneManager();
	_gui = _device->getGUIEnvironment();
	_font = _gui->getFont("texture/bigfont.png");
	if (_font == nullptr)
		throw std::runtime_error("Couldn't load font !");
	_sceneManager->addCameraSceneNode(nullptr, irr::core::vector3df(100.0f, .0f, 20.0f), irr::core::vector3df(0.0f, 0.0f, 0.0f));
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
	_sceneManager->addCameraSceneNode(nullptr, irr::core::vector3df(100.0f, .0f, 20.0f), irr::core::vector3df(0.0f, 0.0f, 0.0f));
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
		_sceneElement[model.first]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
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
	float	size = 10.0f;

	if (map.empty()) {
		return;
	}
	for (auto const &line : map) {
		x = 0;
		for (auto const &element : line) {
			Tools::displayVerbose(_verbose,std::string(1, element), false);
			if (element != '*') {
				x++;
				continue;
			}
			_sceneCube.push_back(_sceneManager->addCubeSceneNode(size));
			_sceneCube.back()->setPosition(irr::core::vector3df(x * size, 0, y * size));
			_sceneCube.back()->setMaterialTexture(0, _driver->getTexture("texture/breakable_wall.jpg"));
			_sceneCube.back()->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			x++;
		}
		y++;
		Tools::displayVerbose(_verbose, "");
	}
	Tools::displayVerbose(_verbose, "\n\n\n\n\n\n");
}
