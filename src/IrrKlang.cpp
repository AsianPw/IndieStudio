/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/

#include <stdexcept>
#include "../inc/IrrKlang.hpp"

IrrKlang::IrrKlang()
{
	_engine = irrklang::createIrrKlangDevice();
	if (!_engine)
		throw std::runtime_error("Couldn't create audio device !");
}

void IrrKlang::play(std::string const &musicFile)
{
	_source.insert({musicFile, _engine->play2D(musicFile.c_str(), true)});
}

void IrrKlang::pause()
{
}

void IrrKlang::resume()
{
}

void IrrKlang::addSound(std::string const &musicFile)
{
}
