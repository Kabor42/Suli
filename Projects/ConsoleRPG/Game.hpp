//
// Created by kabor on 2018.03.01..
//

#ifndef CONSOLERPG_GAME_H
#define CONSOLERPG_GAME_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "Character.hpp"
#include "functions.hpp"

using std::cout;
using std::cin;
using std::endl;

/** Main Game class
 * Provide everything for the main process
 */
class Game {
 public:
     Game();    /** Sets default values */
     virtual ~Game(); /** Main deconstructor */

     /** Main loop
      * Coordiates the whole program.
      * Players choices.
      * etc.
      */
     void mainMenu();

     /** If game is running
      * @returns isRunning
      */
     bool getPlaying() const;

     /** Initialize a new game
      * void
      */
     void initGame();

 private:
     int choice; /** Players choice at the menu */
     bool playing; /** If game is running */

     // Character Related
     Character character;
};


#endif //CONSOLERPG_GAME_H
