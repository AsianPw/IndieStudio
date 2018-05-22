/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_ISCENE_HPP
#define BOMBERMAN_ISCENE_HPP

class IScene {
public:
	~IScene() = default;
	virtual void	compute() = 0;
	virtual void	checkEvents(char event) = 0;

};

#endif //BOMBERMAN_ISCENE_HPP
