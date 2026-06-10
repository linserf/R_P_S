#include"game.h"
#include<string>
#include<iostream>
#include<algorithm>
int main() {
	int round = 1;
	bool isRun = true;
	std::string replay;
	strategy* p1 = new ProbStrategy;
	strategy* p2 = new RandomStrategy;
	game g(p1, p2);
	//while (isRun) {
	//	g.play();
	//	round++;
	//	std::cout << "Do you want to play again?   " << "T/N" << std::endl;
	//	std::cin >> replay;
	//	if (replay =="T"|| replay == "t") {
	//		isRun = true;
	//	}
	//	else {
	//		isRun = false;
	//	}
	//}
	//std::cout << round << " roumds played:\nPlayer 1 won: " << std::count(g.scoreBoard.begin(), g.scoreBoard.end(), win::p1win) << "\nPlayer 2 won: " << std::count(g.scoreBoard.begin(), g.scoreBoard.end(), win::p2win) << "\ntie:" << std::count(g.scoreBoard.begin(), g.scoreBoard.end(), win::tie) << std::endl;
	while (isRun) {
		g.scoreBoard.clear();
		g.run(10000);
		std::cout << "Do you want to play again?   " << "T/N" << std::endl;
		std::cin >> replay;
		if (replay == "T" || replay == "t") {
			isRun = true;
		}
		else {
			isRun = false;
		}
	}
	return 0;
}