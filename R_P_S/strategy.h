#pragma once

#include"common.h"
#include<random>
class strategy {
public:
	virtual choice makechoice() { return choice::ROCK; }
	virtual void gamestate(bool kwin,choice klastchoice) {}

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
	choice makechoice() override;
};
class WinningSrategy :public strategy {
private:
	bool win;
	choice lastchoice;
public:
	WinningSrategy() : win(true), lastchoice(choice::PAPER){
	}
	choice makechoice() override;
	void gamestate(bool kwin, choice klastchoice) override;
};