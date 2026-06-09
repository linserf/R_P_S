#include"common.h"
#include"strategy.h"
#include<random>
choice RandomStrategy::makechoice() {
	return static_cast<choice>(dist(rng));

}
choice WinningSrategy::makechoice() {
	if (this->win == true) {
		return this->lastchoice;
	}
	else {
		return static_cast<choice>((static_cast<int>(lastchoice) + 1 )% 3);
	}
}
void WinningSrategy::gamestate(bool kwin,choice klastchoice) {
	this->win = kwin;
	this->lastchoice = klastchoice;
}