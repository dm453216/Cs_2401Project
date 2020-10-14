/*****************************************************
This is a sample of what the main should like for the first phase of the
Checkers game.
	John Dolan	Ohio University		Fall 2018
*************************************************************/
#include<iostream>
#include "checkers.h"
#include "game.h"
#include <string>

using namespace std;
using namespace main_savitch_14;


int main(){
  Checkers mygame;
  game::who winner;
  winner = mygame.play();
  if(winner == game::HUMAN)
  std::cout<< "Player 1 wins";
  else
  std::cout<< "player 2 wins";



return 0;
}
