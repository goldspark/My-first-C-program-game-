#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player{
protected:
    int health, damage, rating; //Main player states and other monsters
public:
    Player();
    Player(int h, int d, int r);
    void set_rating(int r);
    void set_health(int h);
    void set_damage(int d);
    int get_rating();
    int get_damage();
    int get_health();
    void  get_stats(double current);
    void set_status_r(int h, int d, int r); //recieve something
    void set_status_d(int h, int d, int r); //do something
};


#endif // PLAYER_H_INCLUDED
