#include<iostream>
#include<list>
#include<queue>
#include "space.h"
#include"game.h"
#ifndef CHECKERS_H
#define CHECKERS_H

using namespace main_savitch_14;

class Checkers:public game{
public:
Checkers(){restart();}
 int evaluate( ) const;
 bool is_game_over( ) const;
 void compute_moves(std::queue<std::string>& moves) const;
 void display_status( )const;
 bool is_legal(const std::string& move) const;
game* clone( ) const {return new Checkers(*this);}
 void make_move(const std::string& move);
 bool second_jump_legal(const std::string& move)const;
  // Restart the game from the beginning:
 void restart();
private:
  Space board [8][8];
};
#endif
