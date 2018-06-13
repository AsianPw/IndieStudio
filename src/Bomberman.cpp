/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/

#include "../inc/Bomberman.hpp"
#include "../inc/keyCodes.hpp"
#include "../inc/PlayerMove.hpp"
#include "../inc/Ia.hpp"
#include "../inc/Time.hpp"
#include "../inc/Menu.hpp"
#include "../inc/Tools.hpp"

Bomberman::Bomberman(bool _verbose, size_t nbPlayer, size_t nbIa)
	: _verbose(_verbose), _cameraPos({500.0f, 400.0f, 225.0f}), _cameraRot({ 120.0f, 0.0f, 225.0f}), _map(nbPlayer, nbIa), _change(false), _isEnd(false), _deathCamera(false)
{
	check_b = true;
	check_c = true;
	check_d = true;
	currentTime = getCurrentTime();
	player.x = 30;
	player.y = 30;
	playerrotate.x = 0;
	playerrotate.y = 70;
	ia.x = 30;
	ia.y = 380;
	ia1.x = 380;
	ia1.y = 380;
	ia2.x = 380;
	ia2.y = 30;
	loose_text.x = 170;
	loose_text.y = 400;
	_models.insert({"player", { {player.x, player.y}, {0, 70}, "texture/characters/ziggs.png", "texture/characters/ziggs.md3", irr::scene::EMAT_STAND, false, true }});
	_models.insert({"player2", { {ia.x, ia.y}, {0, 70}, "texture/characters/ziggs_general.png", "texture/characters/ziggs.md3", irr::scene::EMAT_STAND, false, true, 'B' }});
	_models.insert({"player3", { {ia1.x, ia1.y}, {0, 70}, "texture/characters/ziggs_general.png", "texture/characters/ziggs.md3", irr::scene::EMAT_STAND, false, true, 'C' }});
	_models.insert({"player4", { {ia2.x, ia2.y}, {0, 70}, "texture/characters/ziggs_general.png", "texture/characters/ziggs.md3", irr::scene::EMAT_STAND, false, true, 'D' }});
	_guis.insert({"score", { {400, 100}, {0, 180}, "", "Score : " + std::to_string(score), irr::scene::EMAT_STAND, false, true }});
	_guis.insert({"dead", { {loose_text.x, loose_text.y}, {0, 0}, "", "You loose. Press [M] to back to menu.", irr::scene::EMAT_STAND, false, false }});
	_guis.insert({"win", { {loose_text.x, loose_text.y}, {0, 0}, "", "You win. Press [M] to back to menu.", irr::scene::EMAT_STAND, false, false }});
}

std::map<std::string, Data> &Bomberman::getModels()
{
	return _models;
}

std::map<std::string, Data> &Bomberman::getGuis()
{
	return _guis;
}

std::vector<std::vector<char>> &Bomberman::getMap()
{
	return _map.getMap();
}

Tools::vector3d &Bomberman::getCameraPos()
{
	return _cameraPos;
}

Tools::vector3d &Bomberman::getCameraRot()
{
	return _cameraRot;
}

void Bomberman::compute(std::pair<int, std::string> &events)
{
	long	now = getCurrentTime();

	checkGame();
	if (_isEnd) {
		if (_deathCamera)
			_cameraPos.y -= 1;
		else
			_cameraPos.y += 1;
		if (_cameraPos.y > 500 || _cameraPos.y < 350)
			_deathCamera = !_deathCamera;
		return;
	}
	if (now - currentTime > 1000) {
		Ia B('B', _map.getMap());
		Ia C('C', _map.getMap());
		Ia D('D', _map.getMap());
		B.start();
		C.start();
		D.start();
		checkBomb();
		currentTime = now;
	}
	_guis["score"].modelPath = "Score : " + std::to_string(score);
}

IScene *Bomberman::newScene()
{
	if (_change && _isEnd) {
		return new Menu(_verbose);
	}
	return nullptr;
}

bool	Bomberman::checkPlayer(char c)
{
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (_map.getMap()[i][j] == c) {
				return true;
			}
		}
	}
	return false;
}

void	Bomberman::bombExplode(Position p)
{
	int	x = 1;
	std::vector<std::vector<char>> &map = getMap();
	bool	top = false;
	bool	bot = false;
	bool	right = false;
	bool	left = false;

	map = _map.getMap();
	map[p.x][p.y] = ' ';
	while (x < 3)
	{
		if ((p.x + x) < 15 && map[p.x + x][p.y] != '*' && !top)
		{
			if (map[p.x + x][p.y] >= 49 && map[p.x + x][p.y] <= 51)
				bombExplode({p.x + x, p.y});
			if (map[p.x + x][p.y] != ' ')
				top = true;
			map[p.x + x][p.y] = ' ';
			score = score + 10;
		}
		if ((p.x - x) > 0 && map[p.x - x][p.y] != '*' && !bot)
		{
			if (map[p.x - x][p.y] >= 49 && map[p.x - x][p.y] <= 51)
				bombExplode({p.x - x, p.y});
			if (map[p.x - x][p.y] != ' ')
				bot = true;
			map[p.x - x][p.y] = ' ';
			score = score + 10;
		}
		if ((p.y + x) < 15 && map[p.x][p.y + x] != '*' && !right)
		{
			if (map[p.x][p.y + x] >= 49 && map[p.x][p.y + x] <= 51)
				bombExplode({p.x, p.y + x});
			if (map[p.x][p.y + x] != ' ')
				right = true;
			map[p.x][p.y + x] = ' ';
			score = score + 10;
		}
		if ((p.y - x) > 0 && map[p.x][p.y - x] != '*' && !left)
		{
			if (map[p.x][p.y - x] >= 49 && map[p.x][p.y - x] <= 51)
				bombExplode({p.x, p.y - x});
			if (map[p.x][p.y - x] != ' ')
				left = true;
			map[p.x][p.y - x] = ' ';
			score = score + 10;
		}
		x++;
	}
}

void Bomberman::checkBomb()
{
	int	x = 0;
	int	y;
	std::vector<std::vector<char>> &map = getMap();

	map = _map.getMap();
	while (x < 15)
	{
		y = 0;
		while (y < 15)
		{
			if (map[x][y] == '1')
				map[x][y] = '2';
			else if (map[x][y] == '2')
				map[x][y] = '3';
			else if (map[x][y] == '3')
				bombExplode({x, y});
			y++;
		}
		x++;
	}
}

std::string	Bomberman::getSound()
{
	if (_isEnd && !_isWin) {
		_models["player"].rot.x = 90;
		return "media/hero_rise.ogg";
	} else if (_isEnd && _isWin) {
		return "media/hero_win.ogg";
	}
	return "";
}

void	Bomberman::checkGame()
{
	if (!checkPlayer('A')) {
		_guis["dead"].isVisible = true;
		_isEnd = true;
		_isWin = false;
	} else if (!check_b && !check_c && !check_d) {
		_guis["win"].isVisible = true;
		_isEnd = true;
		_isWin = true;
	}
	if (!checkPlayer('B') && check_b) {
		score = score + 100;
		check_b = false;
	}
	if (!checkPlayer('C') && check_c) {
		score = score + 100;
		check_c = false;
	}
	if (!checkPlayer('D') && check_d) {
		score = score + 100;
		check_d = false;
	}
}

void Bomberman::checkEvents(std::pair<int, std::string> &events)
{
	PlayerMove	p('A', _map.getMap());

	checkGame();
	if (!checkPlayer('A'))
		return;
	if (bombDir < 0 || bombDir > 3)
		bombDir = 1;
	p.setBombDir(bombDir);
	if (events.first == KeyCode::KEY_SPACE) {
		p.putBomb();
	}
	if (events.first == KeyCode::KEY_LEFT) {
		bombDir = 3;
		p.moveLeft();
		_models["player"].rot.y = 0;
		if (p.getStatus() == false)
			_models["player"].pos.y = _models["player"].pos.y - 25;
	}
	if (events.first == KeyCode::KEY_UP) {
		bombDir = 0;
		p.moveUp();
		_models["player"].rot.y = 90;
		if (p.getStatus() == false)
			_models["player"].pos.x = _models["player"].pos.x - 25;
	}
	if (events.first == KeyCode::KEY_RIGHT) {
		bombDir = 1;
		p.moveRight();
		_models["player"].rot.y = 180;
		if (p.getStatus() == false)
			_models["player"].pos.y = _models["player"].pos.y + 25;
	}
	if (events.first == KeyCode::KEY_DOWN) {
		bombDir = 2;
		p.moveDown();
		_models["player"].rot.y = -90;
		if (p.getStatus() == false)
			_models["player"].pos.x = _models["player"].pos.x + 25;
	}
}