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

void	IrrKlang::play(std::string const &musicFile)
{
	if (_source.find(musicFile) != _source.end()) {
		return;
	}
	_source.clear();
	pause();
	_source.insert({musicFile, _engine->play2D(musicFile.c_str(), true)});
}

void	IrrKlang::pause()
{
	_engine->setAllSoundsPaused(true);
}

void	IrrKlang::resume()
{
	_engine->setAllSoundsPaused(false);
}

void	IrrKlang::addSound(std::string const &musicFile, int volume)
{
	irrklang::ISound	*tmp;

	if (_engine->isCurrentlyPlaying(musicFile.c_str())){
		return;
	}
	tmp = _engine->play2D(musicFile.c_str(), false, false, true);
	tmp->setVolume(volume / 100.0f);
}

void	IrrKlang::clearUnused()
{
	auto i = std::begin(_source);

	while (i != std::end(_source)) {
		if (i->second && i->second->isFinished())
			i = _source.erase(i);
		else
			++i;
	}
}
