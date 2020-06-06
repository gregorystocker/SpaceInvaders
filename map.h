
#ifndef MAP_H
#define MAP_H

#include "space.h"
#include "player.h"
#include <iostream>
using namespace std;

class Map
{
public:
    Map();
    void initializeMap(Space EnemyArray[], Player playerObj); //creates the map
    // gets the array of enemies and the player passed in as parameters
    void displayMap(); // draws the map




private:
     char mapArray[20][20]; // I`m the map, I`m the map, I`m the map, Hurray!!!
     int spawnFlag = 0;//should only let the enemys spawn once

};




#endif // MAP_H

