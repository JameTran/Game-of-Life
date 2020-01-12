#include <vector>
#include <iostream>
#include "CellType.h"

using namespace std;

class Cell{
private:
  LifeT s;
  int cnt;
  int x;
  int y;

public:
  Cell(){
    this->s = DEAD;
    cnt = 0;
    x = 0;
    y = 0;
  }
  Cell(LifeT s, int cnt, int x, int y){
    this->s = s;
    this->cnt = cnt;
    this->x = x;
    this->y = y;
  }
  LifeT get_Alive(){
    return s;
  }
  int get_cnt(){
    return cnt;
  }
  int get_x(){
    return x;
  }
  int get_y(){
    return y;
  }
  void set_life(LifeT a){
    this->s = a;
  }
  void set_cnt(int a){
    this->cnt = a;
  }
  void set_x(int x){
    this->x = x;
  }
  void set_y(int y){
    this->y = y;
  }
};

class Game{
private:
  vector<vector<Cell>> s; //matrix
  int rows; //rows in matrix
  int cols; //cols in matrix

public:
  Game(){ //if no value is inputed, by default create a 15 x 15 grid
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
  Game(vector<vector<Cell>> s){ //takes in vector of vectors and the size
    this->s = s;
    this->rows = s.size();
    this->cols = s[0].size();
  }
  void set_cell(Cell c){
    this->s[c.get_x()][c.get_y()] = c;
  }
  Cell get_cell(int x, int y){
    return s[x][y];
  }
  int get_rows(){
    return rows;
  }
  int get_cols(){
    return cols;
  }

  void alive_neighbour_cnt(Cell c){
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
    //Updates the cell at s[x][y]
    s[c.get_x()][c.get_y()] = Cell(c.get_Alive(), alive, c.get_x(), c.get_y());
  }
  void update_cell(Cell c){
    //if less than 2 alive cells neighbour, cell dies
    if (c.get_cnt() < 2){
      s[c.get_x()][c.get_y()] = Cell(DEAD, c.get_cnt(), c.get_x(), c.get_y());
    }
    //if more than 3 neighbors, it dies
    if (c.get_cnt() > 3){
      s[c.get_x()][c.get_y()] = Cell(DEAD, c.get_cnt(), c.get_x(), c.get_y());
    }
    //if exactly 3 and dead, it becomes alive
    if (c.get_cnt() == 3 && c.get_Alive() == DEAD){
      s[c.get_x()][c.get_y()] = Cell(ALIVE, c.get_cnt(), c.get_x(), c.get_y());
    }
    //otherwise, do nothing
  }
  void update_game(){ //updates the game state
    //for every row
    for(int i = 0; i < rows; i++){
      for (int j = 0; j < cols; j++){
        //calling member function
        this->update_cell(s[i][j]);
      }
    }
  }
  void print_state(){ //prints current state

  }
};

int main(){
  // LifeT a = ALIVE;
  // Cell test =  Cell(ALIVE, 3, 4, 5);
  // cout << test.get_Alive();
  // test.set_life(DEAD);
  // cout << test.get_Alive();
  //
  // vector<vector<Cell> > m(2);
  // vector<Cell> v;
  // v.push_back(test);
  // m[0] = v;
  // cout << m[0][0].get_Alive();

  Cell c = Cell(ALIVE, 0, 13, 14 );
  Game test = Game();
  test.set_cell(c);
  cout << test.get_cell(13, 14).get_Alive();
  test.update_game();
  cout << test.get_cell(13, 14).get_Alive();
  // cout << test.get_cell(14,14).get_Alive();
  test.update_cell(test.get_cell(13,14));
  cout << test.get_cell(13, 14).get_Alive();













}
