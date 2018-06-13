/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#include "../inc/DiedScene.hpp"

DiedScene::DiedScene(bool verbose) : _verbose(verbose), _map(1, 3)
{

}

std::map<std::string, Data> &DiedScene::getModels()
{
	return _models;
}

std::map<std::string, Data> &DiedScene::getGuis()
{
	return _guis;
}

std::vector<std::vector<char>> &DiedScene::getMap()
{
	return _map.getMap();
}

Tools::vector3d &DiedScene::getCameraPos()
{
	return _cameraPos;
}

Tools::vector3d &DiedScene::getCameraRot()
{
	return _cameraRot;
}

void DiedScene::compute(std::pair<int, std::string> &pair)
{
}

IScene *DiedScene::newScene()
{
	return nullptr;
}

void DiedScene::checkEvents(std::pair<int, std::string> &pair)
{
}
