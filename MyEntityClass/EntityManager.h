#pragma once
#include "MyEntityClass.h"
class EntityManager
{
	int entityCount = 0; //number of Entites in the list
	std::vector<MyEntityClass*> m_lEntities; //list of Entities
	static EntityManager instance;
	static EntityManager* m_pInstance;
	EntityManager* pEntityMngr;

	EntityManager();
	~EntityManager();
public:
	static EntityManager* getInstance();
	static void ReleaseInstance(void);
	//void AddEntity(std::vector<vector3> list, String a_sName);

private:

	EntityManager(void);

	EntityManager(EntityManager const& other);

	EntityManager& operator=(EntityManager const& other);

	~EntityManager(void);

	void Release(void);

	void Init(void);


};

