#pragma once


#include"strategy.h"
class game {
private:
	strategy* player1;
	strategy* player2;
	friend win operator>(choice p1,choice p2);
	choice c1l, c1c, c2l, c2c;
public:
	std::vector<win> scoreBoard;
	game(strategy* s1,strategy* s2);
	void play();
	void run(int rounds);
};