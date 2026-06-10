#pragma once

#include"common.h"
#include<random>
class strategy {
public:
	virtual choice makechoice(choice lastchoice) { return choice::ROCK; }
	virtual void gamestate(bool kwin,choice klastchoice,choice kcrunntchoice) {}

};
class RandomStrategy :public strategy {
private:
	std::mt19937 rng; // 独立的随机数引擎（梅森旋转算法）
	std::uniform_int_distribution<int> dist; // 均匀分布 [0, 2]
public:
	int random;
	RandomStrategy()
		: rng(std::random_device{}()), dist(0, 2) {
	}
	choice makechoice(choice lastchoice) override;
};
class WinningStrategy :public strategy {
private:
	bool win;
	choice lastchoice;
public:
	WinningStrategy() : win(true), lastchoice(choice::PAPER){
	}
	choice makechoice(choice lastchoice) override;
	void gamestate(bool kwin, choice klastchoice, choice kcruntchoice) override;
};
class ProbStrategy :public strategy {
private:
	std::mt19937 rng; // 独立的随机数引擎（梅森旋转算法）
	std::uniform_int_distribution<int> dist; 
	int history[3][3] = { {1,1,1},{1,1,1},{1,1,1} };
public:
	ProbStrategy() :rng(std::random_device{}()) {

	}
	choice makechoice(choice lastchoice) override;
	void gamestate(bool kwin, choice klastchoice, choice kcrunntchoice);
};