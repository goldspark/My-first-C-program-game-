#include "Creatures.h"
#include <iostream>
Creatures::Creatures()
{
  health = 0;
  rating = 0;
  damage = 0;

}
Creatures::Creatures(int h, int d, int r)
{
    health = h;
    damage = d;
    rating = r;

}


void Creatures::get_stats(double current)
{

            // Used to get stats from everything
std::cout << "Status for Creature----\nHealth:" << health <<"(" <<(health/current) * 100 << "%)" << "\nDamage:" << damage << "\nRating: " << rating << "\n----------------------";


}
