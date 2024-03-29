//
// Created by Sp4rk on 26-09-17.
//

#ifndef CLIKEECS_ENTITYMANAGER_H
#define CLIKEECS_ENTITYMANAGER_H

#include <vector>
#include <deque>
#include <iostream>
#include "entities/Entity.h"
#include "managers/JSONHandler.h"

const unsigned MINIMUM_FREE_INDICES = 0;

class EntityManager
{
public:
    EntityManager()
    {
        // TODO: Change smth here?
         generation_.emplace_back(0);
    }

    Entity create(size_t mask = None);

    Entity make_entity(unsigned index, size_t mask);

    bool alive(Entity &e) const;

    void destroy(Entity &e);

private:
    std::vector<unsigned char> generation_; // size for index limit

    std::deque<unsigned int> free_indices_;
};


#endif //CLIKEECS_ENTITYMANAGER_H
