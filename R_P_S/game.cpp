#include"game.h"
#include"strategy.h"
#include"common.h"
#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
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
	bool validInput=false;
	choice c1=choice::PAPER;
	std::string PlayerChoice;
		while (!validInput) {
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
		}
	choice c2 = player1->makechoice();
	win w = c1 > c2;
	player1->gamestate(static_cast<bool>(w), c2);
	std::string WhoWin;
	switch (w) {
	case win::p1win:WhoWin = "you win!"; break;
	case win::p2win:WhoWin = "you lose!"; break;
	case win::tie:WhoWin = "tie!"; break;
	}
	std::cout << "Your opponent's choice is " << ChoicetoString(c2) << " ," << WhoWin << std::endl;
}