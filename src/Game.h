#ifndef Game_H
#define Game_H
#include "CellType.h"
#include "Cell.h"
#include <vector>
/**
 * ... text ...
 */
 /**
 * @brief A class to create a Game
 * @details This class produces a Game object to play Conway's GOL with.
 * Does this by updating a matrix based on the rules of the game, and transitioning its internal state
 *
 */
class Game {
private:
  std::vector<std::vector<Cell>> s; //matrix
  int rows; //rows in matrix
  int cols; //cols in matrix
  /**
 * @brief a method to update a cell with the correct number of alive neighbors
 * @details Gets the sum of all alive neighbor in the Moore neigbourhood, and returns a cells
 * with the update alive neighbour count
 * @param c A cell
 * return An updated cell with the correct number of alive neighbors
 */
  Cell alive_neighbour_cnt(Cell c);
  /**
 * @brief updates the alive cnt of all cells  in the matrix
 * @return a matrix with updated cells
 */
  std::vector<std::vector<Cell>> update_all_cnt();
  /**
 * @brief updates the life of a cell based on its neighbors in the matrix
 * @details determines the state of an input cell based on the rules of the game and the
 * number of alive cells around it.
 * @param A cell
 * @return a cell, with the updated life
 */
  Cell update_life(Cell c);

public:
  /**
 * @brief defualt constructor for the Game
 * @details constructs a Game object with a 15 x 15 matrix, and sets all cells inside to dead.
 * Also sets all cells alive cnt to 0, and x and y fields to their place in the matrix
 */
  Game();
  /**
 * @brief constructor for the Game
 * @param a vector of vectors of type Cell
 */
  Game(std::vector<std::vector<Cell>> s);
  /**
 * @brief sets a cell into a Game, based on the cell's x and y
 * @param a cell
 */
  void set_cell(Cell c);
  /**
 * @brief gets a cell from the game using inputted x and y indices
 * @param the row index
 * @param the col index
 */
  Cell get_cell(int x, int y);
  /**
 * @brief gets the number of rows in a Game
 * @return an int with the number of rows
 */
  int get_rows();
  /**
 * @brief gets the number of cols in a Game
 * @return an int with the number of cols
 */
  int get_cols();
  /**
 * @brief gets matrix in a Game
 * @return an vector of vectors of cells;
 */
  std::vector<std::vector<Cell>> get_matrix();
  /**
 * @brief updates the state of the game, based on the rules provided in the specification
 */
  void update_game();
  /**
 * @brief prints a representation of the Game to the screen
 * @details Prints the matrix corresponding to current game state to the screen. X means alive, O means dead
 */
  void print_state();
};
#endif
