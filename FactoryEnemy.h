#ifndef FACTORYENEMY_H
#define FACTORYENEMY_H

#include "redEnemy.h"

Enemy * getEnemy(const int & _type) {
    Enemy * enemy = nullptr;
    if(!_type)
    enemy = new RedEnemy;
    else {
        enemy = new RedEnemy;
    }


    int random_number = rand() % 3;
    if (random_number == 0)
    {
        enemy->setSpeed(10);
    }
    return enemy;
}

#endif // FACTORYENEMY_H
