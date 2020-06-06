#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "bullett.h"
class Player
{
private:
    char ship;
    int x;
    int y;
    bool isAlive;
    int currentBullett = 0;// keeps track of what bullett we`re on
public:
    Player();
    Player(char ship, int x, int y, bool isAlive); // sets the ship variable, x and y values and if hes alive
    void setX(int x);
    void setY(int y);
    void setIsAlive(bool isAlive); //sets if the player is alive
    void initializeBulletts(); // creates an array of bulletts
    char getShip()const{return ship;} // to get the ship character
    bool getIsAlive()const{return isAlive;}
    int getX()const{return x;}
    int getY()const{return y;}
    void moveShip(char movement);
    void shoot();// sets the bulletts coordinates to right above the player
    Bullett bArray[8];// holds an array of 8 bulletts

};


#endif // PLAYER_H_INCLUDED
