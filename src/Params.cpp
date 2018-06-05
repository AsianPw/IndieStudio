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
}

void	Params::displayHelp() const
{
	std::cerr << "USAGE:" << std::endl;
	std::cerr << "\t\t" << _av[0] << " [options]" << std::endl;
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
	if (argsExist("-h") || argsExist("--help")) {
		displayHelp();
		return false;
	}
	if (argsExist("-v") || argsExist("--verbose")) {
		_verbose = true;
	}
	return true;
}

std::pair<size_t, size_t>	Params::getResolution() const
{
	return std::make_pair(_width, _height);
}