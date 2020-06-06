#ifndef SPACE_H
#define SPACE_H

#include <iostream>
#include "bullett.h"

using namespace std;


class Space//enemy class
{

public:
    Space();//initializes bulletts and ishould initialize numOfEnemies to 0
    //giving error message at numOfEnemies = 0
    Space(int x, int y, char enemyChar, bool isAlive);//sets starting point for enemy and enemy char, and initializes bulletts


    void setNumOfEnemies( int numOfEnemies ){this->numOfEnemies = numOfEnemies;}
    void setCoordinates(int x, int y);
    void setChar(char);
    void setLivingStatus(int isAlive){this->isAlive = isAlive;}
    void kill(){isAlive = false;}

    int getX(){return x;}
    int getY(){return y;}
    bool getIsAlive(){return isAlive;} // returns objects living status
    int getNumOfEnemies(){return numOfEnemies;}
    char getChar() {return enemyChar;}
    int getCurrentBullett(){return currentBullett;}

    void moveEnemy();// moves 6 spaces in one direction, then turns around
    void initializeBulletts(); // creates an array of bulletts
    void AddEnemy(){numOfEnemies++;}
    void changeLivingStatus();// if alive make dead visa versa
    void shoot();// sets the bulletts coordinates to right below the enemy
    Bullett bArray[8];// holds an array of 8 bulletts





private:

    int x,
        y,
        dir = 1,
        moveCounter = 1;// is keeping track of how many times enemy has moved int that direction.

    char enemyChar;
    bool isAlive;// checks if enemy is set to alive or not
    int currentBullett = 0;// keeps track of what bullett we`re on

    static int numOfEnemies;




};
#endif // SPACE_H

