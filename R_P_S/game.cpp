#include"game.h"
#include"strategy.h"
#include"common.h"
#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
#include<vector>
game::game(strategy* s1, strategy* s2) {
	player1 = s1,player2 = s2;
}
win operator>(choice p1,choice p2) {
	if (p1 == p2) {
		return win::tie;
	}
	if ((static_cast<int>(p1) + 1) % 3 == static_cast<int>(p2)) {
		return win::p2win;
	}
	else {
		return win::p1win;
	}

}
void game::play() {
	bool validInput;
	choice c1=choice::PAPER;
	std::string PlayerChoice;
		do {
			validInput = true;
			std::cout << "Please enter your choice" << std::endl;
			std::cin >> PlayerChoice;
			std::transform(PlayerChoice.begin(), PlayerChoice.end(), PlayerChoice.begin(), [](unsigned char c) {
				return std::toupper(c); });
			try {
				c1=StringtoChoice(PlayerChoice);
			}
			catch (const std::invalid_argument& e) {
				std::cout << e.what() << std::endl;
				validInput = false;

			}
		} while (!validInput);
	c2l = c2c;
	c2c = player1->makechoice(c2l);
	win w = c1 > c2c;
	player1->gamestate(static_cast<bool>(w), c2l,c2c);
	std::string WhoWin;
	scoreBoard.push_back(w);
	switch (w) {
	case win::p1win:WhoWin = "you win!"; break;
	case win::p2win:WhoWin = "you lose!"; break;
	case win::tie:WhoWin = "tie!"; break;
	}
	std::cout << "Your opponent's choice is " << ChoicetoString(c2c) << " ," << WhoWin << std::endl;
}
void game::run(int round) {
	win w;
	for(int i=0;i<round;i++) {
		c1l = c1c;
		c2l = c2c;
		c1c = player1->makechoice(c1l);
		c2c = player2->makechoice(c2l);
		w = c1c > c2c;
		player1->gamestate(!static_cast<bool>(w), c1l,c1c);
		player1->gamestate(static_cast<bool>(w), c2l,c2c);
		scoreBoard.push_back(w);

	}
	std::cout << round << " roumds played:\nPlayer 1 won: " << std::count(scoreBoard.begin(), scoreBoard.end(), win::p1win) << "\nPlayer 2 won: " << std::count(scoreBoard.begin(), scoreBoard.end(), win::p2win) << "\ntie:" << std::count(scoreBoard.begin(), scoreBoard.end(), win::tie)<<std::endl;
}