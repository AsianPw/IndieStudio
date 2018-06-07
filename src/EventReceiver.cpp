/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by j-f,
*/

#include "../inc/EventReceiver.hpp"

MyEventReceiver::MyEventReceiver()
{
	for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
		KeyIsDown[i] = false;
}