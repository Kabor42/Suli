//
// Created by kabor on 2018.03.01..
//

#ifndef CONSOLERPG_CHARACTER_H
#define CONSOLERPG_CHARACTER_H

#include "inventory.hpp"
#include <cmath>

class Character {
    public:
        Character();
        virtual ~Character();

        void initialize( const std::string name);
        void printStats() const;
        void levelUp();

        /** Accessors */


        inline const double& getX() const { return this->xPos; }
        inline const double& getY() const { return this->yPos; }

        inline const std::string& getName() const { return this->name; }
        inline const int& getLevel() const { return this->level; }
        inline const int& getExp() const { return this->exp; }
        inline const int& getExpNext() const { return this->expNext; }
        inline const int& getHp() const { return this->hp; }
        inline const int& getHpMax() const { return this->hpMax; }
        inline const int& getStamina() const { return this->stamina; }
        inline const int& getDamageMin() const { return this->damageMin; }
        inline const int& getDamageMax() const { return this->damageMax; }
        inline const int& getDefense() const { return this->defense; }

    private:
        double xPos; /** Player X position */
        double yPos; /** Player Y position */

        std::string name; /** Player's name */
        int level;  /** Player's current level */
        int exp;    /** Player's current experience */
        int expNext;    /** Experience needed to level up */
        int hp;         /** Player's current health */
        int hpMax;  /** Player's max health */
        int stamina;    /** Player's current stamina */
        int staminaMax; /** Players max stamina */
        int damageMin;  /** Player's min possible damage */
        int damageMax;  /** Player's max possible damage */
        int defense;    /** Player's current defense points */
        int luck;

        int statPoints;
        int skillPoints;

        int strength;
        int vitality;
        int dexterity;
        int intelligence;

};


#endif //CONSOLERPG_CHARACTER_H
