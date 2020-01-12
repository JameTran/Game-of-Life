#include <vector>
#include <iostream>
#include "CellType.h"
#include "Cell.h"
#include "Game.h"

using namespace std;
int main(){
  //still life
  Cell a = Cell(ALIVE, 0, 14, 14);
  Cell b = Cell(ALIVE, 0, 13, 13);
  Cell c = Cell(ALIVE, 0, 13, 14 );
  Cell d = Cell(ALIVE, 0, 14, 13);


  //oscillator
  Cell a1 = Cell(ALIVE, 0, 8, 9);
  Cell b1 = Cell(ALIVE, 0, 8, 10);
  Cell c1 = Cell(ALIVE, 0, 8, 11);

  Cell d1 = Cell(ALIVE, 0, 7, 11);
  Cell e1 = Cell(ALIVE, 0, 6, 10);
  Game test = Game();
  test.set_cell(a);
  test.set_cell(b);
  test.set_cell(c);
  test.set_cell(d);
  test.set_cell(a1);
  test.set_cell(b1);
  test.set_cell(c1);
  test.set_cell(d1);
  test.set_cell(e1);
  // cout << test.get_cell(13, 14).get_Alive();
  test.print_state();


  test.update_game();
  test.print_state();
  test.update_game();
  test.print_state();


  // cout << "life before: " << test.get_cell(8, 9).get_Alive() << endl;
  // cout << "alive cnt before: " <<test.get_cell(8, 9).get_cnt() << endl << "life after update: ";
  // vector<vector<Cell>> q = test.update_all_cnt();
  // Game g = Game(q);
  // cout << g.update_life(g.get_cell(8, 9)).get_Alive() << endl;
  // g.set_cell(g.update_life(g.get_cell(8, 9)));
  // cout << "cnt after: "<< g.update_life(g.get_cell(8, 9)).get_cnt();
  // int wtf;
  // g.print_state();

  //
  // //////
  // cout << endl << "test 8, 11" << endl;
  // Cell sample1 = test.alive_neighbour_cnt(test.get_cell(8, 11));
  // cout << "life before: " << sample1.get_Alive() << endl;
  // cout << "alive cnt before: " <<sample1.get_cnt() << endl << "life after update: ";
  //
  // cout << test.update_cell(sample1).get_Alive() << endl;
  // cout << "cnt after: "<< test.update_cell(sample1).get_cnt();

  // test.update_game();
  // cout << endl;
  // test.print_state();
  // cout << test.get_cell(8, 10).get_cnt() << endl;
  // cout << test.get_cell(8, 10).get_Alive() << endl;
  // cout << test.get_cell(9, 10).get_Alive() << endl;
  // cout << test.get_cell(14,14).get_Alive();


  // vector<vector<Cell> > m(2);
  // vector<Cell> v;
  // v.push_back(test);
  // m[0] = v;
  // cout << m[0][0].get_Alive();
}
