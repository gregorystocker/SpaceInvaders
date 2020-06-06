//Greg Stocker
//and Israel Renteria

#include <iostream>
#include "space.h"
#include "bullett.h"
#include "map.h"
// for the system(cls)
#include <stdlib.h>
#include "player.h"
#include "conio.h"

using namespace std;


int main()
{





    //creates object of Space class which is the enemy class
    //should probably have named it enemy, but oh well.
    //parameters: (x coordinate, y coordinate, Enemy Character, Living Status)
    // 157 is the ascii code for the enemy character we`re using
    Space EnemyObj1(10, 2, 157,false);
    Space EnemyObj2(4, 3, 157,false);
    Space EnemyObj3(3, 4, 157,false);
    Space EnemyObj4(13, 2, 157,false);
    Space EnemyObj5(9, 5, 157,false);
    Space EnemyObj6(10, 1, 157,false);
    Space EnemyObj7(6, 4, 157,false);
    Space EnemyObj8(4 , 6, 157,false);
    // initializing array with 8 enemies
    Space EnemyArray[8] = {EnemyObj1,EnemyObj2,EnemyObj3,EnemyObj4,
                            EnemyObj5,EnemyObj5,EnemyObj7,EnemyObj8};

    //******************************************************************************************************************

    // Player(char ship, int x, int y, bool isAlive);
    // creates object of Player class with coordinates (10,16) that is alive
    //and uses an A looking character as its character (142 is the character`s ascii #)
     Player PlayerObj(142, 10, 16 ,true);




//Creates a map object
     Map MapObj;
    char moveChar;
    // used to differenciate between the players and the enemies bullets movebullett function
    int dummy;
    bool game = true; // this is the game loop variable
    bool win = false;
    int deathCount = 0; // checked every loop to see if all enimies are dead and then reset every loop

        //keeps time in game loop
        int spawnCount = 0;
        // keeps track of which enemy to spawn
        int enemyCount = 0;



//GAME LOOP****************************************************************************************************
        while(game)//game loop
        {
            //used to time things
            spawnCount++;
            // resets the deathcount as it is calculated every loop at the end
            deathCount = 0;



            if(kbhit())// if a key is pressed ( this is so its not paused waiting for input)
            {
                moveChar = getch();// recieve movechar from the player

                PlayerObj.moveShip(moveChar); // and pass it into the move function

            }


            if (spawnCount %5 == 0 && enemyCount < 8)
            {
                //spawns the enemies one at a time every five frames until all are there
                EnemyArray[enemyCount].changeLivingStatus();
                enemyCount++;
            }
            //creates the map and puts the enemy characters and player in game map
            MapObj.initializeMap(EnemyArray, PlayerObj);
            for(int i = 0; i < 8; i++)//runs 8 times to cycle through the 8 enemy objects
            {
                    //PLAYER BULLETS
                     if(PlayerObj.bArray[i].getActive() == true)// if selected bullett is active,
                              {
                                  PlayerObj.bArray[i].moveBullett(dummy);// then move the bullett
                              }

                if(EnemyArray[i].getIsAlive() == true)
                {

                    if(spawnCount % 2 == 0)//slows enemy movement
                    EnemyArray[i].moveEnemy();//moves the enemy

                    if(spawnCount % 25 == 0)//times the shoot function
                    {
                        EnemyArray[i].shoot(); //shoots the bullett
                    }




                        }// end IF enemy is alive


                            // j loop is inside of the i loop
                    // checks all the bulletts in the array for each of the enemys in their own array.
                            for(int j = 0; j < 8; j++)// j loop / inner loop
                            {
                                  if(EnemyArray[i].bArray[j].getActive() == true)// if selected bullett is active,
                                  {
                                      EnemyArray[i].bArray[j].moveBullett();// then move the bullett
                                  }



                            }//end j loop/ inner loop


                        //loop c// collision loop
                        for (int c = 0; c < 8; c++)
                        {

                            //COLLISIOIN FOR PLAYER WITH BULLET*******************************
                            // if the specific bullet is active
                            if(EnemyArray[i].bArray[c].getActive() == true)
                            {

                                //checking if players x coordinate is at enemy bullets x
                                if(PlayerObj.getX() == EnemyArray[i].bArray[c].getX())
                                {
                                     //checking if players y coordinate is at enemy bullets y
                                    if(PlayerObj.getY() == EnemyArray[i].bArray[c].getY())
                                    {
                                        PlayerObj.setIsAlive(false);


                                        game = false;

                                    }
                                }
                            }
                            //*****************************************************************
                                    //COLLISIOIN FOR PLAYER WITH BULLET*******************************
                            // if the player`s specific bullet is active
                            if(PlayerObj.bArray[c].getActive() == true)
                            {

                                //checking if players x coordinate is at enemy bullets x
                                if(EnemyArray[i].getX() == PlayerObj.bArray[c].getX())
                                {
                                     //checking if players y coordinate is at enemy bullets y
                                    if(EnemyArray[i].getY() == PlayerObj.bArray[c].getY())
                                    {
                                        EnemyArray[i].kill();

                                    }


                                }

                            }//end of player bullett getActive

                        }// end of c loop






            }//end i loop/ outer loop


        //Check to see if all enemies are defeated************************

        //counting to see if you defeated all enemies
        for(int i = 0; i<8; i++)
        {
            if (EnemyArray[i].getIsAlive() == false)
            {
                deathCount++;
            }
        }

        //checks to see if all enemies are dead and dosnt work unless loop has ran 10 times
        //because enemies are spawned in and will return true at the start
        if (deathCount == 8 && spawnCount > 10)
        {
            game = false;
            win = true;
        }
       //*****************************************************************




            //displays everything
            MapObj.displayMap();

            //clears the screen
            system("cls");

            //0 to 100 real quick
            if(spawnCount == 100)
            {
                // resets the counter
                spawnCount = 0;
            }


        }//end game loop/ while(game) loop
        //*****************************************************************************************

        //victor/loss messages


        //message for if you win
        if (game == 0 && win == 1)
        {
            char ar[20] ={ ' ', ' ', ' ',' ', ' ', ' ', ' ',' ', ' ', ' ', ' ',' ', ' ', ' ', ' ',' ', ' ', ' ', ' ',' '};
            char spot = '*';
            int counter = 0;
            for(int i = 0; i < 200; i++)
                {
                    if (counter <=19)
                        counter++;
                    else
                        counter = 1;
                    ar[counter] = spot;
                    ar[counter -1] = ' ';

                cout<<"You Win!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
                    <<"You saved the galaxy!!!!!!!!!!!!!!!!\n";
                    for(int j = 0; j < 20; j++)
                        cout<<ar[j];


                system("cls");

                }


        }


        //message for if you die
        if (game == 0 && win == 0)
        {
            for(int i = 0; i < 100; i++)
            {
                cout<<"GAME OVER!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
                system("cls");
            }

        }


    return 0;
}


