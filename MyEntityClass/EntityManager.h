#pragma once

#include "MyEntityClass.h"
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class EntityManager
{
    static EntityManager instance;

    std::vector<std::shared_ptr<MyEntityClass>> _entities;
    std::unordered_map<String, size_t> _entityCache;
    MeshManagerSingleton* _meshManager;

    EntityManager();
    ~EntityManager();

    // Hide all instance methods
    EntityManager( const EntityManager& ) = delete;
    EntityManager( EntityManager&& ) = delete;
    EntityManager& operator=( const EntityManager& ) = delete;
    EntityManager& operator=( EntityManager&& ) = delete;

public:
    /// <summary>
    /// Gets the manager instance.
    /// </summary>
    static EntityManager* GetInstance();

    /// <summary>
    /// Adds an entity to this manager.
    /// </summary>
    /// <param name="name">The entity's name.</param>
    MyEntityClass* AddEntity( String name );

    /// <summary>
    /// Updates all of the entities.
    /// </summary>
    void UpdateEntites();
};
