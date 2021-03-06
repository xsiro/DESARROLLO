#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "j1Module.h"
#include "p2Point.h"
#include "j1Entity.h"

struct SDL_Texture;
class j1GUIelement;

struct InGameMenu {

	j1GUIelement* image = nullptr;
	j1GUIelement* return_button = nullptr;
	j1GUIelement* resume_button = nullptr;
	j1GUIelement* volume_scroll = nullptr;
};

class j1Scene : public j1Module
{
public:

	j1Scene();

	// Destructor
	virtual ~j1Scene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Load / Save
	bool Load(pugi::xml_node&);
	bool Save(pugi::xml_node&) const;

	bool Change_Map(int map);
	int actual_map = 3;

public:

	bool Main_Menu = true;
	SDL_Texture* graphics = nullptr;
	j1Entity* skeleton;
	j1Entity* player;
	j1Entity* flying_enemy;

	iPoint Fly_Position =  { 690 , 100 };
	iPoint Skeleton_Position = {190 , 30};
	iPoint Player_Pos = { 30, 320 };

	j1GUIelement*		lifes_label = nullptr;
	j1GUIelement*		input_box = nullptr;
	InGameMenu			menu;

};

#endif // __j1SCENE_H__