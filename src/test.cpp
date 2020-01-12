#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"
#include <vector>
#include <iostream>
#include "CellType.h"
#include "Cell.h"
#include "Game.h"
#include "IO.h"
using namespace std;

TEST_CASE("test cell"){ //tests regular function of the cell ADT
  Cell a = Cell(ALIVE, 0, 3, 4);
  REQUIRE(a.get_Alive() == ALIVE);
  REQUIRE(a.get_cnt() == 0);
  REQUIRE(a.get_x() == 3);
  REQUIRE(a.get_y() == 4);

  //test exceptions
  REQUIRE_THROWS_AS(Cell(ALIVE, -1, 3, 4), out_of_range);
  REQUIRE_THROWS_AS(Cell(ALIVE, 0, -3, 4), out_of_range);
  REQUIRE_THROWS_AS(Cell(ALIVE, 1, 3, -4), out_of_range);
}

TEST_CASE("test game constructor and public getters and setters"){ //tests public functions of the Game ADT
  Game a = Game();
  REQUIRE(a.get_rows() == 15);
  REQUIRE(a.get_cols() == 15);
  Cell sample_cell = Cell(DEAD, 0, 0, 0);
  REQUIRE(a.get_cell(0, 0).get_Alive() == sample_cell.get_Alive());
  a.set_cell(Cell(ALIVE, 0, 4, 5));
  REQUIRE(a.get_cell(4, 5).get_Alive() == ALIVE);

  //test constructor with parameters
  vector<vector<Cell> > good_vect(2);
  for(int i = 0; i < 2; i++){
    vector<Cell> v(1);
    v[0] = Cell();
    good_vect[i] = v;
  }
  Game b = Game(good_vect);
  REQUIRE(b.get_rows() == 2);
  REQUIRE(b.get_cols() == 1);

  //test exceptions
  vector<vector<Cell> > bad_vect;
  REQUIRE_THROWS_AS(Game(bad_vect), invalid_argument);
}

TEST_CASE("test update_game still life"){ //
  //Tests still life
  Cell a = Cell(ALIVE, 0, 14, 14);
  Cell b = Cell(ALIVE, 0, 13, 13);
  Cell c = Cell(ALIVE, 0, 13, 14 );
  Cell d = Cell(ALIVE, 0, 14, 13);
  Game test = Game();
  test.set_cell(a);
  test.set_cell(b);
  test.set_cell(c);
  test.set_cell(d);
  test.update_game();
  REQUIRE(test.get_cell(14, 14).get_Alive() == ALIVE);
  REQUIRE(test.get_cell(13, 14).get_Alive() == ALIVE);
  test.update_game();
  REQUIRE(test.get_cell(14, 14).get_Alive() == ALIVE);
  REQUIRE(test.get_cell(13, 14).get_Alive() == ALIVE);
}
TEST_CASE("test_update_game oscillator"){
  Cell a1 = Cell(ALIVE, 0, 8, 9);
  Cell b1 = Cell(ALIVE, 0, 8, 10);
  Cell c1 = Cell(ALIVE, 0, 8, 11);
  Game test = Game();
  test.set_cell(a1);
  test.set_cell(b1);
  test.set_cell(c1);
  test.update_game();
  REQUIRE(test.get_cell(8, 10).get_Alive() == ALIVE);
  REQUIRE(test.get_cell(7, 10).get_Alive() == ALIVE);
}

TEST_CASE("test edge"){ //makes sure the edges are handled properly. edges are done by
  //treating all outside as 0
  Cell a = Cell(ALIVE, 0, 0, 0); //on in top left
  Cell b = Cell(ALIVE, 0, 14, 14); //one in bottom right
  Game test = Game();
  test.set_cell(a);
  test.set_cell(b);
  test.update_game();
  REQUIRE(test.get_cell(0, 0).get_Alive() == DEAD);
  REQUIRE(test.get_cell(14, 14).get_Alive() == DEAD);
}
TEST_CASE("test IO"){ //tests file input and output
  Game test = read("sample.txt");
  REQUIRE(test.get_cols() == 3);
  REQUIRE(test.get_rows() == 3);
  REQUIRE(test.get_cell(0, 0).get_Alive() == ALIVE);

  test.update_game();
  write(test, "output.txt");
  Game test1 = read("output.txt");
  REQUIRE(test.get_cols() == 3);
  REQUIRE(test.get_rows() == 3);
  REQUIRE(test.get_cell(1, 0).get_Alive() == ALIVE);


}
