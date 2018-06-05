/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_PARAMS_HPP
#define BOMBERMAN_PARAMS_HPP

class Params {
public:
	Params(int ac, char *av[]);
	~Params() = default;
	bool	parse();
	bool	getVerbose() const;
	std::pair<size_t, size_t>	getResolution() const;
private:
	void	displayHelp() const;
	bool	argsExist(const char *arg) const;
private:
	bool	_verbose;
	char	**_av;
	int	_nbArgs;
	size_t	_width;
	size_t	_height;
};

#endif //BOMBERMAN_PARAMS_HPP
