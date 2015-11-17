#include "EntityManager.h"

EntityManager EntityManager::instance;

// Create a new entity manager
EntityManager::EntityManager()
    : _meshManager( MeshManagerSingleton::GetInstance() )
{
}

// Destroy this entity manager
EntityManager::~EntityManager()
{
    // No need to cleanup anything
}

// Get the entity manager instance
EntityManager* EntityManager::GetInstance()
{
    return &instance;
}

// Add an entity to the manager
MyEntityClass* EntityManager::AddEntity( String name )
{
    auto entity = std::make_shared<MyEntityClass>( name );

    _entities.push_back( entity );
    _entityCache[ name ] = _entities.size() - 1;

    return entity.get();
}

// Update all of the entities
void EntityManager::UpdateEntites()
{
    for ( auto& entity : _entities )
    {
        entity->Update();
    }
}
