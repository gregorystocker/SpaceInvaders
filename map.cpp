#include "map.h"
#include "space.h"
#include <string>
#include <iostream>
#include <conio.h> // for the getch() and the kbhit() function
#include <windows.h>
#include "Player.h"

using namespace std;


Map :: Map()
{
     for(int j =0; j < 20; j++)
    {

        for (int i =0; i < 20; i++)
        {
            mapArray[j][i] = ' ';
        }
    }
}


void Map :: initializeMap(Space enemyArray[], Player playerObj)
{
    for(int j =0; j < 20; j++) // goes 20 times for the 20 rows
    {


        for (int i =0; i < 20; i++) // 20 times 20 columns
        {
            if(j == 0 ||  i == 0 || i == 19 || j == 19 )
            {
                mapArray[j][i] = '*';//makes a wall
            }
            else
                mapArray[j][i] = ' ';//makes open space

        }
    }
//just the map so far
//*******************************************************************************************************
                 //puts player in the game{**************************************************
                    // only one player so not in an additional loop
                        if(playerObj.getIsAlive() == true)//checks if player is alive
                    mapArray[playerObj.getY()][playerObj.getX()] = playerObj.getShip();
                    //puts player in the game}**************************************************

                for(int i = 0; i < 8; i++ ) // goes through each enemy character in the array
                                            //also used to go through all bulletts for the player
                {
                     //puts enemy in the game{********************************************************
                 if(enemyArray[i].getIsAlive() == true)//checks if enemy is alive
                    mapArray[enemyArray[i].getY()][enemyArray[i].getX()] = enemyArray[i].getChar();
                    //puts enemy in the game}********************************************************

                    if ( playerObj.bArray[i].getActive() == true)// if player bullett is set to active
                    {
                        // set the array slot at the bulletts coordinates  to the bullett character
                        mapArray[playerObj.bArray[i].getY()][playerObj.bArray[i].getX()] = playerObj.bArray[i].getChar();

                    }



                    for(int inside = 0; inside < 8; inside++)// used to go through each bullett in the array
                    {
                        if(enemyArray[i].bArray[inside].getActive() == true)
                        {
                            mapArray[enemyArray[i].bArray[inside].getY()]//says specific bullett of specific enemy
                             [enemyArray[i].bArray[inside].getX()] = enemyArray[i].bArray[inside].getChar();//assigned to
                                                                                                    //that bulletts coordinates
                                                                                                            //on the map
                        }
                    }
                }





}





void Map :: displayMap()
{
    for(int j =0; j < 20; j++)
    {

        for (int i = 0; i < 20; i++)
        {
            cout<<mapArray[j][i]<<" ";//puts a space in between each character
        }
        cout<<endl;//puts a newline after each row
    }

}


