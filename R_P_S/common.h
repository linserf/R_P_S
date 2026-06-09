#pragma once
#include<iostream>
#include<string>
#include<stdexcept>
enum class choice {
	ROCK, PAPER, SCISSORS
};
enum class win
{
	p1win, p2win, tie
};
inline std::string ChoicetoString(choice c) {
	switch (c) {
	case choice::ROCK: return "ROCK"; break;
	case choice::PAPER: return "PAPER"; break;
	case choice::SCISSORS: return "SCISSORS"; break;
	}
}
inline choice StringtoChoice(std::string s) {
	if (s == "ROCK")return choice::ROCK;
	if (s == "PAPER") return choice::PAPER;
	if (s == "SCISSORS") return choice::SCISSORS;
	throw std::invalid_argument("Invalid input!Please enter rock, paper, or scissors.");
	

}
