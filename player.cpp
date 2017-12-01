#include "player.h"
#include "globals.h"
#include <iostream>
bool death = false;

Player::Player() : health(0), damage(0), rating(0){} // Default constructor

Player::Player(int h, int d, int r) : health(h), damage(d), rating(r){} // Custom constructor

void Player::get_stats(double current){          // Used to get stats from everything

std::cout << "Status for Player----\nHealth:" << health <<"(" <<(health/current) * 100 << "%)" << "\nDamage:" << damage << "\nRating: " << rating << "\n----------------------";

}

void Player::set_status_d(int h, int d, int r){  //when player gets positive on damage, rating and health

    health = health + h;
    damage = damage + d;
    rating = rating + r;


}

void Player::set_status_r(int h, int d, int r){    //for when something happens to player status *i.e he recieves damage)

health = health - h;
if(health <= 0)
{
    death = true;
    return;
}

damage = damage - d;
if(damage < 0)
{
    damage = 0;
    return;
}
rating = rating - r;
if(rating < 0)
{
    rating = 0;
    return;
}

}

int Player::get_rating()
{
    return rating;
}
int Player::get_damage()
{
    return damage;
}

int Player::get_health()
{
    return health;
}

void Player::set_damage(int d)
{
    damage = d;
}

void Player::set_health(int h)
{
    health = h;
}

void Player::set_rating(int r)
{
    rating = r;
}
