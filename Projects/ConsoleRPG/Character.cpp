//
// Created by kabor on 2018.03.01..
//

#include "Character.hpp"

int calculateNextExp( const int level) {
    return static_cast<int> (50/3)*(std::pow(level,3)-6*std::pow(level,2)+(17*level)-11);
}

Character::Character() {

    xPos = 0.0;
    yPos = 0.0;

    strength = 0;
    vitality = 0;
    dexterity = 0;
    intelligence = 0;

    name = "";
    level = 0;
    exp = 0;
    hp = 0 ;
    hpMax = 0;
    stamina = 0;
    staminaMax = 0;
    damageMin = 0;
    damageMax = 0;
    defense = 0;
    luck = 0;

    statPoints = 0;
    skillPoints = 0;
}

Character::~Character() {
}

void Character::initialize( const std::string name) {

    this->xPos = 0.0;
    this->yPos = 0.0;

    this->name = name;
    this->level = 1;
    this->exp = 0;
    this->expNext = calculateNextExp( level);
    this->strength = 5;
    this->vitality = 5;
    this->dexterity = 5;
    this->intelligence = 5;

    this->hp = 10;
    this->hpMax = 10;
    this->stamina = 10;
    this->staminaMax = 10;
    this->damageMin = 2;
    this->damageMax = 4;
    this->defense = 10;
    this->luck=10;

    this->statPoints = 0;
    this->skillPoints = 0;

}

void Character::printStats() const {
    std::cout << "--= Character Sheet =--" << std::endl;
    std::cout << "--= Name: " << this->name << " =--" << std::endl;
    std::cout << "--= Level: " << this->level << " =--" << std::endl;
    std::cout << "--= Exp: " << this->exp << " =--" << std::endl;
    std::cout << "--= Exp to next level: " << this->expNext << " =--" << std::endl;
    std::cout << std::endl;
    std::cout << "--= Strength: " << this->strength << " =--" << std::endl;
    std::cout << "--= Vitality: " << this->vitality << " =--" << std::endl;
    std::cout << "--= Dexterity: " << this->dexterity << " =--" << std::endl;
    std::cout << "--= Intelligence: " << this->intelligence << " =--" << std::endl;
    std::cout << std::endl;
    std::cout << "--= HP: " << this->hp << "/" << this->hpMax << " =--" << std::endl;
    std::cout << "--= Stamina: " << this->stamina << "/" << this->staminaMax << " =--" << std::endl;
    std::cout << "--= Damage: " << this->damageMin << "-" << damageMax << " =--" << std::endl;
    std::cout << "--= Defense: " << defense << " =--" << std::endl;
    std::cout << "--= Luck: " << luck <<  " =--" << std::endl;
    std::cout << std::endl;
}

void Character::levelUp() {
    while (exp >= expNext) {
        exp -= expNext;
        level++;

        this->expNext = calculateNextExp( level);
    }
    this->statPoints++;
    this->skillPoints++;
}
