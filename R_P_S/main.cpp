#include"game.h"
#include<string>
int main(){
	bool isRun = true;
	std::string replay;
	while (isRun) {
		strategy* p1 = new WinningSrategy;
		strategy* p2 = new WinningSrategy;
		game g(p1, p2);
		g.play();
		std::cout << "Do you want to play again?   " << "T/N" << std::endl;
		std::cin >> replay;
		if (replay =="T"|| replay == "t") {
			isRun = true;
		}
		else {
			isRun = false;
		}
	}
	return 0;
}