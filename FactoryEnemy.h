#ifndef FACTORYENEMY_H
#define FACTORYENEMY_H

#include "redEnemy.h"
#include "greenenemy.h"

Enemy * getEnemy(const int & _type) {
    Enemy * enemy = nullptr;

    if(!_type)
        enemy = new RedEnemy;
    else {
        enemy = new GreenEnemy;
    }

    return enemy;
}

#endif // FACTORYENEMY_H
