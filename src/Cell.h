#ifndef Cell_H
#define Cell_H

#include <vector>
#include <iostream>
#include "CellType.h"
/**
* @brief A cell class, with methods to check its life state, number of alive neighbors, and its position in the matrix
*/
class Cell{
private:
  LifeT s;
  int cnt;
  int x;
  int y;
public:
  /**
 * @brief The constructor for the cell
 * @details Constructs the cell by default, sets Life to dead, and cnt, x, y all to 0
 */
  Cell();
  /**
 * @brief constructor for the cell
 * @details Constructs the cell based on the parameters passed in.
 * @param desired life of cell
 * @param alive neighbor cnt for cell
 * @param x position
 * @param y position
 */
  Cell(LifeT s, int cnt, int x, int y);
  /**
 * @brief gets the life status of a cell
 * @return an enum with 0 being alive, 1 being dead
 */
  LifeT get_Alive();
  /**
 * @brief gets the number of alive neighbors of a cell
 * @return an int with the number of alive neighbors of a cell
 */
  int get_cnt();
  /**
 * @brief gets x value of a cell
 * @return an int with the x value
 */
  int get_x();
  /**
 * @brief gets y value of a cell
 * @return an int with the y value
 */
  int get_y();
};
#endif
