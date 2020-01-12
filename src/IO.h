#ifndef IO_H
#define IO_H
#include <iostream>
#include <fstream>
#include <vector>
#include "CellType.h"
#include "Cell.h"
#include "Game.h"

/**
* @brief reads from a text file, corresponding to the string. Then constructs a Game based on those details
* @details Reads a matrix from a file of Xs and Os. (X = alive), O = dead) Creates a matrix of cells based on this
* and creates a Game object with it
* @param A string corresponding to the file name
* @return a Game with the state in the text file matrix
*/
Game read(std::string txt);
/**
* @brief writes the state of the game to a text file, corresponding to the string.
* @details Given a matrix of cells, prints  a matrix of Xs and Os (X = alive), O = dead) corresponding to the cells.
* @param A Game object with the desired state
* @param A string corresponding to the file name
*/
void write(Game s, std::string txt);

#endif
