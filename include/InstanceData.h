//
// Created by Sp4rk on 26-09-17.
//

#ifndef CLIKEECS_INSTANCEDATA_H
#define CLIKEECS_INSTANCEDATA_H

#include <iostream>

#include "Vector3.h"
#include "Entity.h"
#include "Sprite.h"
#include "Transform.h"
#include <set>

const unsigned int MAX_ENTITY_REGISTERING = 1 << ENTITY_INDEX_BITS;

struct InstanceData
{
    unsigned size = 0; ///< Number of used instances
    unsigned capacity = 0; ///< Number of allocated instances
    void *buffer = nullptr; ///< Buffer with instance data

    std::set<size_t> reg_entities;

    Entity *entity = nullptr;
    float *mass = nullptr;
    Vector3 *position = nullptr;
    Vector3 *velocity = nullptr;
    Vector3 *acceleration = nullptr;
    // TODO: review this code & all dependencies
//    Transform *transform = nullptr;
    Sprite2D *sprite = nullptr;
};

#endif //CLIKEECS_INSTANCEDATA_H
