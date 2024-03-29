#ifdef _WIN32

#include <windows.h>
#include <cstdio> // stdio.h deprecated ?
#include <tchar.h>
#define GLEW_BUILD
#include <glew.h>

#endif

#ifdef linux
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// TODO: include this file (& link ?)
#define GL3_PROTOTYPES 1
#include <gl3.h>
#endif

/// SDL & STL headers
#include <SDL.h>
#include <iostream>

/// OpenGL Headers

/// Core Headers
#include <managers/Manager.h>
#include <systems/Physics2D.h>
#include <scenes/SceneOpenGL.h>
#include <managers/TransformManager.h>

// TODO: when setting a new Entity instance in map, check if it already exists !
// TODO: as i want to make it a kin of API, this class only exists in a debug/test context
class SparkEngine
{
public:
    void init();
};

int main(int argc, char **argv)
{
//    SceneOpenGL* sceneOpenGL = new SceneOpenGL(); // Can customize params !
//    sceneOpenGL->init();

    SparkEngine sparkEngine;
    sparkEngine.init();

    return 0;
}
void SparkEngine::init()
{

    auto entityManager = new EntityManager();
    auto systemManager = new SystemManager();
    auto manager = new Manager(10);

    size_t loaded_entities = manager->loadEntities(entityManager);
    std::cout << "Loaded Entities: " << loaded_entities << std::endl;

    size_t loaded_systems = manager->loadSystems(systemManager);
    std::cout << "Loaded Systems: " << loaded_systems << std::endl;

    /// TEST Systems
    auto system = systemManager->create<Physics2D>(manager->data(), Position); // id & mask defined in
    system->setName("CustomSystem");
    manager->setSystem(system);

    for (auto &id : manager->sys()->reg_systems)
    {
        std::cout << "System Name : " << manager->sys()->systems[id]->name() << std::endl;
    }

//    manager->destroyS(0);
//    manager->destroyS(4);
//    manager->destroyS(4);

    // TODO: Modify destroyEC method to properly delete an entity

//    manager->destroyEC(1);
    manager->destroyEC(2);
//    manager->destroyEC(3);
//    manager->destroyEC(4);
//    manager->destroyEC(5);
    manager->destroyEC(6);
    manager->destroyEC(5);

    manager->simulate();
    manager->save();

    for(auto& x : manager->entity_instances)
    {
        std::cout << "E = " << x.first << " ; " << " I = " << x.second << std::endl;
    }

    std::cout << "Instance_IDs | ";
    for(auto& op : manager->instance_ids)
    {
        std::cout << op << " | ";
    }
    std::cout << std::endl;

}