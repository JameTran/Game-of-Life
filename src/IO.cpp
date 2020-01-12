#include <iostream>
#include <fstream>
#include <vector>
#include "CellType.h"
#include "Cell.h"
#include "Game.h"
#include "IO.h"

using namespace std;

Game read(string txt){
  int m, n;
  ifstream in(txt.c_str());
  in >> m >> n; //get rows and cols

  vector<vector<Cell >> grid(m); //makes a vector of vectors of size == rows
  for(int i = 0; i < m; i++){ //adds column vectors of length col == n
    vector<Cell> cols(n);
    grid[i] = cols;
  }

  //reads  matrix
  for (int i = 0; i < n; i++){ //for length n cols
    for(int j = 0; j < m; j++){ //for each row
      char temp;
      in >> temp;
      if(temp == 'X'){ //if input is a live cell
        //grid[j][i] = 1;
        Cell a = Cell(ALIVE, 0, j, i);
        grid[j][i] = a;
      }
      if(temp == 'O'){
        Cell b = Cell(DEAD, 0, j, i);
        grid[j][i] = b;
      }
    }
  }
  return Game(grid);
}

void write(Game s, string txt){
  int rows = s.get_rows();
  int cols = s.get_cols();
  ofstream out(txt.c_str());
  out << rows << " " << cols << "\n";
  for(int i = 0; i < cols; i++){ //for num of cols
    for(int j = 0; j < rows; j++){ //print the row
      if(s.get_cell(j, i).get_Alive() == ALIVE){
        out << 'X' << " ";
      }
      else if(s.get_cell(j, i).get_Alive() == DEAD){
        out << "O" << " ";
      }
    }
    out << "\n";
  }
}

// int  main() {
  // Game test = read("sample.txt");
  // test.print_state();
  // test.update_game();
//   test.print_state();
//   cout << test.get_cols();
//   write(test, "output.txt");
//
//
//   return 0;
// }
