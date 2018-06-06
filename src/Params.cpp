/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Parse Params
*/
#include <cstddef>
#include <cstring>
#include <iostream>
#include "../inc/Params.hpp"

Params::Params(int ac, char **av) : _verbose(false), _nbArgs(ac), _av(av), _width(1080), _height(720)
{
}

bool	Params::getVerbose() const
{
	return _verbose;
}

void	Params::displayHelp() const
{
	std::cerr << "USAGE:" << std::endl;
	std::cerr << "\t\t" << _av[0] << " [options]" << std::endl << std::endl;
	std::cerr << "Here is the list of diferents options : " <<std::endl;
	std::cerr << std::endl;
	std::cerr << "\t\t-s or --size [width] [height]\tSet window dimensions" << std::endl;
	std::cerr << "\t\t-v or --verbose\t\t\tPrint all object's informations (position and others)" << std::endl;
	std::cerr << "\t\t-f or --fullscreen\t\tUse the fullscreen option" << std::endl;
}

bool	Params::argsExist(const char *arg) const
{
	for (int count = 0; count < _nbArgs; ++count) {
		if (!strcmp(arg, _av[count])) {
			return true;
		}
	}
	return false;
}

bool	Params::parse()
{
	if (argsExist("-v") || argsExist("--verbose"))
		_verbose = true;
	if (argsExist("-f") || argsExist("--fullscreen"))
		_fullscreen = true;
	if (argsExist("-h") || argsExist("--help")) {
		displayHelp();
		return false;
	}
	if (argsExist("-s") || argsExist("--size")) {
		_width = atoi(_av[2]);
		_height = atoi(_av[3]);
		if (_width  <= 0 || _height <= 0) {
			std::cerr << "width and height , both of them must";
			std::cout << " be positive integers" << std::endl;
			return 84;
		}
	}
	return true;
}

std::pair<size_t, size_t>	Params::getResolution() const
{
	return std::make_pair(_width, _height);
}