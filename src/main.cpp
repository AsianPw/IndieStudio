/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Main
*/

#include <memory>
#include <iostream>
#include "../inc/Params.hpp"

int main(int ac, char *av[])
{
	std::unique_ptr<Params>	params(new Params(ac, av));

	if (params->parse()) {
		std::cout << "" << std::endl;
	}
	return (0);
}
