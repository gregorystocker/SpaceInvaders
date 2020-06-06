#include <iostream>
#include "bullett.h"
using namespace std;
//constructors****************************************************************************
Bullett :: Bullett()
{
    dir = 1; // arent really using this right now for bullett
}
Bullett :: Bullett(int dummy)
{

}

Bullett :: Bullett( int x, int y)
{
    setX(x);
    setY(y); //set the bulletts coordinates
}
//***************************************************************************************

void Bullett :: moveBullett() // the enemy uses this one
{
    if (y+1 > 19) //checks if the next space availible outside of the array
    {
        deactivate(); //deactivate bullett
        y = 0;// and resosition its y coordinate to 0
    }


    else if(y+1 <=20)// if the next spot to move to is part of the array:
        y +=1;// then move there


}


void Bullett :: moveBullett(int dummy) // the player uses this one
{
    if (y-1 < 0) //checks if the next space availible outside of the array
    {
        deactivate(); //deactivate bullett
        y = 20;// and resosition its y coordinate to 20
    }


    else if(y+1 <=20)// if the next spot to move to is part of the array:
        y -=1;// then move there


}
