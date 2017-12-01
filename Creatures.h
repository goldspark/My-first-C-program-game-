#ifndef CREATURES_H_INCLUDED
#define CREATURES_H_INCLUDED
#include "player.h"
class Creatures:public Player{
public:

   Creatures();
   Creatures(int h, int d, int r);
   void get_stats(double current);

};



#endif // CREATURES_H_INCLUDED
