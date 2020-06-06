//**********
// player.cpp
// Author: Israel Renteria
// Last Modified:
// Description:
//**********
#include <conio.h>
#include <iostream>
#include <cassert>
#include "player.h"
#include "bullett.h"

using namespace std;

Player::Player()
{
    ship= '^';
    x = 0;
    y = 0;
    isAlive= true;
}

Player::Player(char ship, int x, int y, bool isAlive)
{
    this->ship= ship;
    this->x= x;
    this-> y= y;
    this ->isAlive;
}

void Player::setX(int x)
{
    assert(x<= 20 && x >= 0);
    this->x = x;
}

void Player::setY(int y)
{
    assert(y<=20 && y>= 0);
    this-> y= y;
}

void Player::moveShip(char movement)
{

    if((movement=='a' || movement=='A' ) && x > 1)
        x  = x-1;
    else if ((movement =='d'|| movement=='D') && x < 18)
        x = x+ 1;
    else if((movement == 'w'|| movement=='W') && y > 9)
        y = y-1;
    else if ((movement== 's'|| movement=='S') && y < 18)
        y = y+1;
    else if (movement == ' ')
        shoot();
}

void Player::shoot()
{
    bArray[currentBullett].setX(x);
     bArray[currentBullett].setY(y - 1); // right above the player
     bArray[currentBullett].activate(); // activates bullett so it will trigger movebullett fuction called from main

    if(currentBullett <=7)
     currentBullett++;// now that we have shot that bullett, the next in the "clip" will fire next time shoot is called
     else
        currentBullett = 0; //reload, as our bullett array only has 8 spots
}

void Player::setIsAlive(bool isAlive)
{
    this->isAlive= isAlive;
}

void Player :: initializeBulletts()
{
    bArray[0] = Bullett(1); // uses the 1 as a dummy variable to differenciate between the bullett that player and enemy
    bArray[1] = Bullett(1);                                                                                        //uses
    bArray[2] = Bullett(1);
    bArray[3] = Bullett(1);
    bArray[4] = Bullett(1);
    bArray[5] = Bullett(1);
    bArray[6] = Bullett(1);
    bArray[7] = Bullett(1);


}
