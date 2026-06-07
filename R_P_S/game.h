#pragma once


#include"strategy.h"
class game {
private:
	std::unique_ptr<strategy> player1;
	std::unique_ptr<strategy> player2;
	friend win operator>(choice p1,choice p2);
public:
	game();
	void play();
	void run(int rounds);
};