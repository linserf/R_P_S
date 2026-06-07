#include"game.h"
#include"strategy.h"
#include"common.h"
#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
game::game():player1(std::make_unique<RandomStrategy>()), player2(std::make_unique < RandomStrategy>()){}
win operator>(choice p1,choice p2) {
	if (p1 == p2) {
		return win::tie;
	}
	if ((static_cast<int>(p1) + 1) % 3 == static_cast<int>(p2)) {
		return win::p1win;
	}
	else {
		return win::p2win;
	}

}
void game::play() {
	std::string PlayerChoice;
	std::cout << "Please enter your choice" << std::endl;
	std::cin >> PlayerChoice;
	std::transform(PlayerChoice.begin(), PlayerChoice.end(), PlayerChoice.begin(), [](unsigned char c) {
		return std::toupper(c); });
	choice c1 = StringtoChoice(PlayerChoice);
	choice c2 = player1->makechoice();
	win w = c1 > c2;
	std::string WhoWin;
	switch (w) {
	case win::p1win:WhoWin = "you win!"; break;
	case win::p2win:WhoWin = "you lose!"; break;
	case win::tie:WhoWin = "tie!"; break;
	}
	std::cout << "Your opponent's choice is " << ChoicetoString(c2) << " ," << WhoWin << std::endl;
}