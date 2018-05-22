/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Display Interface
*/
#ifndef IDISPLAY_HPP
#define IDISPLAY_HPP

class IDisplay {
public:
	~IDisplay() = default;
	virtual void	display() const = 0;
	virtual bool	isOpen() const = 0;
	virtual char	getEvents() const = 0;
	virtual bool	isEvent() const = 0;
};

#endif //BOMBERMAN_IDISPLAY_HPP
