#include <vector>
#include <iostream>
#include "CellType.h"
#include "Cell.h"

using namespace std;

Cell::Cell(){
  this->s = DEAD;
  cnt = 0;
  x = 0;
  y = 0;
}
Cell::Cell(LifeT s, int cnt, int x, int y){
    if(cnt < 0){
      throw out_of_range("cnt must be higher than zero");
    }
    if(x < 0){
      throw out_of_range("x must be higher than zero");
    }
    if(y < 0){
      throw out_of_range("y must be higher than zero");
    }

    this->s = s;
    this->cnt = cnt;
    this->x = x;
    this->y = y;
}
LifeT Cell::get_Alive(){
    return s;
}
int Cell::get_cnt(){
    return cnt;
  }
int Cell::get_x(){
  return x;
}
int Cell::get_y(){
  return y;
}
