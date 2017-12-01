#ifndef LOADSAVE_H_INCLUDED
#define LOADSAVE_H_INCLUDED
#include <fstream>
#include <iostream>
#include "globals.h"




int save_game1(char *input, std::ofstream &save);
int load_game1(char *input, std::ifstream &load);


#endif // LOADSAVE_H_INCLUDED
