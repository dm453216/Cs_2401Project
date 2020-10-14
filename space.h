#include<iostream>
#include<list>
#ifndef SPACE_H
#define SPACE_H

class Space{
public:
  Space(){black = king = red = empty = false; unplayable = true;}
  bool is_non_playable()const{return unplayable;}
  bool is_empty()const{return empty;}
  void make_empty(){black = red = king = unplayable = false; empty = true;}
  void make_black(){red = king = unplayable = empty= false;  black = true;}
  void make_red(){black = king = unplayable = empty = false;  red = true;}
  bool is_black()const{return black;}
  bool is_red()const{return red;}
  bool is_king()const{return king;}
  void make_red_king(){black = unplayable = empty = false; red = king = true;}
  void make_black_king(){red = unplayable = empty = false; black =king = true;}

private:
  bool red;
  bool empty;
  bool black;
  bool king;
  bool unplayable;
};
#endif
