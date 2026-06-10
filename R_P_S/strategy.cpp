#include"common.h"
#include"strategy.h"
#include<random>
choice RandomStrategy::makechoice(choice lastchoice) {
	return static_cast<choice>(dist(rng));

}
choice WinningStrategy::makechoice(choice lastchoice) {
	if (this->win == true) {
		return this->lastchoice;
	}
	else {
		return static_cast<choice>((static_cast<int>(lastchoice) + 1 )% 3);
	}
}
void WinningStrategy::gamestate(bool kwin,choice klastchoice,choice kcruntchoice) {
	this->win = kwin;
	this->lastchoice = kcruntchoice;
}
void ProbStrategy::gamestate(bool kwin, choice klastchoice, choice kcruntchoice) {
	if (kwin) {
		history[static_cast<int>(klastchoice)][static_cast<int>(kcruntchoice)] += 1;
	}
	else {
		history[static_cast<int>(klastchoice)][(static_cast<int>(kcruntchoice) + 1) % 3] += 1;
		history[static_cast<int>(klastchoice)][(static_cast<int>(kcruntchoice) + 2) % 3] += 1;
	}

}
choice ProbStrategy::makechoice(choice lastchoice) {
	int score = history[static_cast<int>(lastchoice)][0] +
		history[static_cast<int>(lastchoice)][1] +
		history[static_cast<int>(lastchoice)][2];

	if (score == 0) score = 1; // 防止除以0

	std::uniform_int_distribution<int> local_dist(0, score - 1);
	int rand = local_dist(rng);
	int sum = 0;
	for (int i = 0; i < 3; ++i) {
		sum += history[static_cast<int>(lastchoice)][i];
		if (rand < sum) {
			return static_cast<choice>(i);
		}
	}
	return static_cast<choice>(0); // 理论上不会到这里
}