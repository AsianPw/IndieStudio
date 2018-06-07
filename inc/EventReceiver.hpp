/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by j-f,
*/
#ifndef BOMBERMAN_EVENTRECEIVER_HPP
#define BOMBERMAN_EVENTRECEIVER_HPP

#include <irr/irrlicht.h>
using namespace irr;

class MyEventReceiver : public IEventReceiver
{
	public:
	MyEventReceiver();
	virtual bool OnEvent(const SEvent& event)
	{
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		return false;
	}
	virtual bool IsKeyDown(EKEY_CODE keyCode) const
	{
		return KeyIsDown[keyCode];
	}
	private:
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

#endif //BOMBERMAN_EVENTRECEIVER_HPP
