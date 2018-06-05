/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Display Interface
*/
#ifndef IDISPLAY_HPP
#define IDISPLAY_HPP

#include <map>
#include "Position.hpp"

class IDisplay {
public:
	virtual ~IDisplay() = default;
	virtual void	display() const = 0;
	virtual bool	isOpen() const = 0;
	virtual void	loadModels(std::map<std::string, Position> &) = 0;
	virtual char	getEvents() const = 0;
	virtual bool	isEvent() const = 0;
};

#endif //BOMBERMAN_IDISPLAY_HPP
