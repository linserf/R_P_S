#include"game.h"
int main(){
	strategy* p1 = new RandomStrategy;
	strategy* p2 = new RandomStrategy;
	game g(p1, p2);
	g.play();
}