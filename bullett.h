#ifndef BULLETT_H
#define BULLETT_H

#include <iostream>



using namespace std;


class Bullett
{
public:
    Bullett();// enemy uses the default constructor
    Bullett(int dummy); // player uses the dummy variable argument constructor
    Bullett(int x, int y); // this one isn`t really used

    void setX(int x){this ->x = x;}
    void setY(int y){this->y = y;}
    int getX(){return x;}
    int getY(){return y;}
    char getChar(){return bChar;}
    void setDir(int dir){ if(dir == 1 || dir == -1)this->dir = dir; else cerr;}
    void activate(){active = true;}
    void deactivate(){active = false;}
    void moveBullett();// moves the bullett down (enemy class uses this one)
     void moveBullett(int dummy);// moves the bullett up (player class uses this one)
     //uses the dummy variable to separate it from the one the enemy uses

    bool getActive(){return active;}

private:
    char bChar = '|';
    int x,
        y,
        dir = 1;
    bool active = false;




};
#endif // BULLETT_H
