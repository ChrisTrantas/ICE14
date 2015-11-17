#include "EntityManager.h"

EntityManager EntityManager::instance;
EntityManager* EntityManager::m_pInstance = nullptr;
EntityManager::EntityManager()
{
}


EntityManager::~EntityManager()
{
}

void EntityManager::Init(void)
{
	entityCount = 0;
	pEntityMngr = EntityManager::getInstance();
}

void EntityManager::Release(void)
{
	for (int entityCount = 0; entityCount < m_lEntities.size(); entityCount++)
	{
		if (m_lEntities[entityCount] != nullptr)
		{
			delete m_lEntities[entityCount];
			m_lEntities[entityCount] = nullptr;
		}
	}
	m_lEntities.clear();
}

EntityManager* EntityManager::getInstance()
{
	return &instance;
}

void EntityManager::ReleaseInstance()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

//The big 3
EntityManager::EntityManager() { Init(); }
EntityManager::EntityManager(EntityManager const& other) { }
EntityManager& EntityManager::operator=(EntityManager const& other) { return *this; }
EntityManager::~EntityManager() { Release(); };