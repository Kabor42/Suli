//
// Created by kabor on 2018.03.01..
//
#include "Game.hpp"


Game::Game() {
    choice = 0;
    playing = true;
}

Game::~Game() {
}

void Game::initGame() {
    std::string name;
    std::cout << "Enter name for new character :";
    getline(std::cin, name);

    character.initialize( name);
}

void Game::mainMenu() {
    cout <<     "MAIN MENU"              << endl << endl;

    cout <<     "0: QUIT"               << endl;
    cout <<     "1: Travel"             << endl;
    cout <<     "2: Shop"               << endl;
    cout <<     "3: Level up"           << endl;
    cout <<     "4: Rest"               << endl;
    cout <<     "5: Caracter sheet"     << endl;

    cout << endl << "Choice: " << endl;
    cin >> choice;

    switch (choice) {
        case 0:
            playing = false;
            break;
        case 5:
            character.printStats();
            break;
        default:
            break;
    }
}

bool Game::getPlaying() const {
    return playing;
}
