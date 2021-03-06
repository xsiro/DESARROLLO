#ifndef __j1ENTITY_H__
#define __j1ENTITY_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Animation.h"
#include "p2DynArray.h"
#include "j1Module.h"

struct SDL_Texture;
struct Collider;

class j1Entity : public j1Module
{

public:
	enum class Types
	{
		PLAYER,
		SKELETON,
		FLYING_ENEMY,
		COIN,
		NULL_ENTITY
	};

	Types entity_type;
	j1Entity(Types type);

	virtual ~j1Entity();

	bool Load(pugi::xml_node& data);
	bool Save(pugi::xml_node& data) const;

	virtual void Pushbacks();
	virtual void OnCollision(Collider* c1, Collider* c2);
	virtual void GetPosition();
	virtual void Restart();
	virtual bool CleanUp();

	iPoint			position;
	int				SpawnPointX, SpawnPointY;
	bool			Looking_Forward = true;
	bool			Can_input = true;
	bool			Alive = true;
	bool			Grounded = true;
	
	Collider* collider = nullptr;
	SDL_Texture* Character_tex = nullptr;
	SDL_Texture* Asset_tex = nullptr;
	p2SString		entity_name;
	
};

#endif
