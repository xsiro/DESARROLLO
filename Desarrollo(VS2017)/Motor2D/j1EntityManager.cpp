#include "j1EntityManager.h"
#include "j1Entity.h"
#include "j1App.h"
#include "j1Player.h"
#include "p2Log.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "j1Input.h"
#include "j1Collision.h"
#include "j1Window.h"
#include "j1Scene.h"
#include "j1Map.h"
#include "j1Audio.h"


j1EntityManager::j1EntityManager()
{
	name.create("entityManager");
}


j1EntityManager::~j1EntityManager()
{}

j1Entity* j1EntityManager::CreateEntity(Entity_Class type)
{
	j1Entity* entity = nullptr;
	switch (type)
	{
	case Entity_Class::PLAYER:
		break;
	case Entity_Class::FLYING_ENEMY:
		break;
	case Entity_Class::GROUND_ENEMY:
		break;
	default:
		break;
	}
	entities.add(entity);
	return entity;
}

void j1EntityManager::DestroyEntity(j1Entity* delete_entity)
{
	RELEASE(delete_entity);
}

bool j1EntityManager::Awake(pugi::xml_node& config)
{
	bool ret = true;

	return ret;
}

bool j1EntityManager::Start()
{
	bool ret = true;
	return ret;
}

bool j1EntityManager::PreUpdate()
{
	bool ret = true;
	return ret;
}

bool j1EntityManager::Update(float dt)
{
	bool ret = true;
	return ret;
}

bool j1EntityManager::PostUpdate()
{
	bool ret = true;
	return ret;
}

bool j1EntityManager::CleanUp()
{
	bool ret = true;
	return ret;
}

void j1EntityManager::OnCollision(Collider* c1, Collider* c2) {
}

bool j1EntityManager::Load(pugi::xml_node& data)
{
	bool ret = true;
	return ret;
}

bool j1EntityManager::Save(pugi::xml_node& data)
{
	bool ret = true;
	return ret;
}