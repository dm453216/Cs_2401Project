#include<iostream>
#include<list>
#include "checkers.h"
#include"colors.h"
#include"space.h"
#include"game.h"

using namespace std;
using namespace main_savitch_14;
 void Checkers::display_status( )const{
   int i;
   int counter =1;
   cout << " A    B   C   D   E   F   G   H " << endl;
    for(int row = 0 ; row < 8; ++row){
      cout << counter;
      ++counter;
     for(int col = 0; col < 8; ++col){
       if(board[row][col].is_empty()){
         cout << B_BLACK << "    ";
       }
       else if(board[row][col].is_non_playable()){
         cout << B_RED << " " << RED << " o ";
       }
       else if(board[row][col].is_black() && board[row][col].is_king()){
         cout << B_BLACK << " " << WHITE << " @ ";
       }
       else if(board[row][col].is_red() && board[row][col].is_king()){
         cout << B_BLACK << " " << RED<< " @ ";
       }
       else if(board[row][col].is_red()){
         cout << B_BLACK << " " <<  RED <<" o ";
       }
       else if(board[row][col].is_black()){
         cout << B_BLACK << " " << WHITE <<" o ";
       }
}
  cout << B_BLACK << endl;
}
cout << B_BLACK << WHITE;
}


void Checkers::restart(){

board[0][1].make_black();
board[0][3].make_black();
board[0][5].make_black();
board[0][7].make_black();
board[1][0].make_black();
board[1][2].make_black();
board[1][4].make_black();
board[1][6].make_black();
board[2][1].make_black();
board[2][3].make_black();
board[2][5].make_black();
board[2][7].make_black();

board[3][0].make_empty();
board[3][2].make_empty();
board[3][4].make_empty();
board[3][6].make_empty();
board[4][1].make_empty();
board[4][3].make_empty();
board[4][5].make_empty();
board[4][7].make_empty();

board[5][0].make_red();
board[5][2].make_red();
board[5][4].make_red();
board[5][6].make_red();
board[6][1].make_red();
board[6][3].make_red();
board[6][5].make_red();
board[6][7].make_red();
board[7][0].make_red();
board[7][2].make_red();
board[7][4].make_red();
board[7][6].make_red();
}


bool Checkers::is_legal(const std::string& move) const{
int x1,y1;
int x2,y2;
int x3,y3;
int pos1x,pos1y;
int pos2x,pos2y;
if(next_mover() == HUMAN){ //red persons turn
  y1 =toupper(move[0])-'A';
  x1 = move[1]-'1'; // have postion of starting point
  y2 = toupper(move[2])-'A';
  x2 = move[3]-'1';
  //x3 = toupper(move[4]) -'A';
//  y3 = move[5]-'1';
  pos1y = y1+1;
  pos1x= x1-1;    // get cordinates of the leagal diagnal square that is up 1 and right
  pos2y = y1 -1;
  pos2x= x1 +1; // get cordinates of the square diagnal up 1 and two the left
  if(board[x1][y1].is_non_playable() || board[x2][y2].is_non_playable()){
    return false;
  }
  if(board[x1][y1].is_black() || board[x2][y2].is_black()){
    return false;
  }
  if(x1-x2 >2){
    return false;
  }
  if((y2 > 7 || x2 > 7) || (y2 < 0 || x2 < 0)){ // check to see if piece jumped of board
    //cout << "You have jumped of board!"<<endl;
    return false;
  }

  bool no_jump = true;

for(int row = 0; row < 8;++row){// finds if possible move to be made for red
  for(int col = 0; col < 8; ++col){
    if(((col<6) && (row>1) && board[row][col].is_red()) && (board[row-1][col+1].is_black() && board[row-2][col+2].is_empty())) { // checks to see if piece has forced move to right, excpt pieces on right side of board
      //  second_jump_legal(move);
      if(x2 ==(row -2) && y2 == (col +2)){
        return true;
      }else{
        no_jump = false;
      }
      }
  if((col> 1) && (row>1) && board[row][col].is_red() && board[row-1][col-1].is_black() && board[row-2][col-2].is_empty()) {// checks for moves up to the left
      if((x2 == (row-2) && y2 == (col-2))) {
        return true;
            }else{
              no_jump = false;
            }
        }
        if( (row < 6 && col >1) && (board[row][col].is_red() && board[row][col].is_king()) && board[row+1][col-1].is_black() && board[row+2][col-2].is_empty()){ // checks moves down and two the right
          if(x2 == (row +2) && y2 == (col-2)){
            return true;
          }else{
            no_jump = false;
          }
        }
        if((row < 6 && row >=0) && (col <6 && col >=0) && (board[row][col].is_red() && board[row][col].is_king()) && board[row +1][col+1].is_black() && board[row+2][col+2].is_empty()){
          if(x2 == (row+2) && y2 ==(col +2)){
            return true;
          }else{
            no_jump = false;
          }
        }
        if( (row < 6 && col >1) && (board[row][col].is_red() && board[row][col].is_king()) && board[row-1][col-1].is_black() && board[row-2][col-2].is_empty()){ // checks moves down and two the right
          if(x2 == (row -2) && y2 == (col-2)){
            return true;
          }else{
            no_jump = false;
          }
        }
        if((row < 6 && row >=0) && (col <6 && col >=0) && (board[row][col].is_red() && board[row][col].is_king()) && board[row -1][col+1].is_black() && board[row-2][col+2].is_empty()){
          if(x2 == (row-2) && y2 ==(col +2)){
            return true;
          }else{
            no_jump = false;

      }
    }
}
}
    // now checked for all possible forced moves

if(no_jump){
    for(int row = 0; row < 8;++row){ // does basic moves
      for(int col = 0; col < 8; ++col){
           //first case of just moving one space diagnal up or down


              if((col< 7 && row >0) && board[row][col].is_red() && board[row-1][col+1].is_empty()){
              if(x2 ==(row -1) && y2 == (col +1)){ // takes care of basic moves of one space
              return true;
            }
          }
            if((col >0 and row >0) && board[row][col].is_red() && board[row-1][col-1].is_empty()){
              if(x2 ==(row-1) && y2 == (col -1)){// takes care of basic moves of one space
              return true;
            }
          }
            if(((row< 7) && (row >=0)) && (col <= 7 && col >0) && (board[row][col].is_red() && board[row][col].is_king()) && board[row+1][col-1].is_empty()){ // checks moves down and two the right
              if(x2 == (row +1) && y2 == (col-1)){
                return true;

              }
            }

            if(((row < 7) && row >=0) && ((col < 7) && col >=0) && (board[row][col].is_red() && board[row][col].is_king()) && board[row +1][col+1].is_empty()) {
              if(x2 == (row+1) && y2 ==(col +1)){
                return true;
              }
            }
            if(((row< 7) && (row >=0)) && (col <= 7 && col >0) && (board[row][col].is_red() && board[row][col].is_king()) && board[row-1][col-1].is_empty()){ // checks moves down and two the right
              if(x2 == (row -1) && y2 == (col-1)){
                return true;

              }
            }

            if(((row < 7) && row >=0) && ((col < 7) && col >=0) && (board[row][col].is_red() && board[row][col].is_king()) && board[row -1][col+1].is_empty()) {
              if(x2 == (row-1) && y2 ==(col +1)){
                return true;
          }

}
}
}


    return false;
}






}else { // Black piece turn
  y1 = toupper(move[0])-'A';
  x1 = move[1]-'1'; // have postion of starting point
  y2 = toupper(move[2])-'A';
  x2 = move[3]-'1'; // have postion of where you want to jump
  pos1y = y1-1;
  pos1x= x1+1;    // get cordinates of the leagal diagnal square that is up 1 and left
  pos2y = y2 +1;
  pos2x= x2 +1; // get cordinates of the square diagnal up 1 and two the right
   if(board[x1][y1].is_red()|| board[x2][y2].is_red()){
    return false;
  }
   if(board[x1][y1].is_non_playable() || board[x2][y2].is_non_playable()){
      return false;
    }
  if((y2 > 7 || x2 > 7) || (y2 < 0 || x2 < 0)){ // check to see if piece jumped of board
    //cout << "You have jumped of board!"<<endl;
    return false;
  }

  bool no_jumps = true;
  for(int row = 0; row < 8;++row){ // finds if possible move to be made for red
    for(int col = 0; col < 8; ++col){

      if(((col<6) && (row<6) && board[row][col].is_black()) && (board[row+1][col+1].is_red() && board[row+2][col+2].is_empty())) { // checks to see if piece has forced move to right, excpt pieces on right side of board
        if(x2 ==(row +2) && y2 == (col +2)){
          return true;
        }else{
        no_jumps = false;
        }
        }
    if((col> 1 && row<6) && board[row][col].is_black() && board[row+1][col-1].is_red() && board[row+2][col-2].is_empty()) {// checks for moves down to the left
        if((x2 == (row+2) && y2 == (col-2))) {
          return true;
              }else{
                no_jumps = false;
              }
          }
          if( (row > 2 && col <6) && (board[row][col].is_black() && board[row][col].is_king()) && board[row+1][col+1].is_red() && board[row+2][col+2].is_empty()){ // checks moves up and two the right
            if(x2 == (row +2) && y2 == (col +2)){
              return true;
            }else{
              no_jumps = false;
            }
          }
          if((row >2 && row <= 7) && (col >2 && col <= 7) && (board[row][col].is_black() && board[row][col].is_king()) && board[row +1][col-1].is_red() && board[row+2][col-2].is_empty()){//checks up and two left
            if(x2 == (row+2) && y2 ==(col -2)){
              return true;
            }else{
              no_jumps = false;
            }
          }
          if( (row > 2 && col <6) && (board[row][col].is_black() && board[row][col].is_king()) && board[row-1][col+1].is_red() && board[row-2][col+2].is_empty()){ // checks moves up and two the right
            if(x2 == (row -2) && y2 == (col +2)){
              return true;
            }else{
              no_jumps = false;
            }
          }
          if((row >2 && row <= 7) && (col >2 && col <= 7) && (board[row][col].is_black() && board[row][col].is_king()) && board[row -1][col-1].is_red() && board[row-2][col-2].is_empty()){//checks up and two left
            if(x2 == (row-2) && y2 ==(col -2)){
              return true;
            }else{
              no_jumps = false;
        }

    }
  }
}
        // covers all possible forced moves
       if(no_jumps){
        for(int row = 0; row < 8;++row){ // does basic moves
          for(int col = 0; col < 8; ++col){
               //first case of just moving one space diagnal up or down


                  if((col <7 && row <7) && board[row][col].is_black() && board[row+1][col+1].is_empty()){
                  if(x2 ==(row +1) && y2 == (col +1)){ // takes care of basic moves of one space
                  return true;
                }
              }
                if((col >0 && row <7) && board[row][col].is_black() && board[row+1][col-1].is_empty()){
                  if(x2 ==(row+1) && y2 == (col -1)){// takes care of basic moves of one space
                  return true;
                }
              }
                if((row > 0)  && (col > 0 && col <= 7) && (board[row][col].is_black() && board[row][col].is_king()) && board[row-1][col-1].is_empty()){ // checks moves down and two the right
                  if(x2 == (row -1) && y2 == (col-1)){
                    return true;

                  }
                }

                if(((row > 0) && row <= 7) && ((col >= 0) && col < 7 ) && (board[row][col].is_black() && board[row][col].is_king()) && board[row -1][col+1].is_empty()) {
                  if(x2 == (row-1) && y2 ==(col +1)){
                    return true;
                  }
                }
                if((row > 0)  && (col > 0 && col <= 7) && (board[row][col].is_black() && board[row][col].is_king()) && board[row+1][col-1].is_empty()){ // checks moves down and two the right
                  if(x2 == (row +1) && y2 == (col-1)){
                    return true;

                  }
                }

                if(((row > 0) && row <= 7) && ((col >= 0) && col < 7 ) && (board[row][col].is_black() && board[row][col].is_king()) && board[row +1][col+1].is_empty()) {
                  if(x2 == (row+1) && y2 ==(col +1)){
                    return true;
              }
            }
}
}
}

        return false;


}


}






void Checkers::make_move(const std::string& move){
  int y1;
  int x1;
  int x2;
  int y2;
  int erase_x,erase_y;
  if(next_mover()==HUMAN){
  y1 = toupper(move[0])-'A';
  x1 = move[1]-'1';
  y2 = toupper(move[2])-'A';
  x2 = move[3]-'1';
  erase_x = (x1 + x2)/2;
  erase_y = (y1+y2)/2;
  if(board[x1][y1].is_red() && board[x1][y1].is_king()){
    if((x1+x2)%2 == 0 && (y1+y2)%2== 0){
      board[erase_x][erase_y].make_empty();
      board[x2][y2].make_red_king();
      board[x1][y1].make_empty();
  }else{
    board[x2][y2].make_red_king();
    board[x1][y1].make_empty();
  }
    }else{
    if((x1+x2)%2 == 0 && (y1+y2)%2== 0){
      if(x2 == 0){
        board[erase_x][erase_y].make_empty();
        board[x2][y2].make_red_king();
        board[x1][y1].make_empty();
      }else{
      board[erase_x][erase_y].make_empty();
      board[x2][y2].make_red();
      board[x1][y1].make_empty();
    }
  }else{
    if(x2 == 0){
      board[x2][y2].make_red_king();
      board[x1][y1].make_empty();
    }else{
    board[x2][y2].make_red();
    board[x1][y1].make_empty();
  }
}
}
}else{

  y1 = toupper(move[0])-'A';
  x1 = move[1]-'1';
  y2 = toupper(move[2])-'A';
  x2 = move[3]-'1';
  erase_x = (x1 + x2)/2;
  erase_y = (y1+y2)/2;
  if(board[x1][y1].is_black() && board[x1][y1].is_king()){
    if((x1+x2)%2 == 0 && (y1+y2)%2== 0){
      board[erase_x][erase_y].make_empty();
      board[x2][y2].make_black_king();
      board[x1][y1].make_empty();

  }else{
    board[x2][y2].make_black_king();
    board[x1][y1].make_empty();
  }

}else{
  if((x1+x2)%2 == 0 && (y1+y2)%2== 0){
    if(x2 == 7){
      board[erase_x][erase_y].make_empty();
      board[x2][y2].make_black_king();
      board[x1][y1].make_empty();
    }else{
    board[erase_x][erase_y].make_empty();
    board[x2][y2].make_black();
    board[x1][y1].make_empty();
  }
  }else{
   if(x2 == 7){
   board[x2][y2].make_black_king();
   board[x1][y1].make_empty();
}else{
  board[x2][y2].make_black();
  board[x1][y1].make_empty();
}
}
}
}



game::make_move(move);
}
 bool Checkers::is_game_over( ) const{
   int red_pieces = 0;
   int black_pieces = 0;

   for(int row = 0; row <8;++row){
     for(int col=0; col<8; ++col){
       if(board[row][col].is_red()){
         red_pieces++;
       }else if(board[row][col].is_black()){
         black_pieces++;
       }
     }
   }

   if(red_pieces == 0 || black_pieces == 0){
     return true;
   }else{
     return false;
   }
 }


/*
bool Checkers:: second_jump_legal(const std::string& move)const{
bool no_sec_jump;
int x3,y3;
bool no_sec_jumps = true;
x3 = toupper(move[4]) -'A';
y3 = move[5]-'1';
for(int row; row < 8;++row){// finds if possible move to be made for red
 for(int col; col < 8; ++col){
   if(((col<6) && (row>1) && board[row][col].is_red()) && (board[row-1][col+1].is_black() && board[row-2][col+2].is_empty())) { // checks to see if piece has forced move to right, excpt pieces on right side of board
     if(x3==(row -2) && y3== (col +2)){
       return true;
     }else{
       no_sec_jumps= false;
     }
     }
 if((col> 1) && (row>1) && board[row][col].is_red() && board[row-1][col-1].is_black() && board[row-2][col-2].is_empty()) {// checks for moves up to the left
     if((x3 == (row-2) && y3 == (col-2))) {
       return true;
           }else{
             no_sec_jumps= false;
           }
       }
       if( (row < 6 && col >1) && (board[row][col].is_red() && board[row][col].is_king()) && board[row+1][col-1].is_black() && board[row+2][col-2].is_empty()){ // checks moves down and two the right
         if(x3 == (row +2) && y3 == (col-2)){
           return true;
         }else{
           no_sec_jumps = false;
         }
       }
       if((row < 6 && row >=0) && (col <6 && col >=0) && (board[row][col].is_red() && board[row][col].is_king()) && board[row +1][col+1].is_black() && board[row+2][col+2].is_empty()){
         if(x3 == (row+2) && y3 ==(col +2)){
           return true;
         }else{
           no_sec_jumps = false;
         }
       }

     }
   }
}
*/
   // now checked for all possible forced moves
   void Checkers::compute_moves(std::queue<std::string>& moves) const{
     int x1,x2,y1,y2;
     string tmp = "";
     bool no_jump = false;
     if(next_mover() == HUMAN){ //red persons turn
       bool no_jump = false;
       for(int row = 0; row < 8;++row){// finds if possible move to be made for red
         for(int col = 0; col < 8; ++col){
       if(!(board[row][col].is_non_playable() || board[row][col].is_non_playable() || board[row][col].is_black() || board[row][col].is_black())) {
         if(((col<6) && (row>1) && board[row][col].is_red()) && (board[row-1][col+1].is_black() && board[row-2][col+2].is_empty())) { // checks to see if piece has forced move to right, excpt pieces on right side of board

           y1 = static_cast<char>(col+'A');
           x1 = static_cast<char>(row+'1');
           y2 = static_cast<char>((col+2)+'A');
           x2 = static_cast<char>((row-2) +'1');
           tmp +=y1;
           tmp+= x1;
           tmp += y2;
           tmp += x2;
           moves.push(tmp);
           tmp = "";
           no_jump = true;
           }

       else if((col> 1) && (row>1) && board[row][col].is_red() && board[row-1][col-1].is_black() && board[row-2][col-2].is_empty()) {// checks for moves up to the left
         y1 = static_cast<char>(col+'A');
         x1 = static_cast<char>(row+'1');
         y2 = static_cast<char>((col-2)+'A');
         x2 = static_cast<char>((row-2) +'1');
         tmp +=y1;
         tmp+= x1;
         tmp += y2;
         tmp += x2;
         moves.push(tmp);
         tmp = "";
         no_jump = true;

                 }



             else if( (row < 6 && col >1) && (board[row][col].is_red() && board[row][col].is_king()) && board[row+1][col-1].is_black() && board[row+2][col-2].is_empty()){ // checks moves down and two the right
               y1 = static_cast<char>(col+'A');
               x1 = static_cast<char>(row+'1');
               y2 = static_cast<char>((col-2)+'A');
               x2 = static_cast<char>((row+2) +'1');
               tmp +=y1;
               tmp+= x1;
               tmp += y2;
               tmp += x2;
               moves.push(tmp);
               tmp = "";
               no_jump = true;
                               }

            else if((row< 6 && row >=0) && (col <6 && col >=0) && (board[row][col].is_red() && board[row][col].is_king()) && board[row +1][col+1].is_black() && board[row+2][col+2].is_empty()){
               y1 = static_cast<char>(col+'A');
               x1 = static_cast<char>(row+'1');
               y2 = static_cast<char>((col+2)+'A');
               x2 = static_cast<char>((row+2) +'1');
               tmp +=y1;
               tmp+= x1;
               tmp += y2;
               tmp += x2;
               moves.push(tmp);
               tmp = "";
               no_jump = true;
               }
            else  if( (row < 6 && col >1) && (board[row][col].is_red() && board[row][col].is_king()) && board[row-1][col-1].is_black() && board[row-2][col-2].is_empty()){ // checks moves down and two the right
               y1 = static_cast<char>(col+'A');
               x1 = static_cast<char>(row+'1');
               y2 = static_cast<char>((col-2)+'A');
               x2 = static_cast<char>((row-2) +'1');
               tmp +=y1;
               tmp+= x1;
               tmp += y2;
               tmp += x2;
               moves.push(tmp);
               tmp = "";
               no_jump = true;
               }

             else if((row < 6 && row >=0) && (col <6 && col >=0) && (board[row][col].is_red() && board[row][col].is_king()) && board[row -1][col+1].is_black() && board[row-2][col+2].is_empty()){
               y1 = static_cast<char>(col+'A');
               x1 = static_cast<char>(row+'1');
               y2 = static_cast<char>((col+2)+'A');
               x2 = static_cast<char>((row -2) +'1');
               tmp +=y1;
               tmp+= x1;
               tmp += y2;
               tmp += x2;
               moves.push(tmp);
               tmp = "";
               no_jump = true;
          }
}
}
}

         // now checked for all possible forced moves

     if(no_jump == false){
         for(int row = 0; row < 8;++row){ // does basic moves
           for(int col = 0; col < 8; ++col){
                //first case of just moving one space diagnal up or down
                if(!(board[row][col].is_non_playable() || board[row][col].is_non_playable() || board[row][col].is_black() || board[row][col].is_black())){

                   if((col< 7 && row >0) && board[row][col].is_red() && board[row-1][col+1].is_empty()){
                     y1 = static_cast<char>(col+'A');
                     x1 = static_cast<char>(row+'1');
                     y2 = static_cast<char>((col+1)+'A');
                     x2 = static_cast<char>((row -1) +'1');
                     tmp +=y1;
                     tmp+= x1;
                     tmp += y2;
                     tmp += x2;
                     moves.push(tmp);
                     tmp = "";
                 }

                 if((col >0 and row >0) && board[row][col].is_red() && board[row-1][col-1].is_empty()){
                   y1 = static_cast<char>(col+'A');
                   x1 = static_cast<char>(row+'1');
                   y2 = static_cast<char>((col-1)+'A');
                   x2 = static_cast<char>((row-1) +'1');
                   tmp +=y1;
                   tmp+= x1;
                   tmp += y2;
                   tmp += x2;
                   moves.push(tmp);
                   tmp = "";
               }
                 if(((row< 7) && (row >=0)) && (col <= 7 && col >0) && (board[row][col].is_red() && board[row][col].is_king()) && board[row+1][col-1].is_empty()){ // checks moves down and two the right
                   y1 = static_cast<char>(col+'A');
                   x1 = static_cast<char>(row+'1');
                   y2 = static_cast<char>((col-1)+'A');
                   x2 = static_cast<char>((row+1) +'1');
                   tmp +=y1;
                   tmp+= x1;
                   tmp += y2;
                   tmp += x2;
                   moves.push(tmp);
                   tmp = "";


                 }

                 if(((row < 7) && row >=0) && ((col < 7) && col >=0) && (board[row][col].is_red() && board[row][col].is_king()) && board[row +1][col+1].is_empty()) {
                   y1 = static_cast<char>(col+'A');
                   x1 = static_cast<char>(row+'1');
                   y2 = static_cast<char>((col+1)+'A');
                   x2 = static_cast<char>((row +1) +'1');
                   tmp +=y1;
                   tmp+= x1;
                   tmp += y2;
                   tmp += x2;
                   moves.push(tmp);
                   tmp = "";


                 }
                 if(((row< 7) && (row >=0)) && (col <= 7 && col >0) && (board[row][col].is_red() && board[row][col].is_king()) && board[row-1][col-1].is_empty()){ // checks moves down and two the right
                   y1 = static_cast<char>(col+'A');
                   x1 = static_cast<char>(row+'1');
                   y2 = static_cast<char>((col-1)+'A');
                   x2 = static_cast<char>((row -1) +'1');
                   tmp +=y1;
                   tmp+= x1;
                   tmp += y2;
                   tmp += x2;
                   moves.push(tmp);
                   tmp = "";
                   }


                 if(((row < 7) && row >=0) && ((col < 7) && col >=0) && (board[row][col].is_red() && board[row][col].is_king()) && board[row -1][col+1].is_empty()) {
                   y1 = static_cast<char>(col+'A');
                   x1 = static_cast<char>(row+'1');
                   y2 = static_cast<char>((col+1)+'A');
                   x2 = static_cast<char>((row -1) +'1');
                   tmp +=y1;
                   tmp+= x1;
                   tmp += y2;
                   tmp += x2;
                   moves.push(tmp);
                   tmp = "";
               }


}

}
   }
}
     }else { // Black piece turn
       bool no_jumps = false;
         for(int row = 0; row < 8; ++row){
           for(int col = 0;col < 8; ++col){
             if(!(board[row][col].is_non_playable() || board[row][col].is_non_playable()||board[row][col].is_red() || board[row][col].is_red() )) {


           if(((col<6) && (row<6) && board[row][col].is_black()) && (board[row+1][col+1].is_red() && board[row+2][col+2].is_empty())) { // checks to see if piece has forced move to right, excpt pieces on right side of board
             y1 = static_cast<char>(col+'A');
             x1 = static_cast<char>(row+'1');
             y2 = static_cast<char>((col+2)+'A');
             x2 = static_cast<char>((row+2) +'1');
             tmp +=y1;
             tmp+= x1;
             tmp += y2;
             tmp += x2;
             moves.push(tmp);
             tmp = "";
             no_jumps = true;
           }
        else if((col> 1 && row<6) && board[row][col].is_black() && board[row+1][col-1].is_red() && board[row+2][col-2].is_empty()) {// checks for moves down to the left
           y1 = static_cast<char>(col +'A');
           x1 = static_cast<char>(row+'1');
           y2 = static_cast<char>((col-2)+'A');
           x2 = static_cast<char>((row+2) +'1');
           tmp +=y1;
           tmp+= x1;
           tmp += y2;
           tmp += x2;
           moves.push(tmp);
           tmp = "";
           no_jumps = true;
               }
               else if( (row > 2 && col <6) && (board[row][col].is_black() && board[row][col].is_king()) && board[row+1][col+1].is_red() && board[row+2][col+2].is_empty()){ // checks moves up and two the right
                 y1 = static_cast<char>(col +'A');
                 x1 = static_cast<char>(row+'1');
                 y2 = static_cast<char>((col+2)+'A');
                 x2 = static_cast<char>((row+2) +'1');
                 tmp +=y1;
                 tmp+= x1;
                 tmp += y2;
                 tmp += x2;
                 moves.push(tmp);
                 tmp = "";
                 no_jumps = true;
               }
               else if((row >2 && row <= 7) && (col >2 && col <= 7) && (board[row][col].is_black() && board[row][col].is_king()) && board[row +1][col-1].is_red() && board[row+2][col-2].is_empty()){//checks up and two left
                 y1 = static_cast<char>(col +'A');
                 x1 = static_cast<char>(row+'1');
                 y2 = static_cast<char>((col-2)+'A');
                 x2 = static_cast<char>((row+2) +'1');
                 tmp +=y1;
                 tmp+= x1;
                 tmp += y2;
                 tmp += x2;
                 moves.push(tmp);
                 tmp = "";
                 no_jumps = true;

               }
               else if( (row > 2 && col <6) && (board[row][col].is_black() && board[row][col].is_king()) && board[row-1][col+1].is_red() && board[row-2][col+2].is_empty()){ // checks moves up and two the right
                 y1 = static_cast<char>(col +'A');
                 x1 = static_cast<char>(row+'1');
                 y2 = static_cast<char>((col+2)+'A');
                 x2 = static_cast<char>((row-2) +'1');
                 tmp +=y1;
                 tmp+= x1;
                 tmp += y2;
                 tmp += x2;
                 moves.push(tmp);
                 tmp = "";
                 no_jumps = true;

               }
              else if((row >2 && row <= 7) && (col >2 && col <= 7) && (board[row][col].is_black() && board[row][col].is_king()) && board[row -1][col-1].is_red() && board[row-2][col-2].is_empty()){//checks up and two left
                 y1 = static_cast<char>(col +'A');
                 x1 = static_cast<char>(row+'1');
                 y2 = static_cast<char>((col-2)+'A');
                 x2 = static_cast<char>((row-2) +'1');
                 tmp +=y1;
                 tmp+= x1;
                 tmp += y2;
                 tmp += x2;
                 moves.push(tmp);
                 tmp = "";
                 no_jumps = true;


        }
      }
       }
     }
             // covers all possible forced moves
            if(no_jumps == false){
             for(int row = 0; row < 8;++row){ // does basic moves
               for(int col = 0; col < 8; ++col){
                    //first case of just moving one space diagnal up or down
                     if(!(board[row][col].is_non_playable() || board[row][col].is_non_playable()||board[row][col].is_red() || board[row][col].is_red())) {

                       if((col <7 && row <7) && board[row][col].is_black() && board[row+1][col+1].is_empty()){
                         y1 = static_cast<char>(col +'A');
                         x1 = static_cast<char>(row+'1');
                         y2 = static_cast<char>((col+1)+'A');
                         x2 = static_cast<char>((row+1) +'1');
                         tmp +=y1;
                         tmp+= x1;
                         tmp += y2;
                         tmp += x2;
                         moves.push(tmp);
                         tmp = "";


                   }
                     if((col >0 && row <7) && board[row][col].is_black() && board[row+1][col-1].is_empty()){
                       y1 = static_cast<char>(col +'A');
                       x1 = static_cast<char>(row+'1');
                       y2 = static_cast<char>((col-1)+'A');
                       x2 = static_cast<char>((row+1) +'1');
                       tmp +=y1;
                       tmp+= x1;
                       tmp += y2;
                       tmp += x2;
                       moves.push(tmp);
                       tmp = "";


                   }
                     if((row > 0)  && (col > 0 && col <= 7) && (board[row][col].is_black() && board[row][col].is_king()) && board[row-1][col-1].is_empty()){ // checks moves down and two the right
                       y1 = static_cast<char>(col +'A');
                       x1 = static_cast<char>(row+'1');
                       y2 = static_cast<char>((col-1)+'A');
                       x2 = static_cast<char>((row-1) +'1');
                       tmp +=y1;
                       tmp+= x1;
                       tmp += y2;
                       tmp += x2;
                       moves.push(tmp);
                       tmp = "";



                     }

                     if(((row > 0) && row <= 7) && ((col >= 0) && col < 7 ) && (board[row][col].is_black() && board[row][col].is_king()) && board[row -1][col+1].is_empty()) {
                       y1 = static_cast<char>(col +'A');
                       x1 = static_cast<char>(row+'1');
                       y2 = static_cast<char>((col+1)+'A');
                       x2 = static_cast<char>((row-1) +'1');
                       tmp +=y1;
                       tmp+= x1;
                       tmp += y2;
                       tmp += x2;
                       moves.push(tmp);
                       tmp = "";


                     }
                     if((row > 0)  && (col > 0 && col <= 7) && (board[row][col].is_black() && board[row][col].is_king()) && board[row+1][col-1].is_empty()){ // checks moves down and two the right
                       y1 = static_cast<char>(col +'A');
                       x1 = static_cast<char>(row+'1');
                       y2 = static_cast<char>((col-1)+'A');
                       x2 = static_cast<char>((row+1) +'1');
                       tmp +=y1;
                       tmp+= x1;
                       tmp += y2;
                       tmp += x2;
                       moves.push(tmp);
                       tmp = "";


                     }

                     if(((row > 0) && row <= 7) && ((col >= 0) && col < 7 ) && (board[row][col].is_black() && board[row][col].is_king()) && board[row +1][col+1].is_empty()) {
                       y1 = static_cast<char>(col +'A');
                       x1 = static_cast<char>(row+'1');
                       y2 = static_cast<char>((col+1)+'A');
                       x2 = static_cast<char>((row+1) +'1');
                       tmp +=y1;
                       tmp+= x1;
                       tmp += y2;
                       tmp += x2;
                       moves.push(tmp);
                       tmp = "";

                   }
                 }
               }
             }
           }
         }
       }

    int Checkers:: evaluate( )const{
     int score = 0;
     int red_score = 0;
     int black_score =0;
     int king = 3;
     int pawn = 3;

    for(int row = 0; row < 8; ++row){
      for(int col = 0; col < 8; ++col){
      if(board[row][col].is_red()){
        red_score = red_score + pawn;
      }
      if(board[row][col].is_red() &&board[row][col].is_king()){
        red_score = red_score +king;
      }
      if(board[row][col].is_black()){
        black_score = black_score +pawn;
    }
    if(board[row][col].is_black() && board[row][col].is_king()){
      black_score = black_score +king;
    }
  }
}
    score = black_score - red_score;
    return score;
    }
