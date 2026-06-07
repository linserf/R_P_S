#include"common.h"
#include"strategy.h"
#include<random>
choice RandomStrategy::makechoice() {
	return static_cast<choice>(dist(rng));

}