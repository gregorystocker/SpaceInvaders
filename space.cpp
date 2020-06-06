#include <iostream>
#include "space.h"
#include <cassert>
#include <stdlib.h>
#include <time.h>
using namespace std;

Space :: Space()
{
   initializeBulletts();
   //setNumOfEnemies(0);
   //not working for some reason
}

Space :: Space(int x, int y, char enemyChar, bool isAlive)
{
     initializeBulletts(); // creates array of bulletts
     setCoordinates(x,y); // sets the coordinates
     setChar(enemyChar); // sets character
     setLivingStatus(isAlive); // sets living status
}

void Space :: setCoordinates(int x, int y)
{
    assert(x >=1 && x <= 28); //bounds checking
    assert(y >=1 && y <= 28);
        this->x = x;
        this->y = y;
}

void Space:: setChar(char enemyChar)
{
    this-> enemyChar = enemyChar;
}

void Space :: initializeBulletts()
{
    bArray[0] = Bullett();
    bArray[1] = Bullett();
    bArray[2] = Bullett();
    bArray[3] = Bullett();
    bArray[4] = Bullett();
    bArray[5] = Bullett();
    bArray[6] = Bullett();
    bArray[7] = Bullett();


}

 void Space :: moveEnemy()
 {
     if(moveCounter < 6 && moveCounter > 0)
     {
        moveCounter++; //moves the enemy
        if(x >= 20 || x <= 0 )// add bounds checking
            // should move 6 spaces and them turn around continuously
        {
            if( x>= 20)
                x = 19;

            if( x<= 0)
                x = 1;
            moveCounter = 1;
            dir *= -1;
        }
     }
        else
        {
             dir *= -1;//turns around
             moveCounter = 1;
              if(x >= 20 || x <= 0 )
                {
                    if( x>= 20)
                        x = 19;

                    if( x<= 0)
                        x = 1;

                    moveCounter = 1;
                    dir *= -1;
                }
        }


        x += (1 * dir);

 }


 void Space :: changeLivingStatus()//returns a boolean to see if the enemy is alive or not
 {
     if( isAlive == false)
     {
         isAlive = true;
     }


     else if( isAlive == true)
     {
         isAlive = false;
     }
 }


 void Space :: shoot()
 {
     bArray[currentBullett].setX(x); // passes in the coordinate from the enemy`s member variable x same with y
     bArray[currentBullett].setY(y + 1); // right beneath the enemy
     bArray[currentBullett].activate(); // activates bullett so it will trigger movebullett fuction called from main

    if(currentBullett <=6) // checks if the bullett is on an available slot
     currentBullett++;// now that we have shot that bullett, the next in the "chamber" will fire next time shoot is called
     else
        currentBullett == 0; //reload, as our bullett array only has 8 spots
 }

