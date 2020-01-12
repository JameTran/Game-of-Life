#include <vector>
#include <iostream>
#include "CellType.h"
#include "Cell.h"
#include "Game.h"

using namespace std;

Game::Game() {//if no value is inputed, by default create a 15 x 15 grid
  vector<vector<Cell>> q(15); //creates 15 rows (1 x 15 rn)

  for(int i = 0; i < 15; i++){ //add 15 columns of dead cells

    vector<Cell> a(15);
    //fills vector with dead cells
    for(int j = 0; j < 15; j++){
    // Cell temp_cell = Cell(DEAD, 0, i, j);
    a[j] = Cell(DEAD, 0, i, j);
    }
    q[i] = a;
  }
  this->s = q; //sets s to the 15 x 15 matrix
  this->rows = q.size();
  this->cols = q[0].size();
}
Game::Game(vector<vector<Cell>> s){ //takes in vector of vectors
  if(s.size() < 1 || s[0].size() < 1){
    throw invalid_argument("invalid matrix");
  }
  this->s = s;
  this->rows = s.size();
  this->cols = s[0].size();
}
void Game::set_cell(Cell c){
  this->s[c.get_x()][c.get_y()] = c;
}
Cell Game::get_cell(int x, int y){
  if( x < 0 || y < 0 || x > rows || y > cols){
    throw invalid_argument("out of range");
  }
  return s[x][y];
}
int Game::get_rows(){
  return rows;
}
int Game::get_cols(){
  return cols;
}
//Private
vector<vector<Cell>> Game::get_matrix(){
  return this->s;
}

Cell Game::alive_neighbour_cnt(Cell c){
  int alive = 0; //sets alive neighbors to 0
  //checks each neighbor to see if they're alive.
  //IMPORTANT: Leave index checks in front
  if (c.get_x() > 0 && c.get_y() > 0 && (s[c.get_x() - 1][c.get_y() - 1]).get_Alive() == ALIVE){
    alive++;
  }
  if (c.get_y() > 0 && s[c.get_x()][c.get_y() - 1].get_Alive() == ALIVE){
    alive++;
  }
  if (c.get_y() > 0 && c.get_x() < rows - 1 && s[c.get_x() + 1][c.get_y() - 1].get_Alive() == ALIVE){
    alive++;
  }
  if (c.get_x() > 0 && s[c.get_x() - 1][c.get_y()].get_Alive() == ALIVE){
    alive++;
  }
  if (c.get_x() < rows - 1 && s[c.get_x() + 1][c.get_y()].get_Alive() == ALIVE){
    alive++;
  }
  if (c.get_x() > 0 && c.get_y() < cols - 1 && s[c.get_x() - 1][c.get_y() + 1].get_Alive() == ALIVE){
    alive++;
  }
  if (c.get_y() < cols - 1 && s[c.get_x()][c.get_y() + 1].get_Alive() == ALIVE){
    alive++;
  }
  if (c.get_y() < cols - 1 && c.get_x() < rows - 1 && s[c.get_x() + 1][c.get_y() + 1].get_Alive() == ALIVE){
    alive++;
  }
  //Returns an Updated the cell
  Cell temp = Cell(c.get_Alive(), alive, c.get_x(), c.get_y());
  return temp;
}

vector<vector<Cell>> Game::update_all_cnt(){ //helper function, returns an s where all cells cnt values
  // are updated
  vector<vector<Cell>> temp;
  temp = this->s;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      temp[i][j] = this->alive_neighbour_cnt(s[i][j]);
    }
  }
  return temp;
}
Cell Game::update_life(Cell c){ //returns an updated cell, based on cell.alive_cnt.
  Cell temp;
  //if less than 2 alive cells neighbour, cell dies
  if (c.get_cnt() < 2){
    temp = Cell(DEAD, c.get_cnt(), c.get_x(), c.get_y());
  }
  //if more than 3 neighbors, it dies
  else if (c.get_cnt() > 3){
    temp = Cell(DEAD, c.get_cnt(), c.get_x(), c.get_y());
  }
  //if exactly 3 and dead, it becomes alive
  else if (c.get_cnt() == 3 && c.get_Alive() == DEAD){
    temp = Cell(ALIVE, c.get_cnt(), c.get_x(), c.get_y());
  }
  //otherwise, do nothing
  return temp;
}
void Game::update_game(){ //updates the game state
  vector<vector<Cell>> temp = this->update_all_cnt();
  Game g = Game(temp);
  //for every row
  for(int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      //calling member function
      g.set_cell(g.update_life(g.get_cell(i, j)));
    }
  }
  this->s = g.get_matrix();
}

void Game::print_state(){ //prints the current print_state
  cout << endl;
  for(int i = 0; i < cols; i++) { //for each column
    for(int j = 0; j < rows; j++){ //for each element in the row
      if(s[j][i].get_Alive() == ALIVE){
        cout << "X" ;
      }
      else if(s[j][i].get_Alive() == DEAD){
        cout << "O";
      }
    }
    cout << endl;
  }
}
