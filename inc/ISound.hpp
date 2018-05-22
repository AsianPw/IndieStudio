/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_ISOUND_HPP
#define BOMBERMAN_ISOUND_HPP

class ISound {
public:
	~ISound() = default;
	virtual void	play() = 0;
	virtual void	pause() = 0;
	virtual void	resume() = 0;
	virtual void	addSound() = 0;
};

#endif //BOMBERMAN_ISOUND_HPP
