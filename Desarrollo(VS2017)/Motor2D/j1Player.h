#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "j1Module.h"
#include "j1Animation.h"
#include "p2Point.h"
#include "p2Log.h"
#include "j1Entity.h"
#include "j1EntityManager.h"

struct SDL_Texture;

struct input {	
	bool pressing_A;
	bool pressing_S;
	bool pressing_D;
	bool pressing_W;
	bool pressing_SPACE;
	bool pressing_F;
	bool pressing_E;
	bool pressing_Q;
};

enum states {
	IDLE,
	DASH,
	FORWARD,
	DEATH,
	BACKWARD,
	JUMP,
	JUMP_FORWARD,
	JUMP_BACKWARD,
	ATTACK_E,
	DEAD,
	KICK
};

struct PlayerInfo
{
	Animation*		current_animation=&idle;
	Animation idle;
	Animation walk;
	Animation jump;
	Animation death;
	Animation voltereta;
	Animation attack;
	Animation kick;

	Animation idle2;
	Animation walk2;
	Animation jump2;
	Animation death2;
	Animation voltereta2;
	Animation attack2;
	Animation kick2;

    iPoint position;
	iPoint Initial_position;

	p2SString		Death_Effect;
	p2SString		Jump_Effect;

	pugi::xml_document playerdoc;
	pugi::xml_node playernode;

    input Input; 

	SDL_Texture*	Tex_Player;

	//PLAYER, AND WORLD MAX VELOCITIES
	int				Spawn_X;
	int				Spawn_Y;
	float			World_Gravity = 0.42;
	float			Speed_X = 3.75;
	float			Speed_Y = 7.0;
	float			Dash_Speed = 7.25;
	float			Reducction_Speed = 0.75;
	float		    MAX_X = 4.0;
	float			MAX_Y = 15.0;
	float		    MAX_JUMP = 9;
	fPoint		    velocity;


	
	bool            Looking_Forward = true;
	bool			Can_Input = true;
	bool			Alive = true;
	bool			Dash = false;
	bool            Grounded = true;
	bool            God_Mode = false;

	Uint32		dash_timer;
	int		    dashTime = 395;
	bool		dashTimer = false;

	//Attack timer
	Uint32		attack_timer;
	bool        attacking = false;
	int		    attackTime = 590;
	bool		attackTimer = false;

	Uint32		death_timer;
	int		    deathTime = 460;
	bool		deathTimer = false;

	//PLAYER GOD-MODE
	bool GodMode = false;
	bool GodModeForward = false;
	bool GodModeBackward = false;
	bool GodModeUp = false;
	bool GodModeDown = false;

	
	Collider * playerhead = nullptr;
	Collider * playerbody = nullptr;
	Collider * playerfeet = nullptr;
	Collider * playerattack = nullptr;

};

class j1Player : public j1Entity
{
public:
	j1Player();
	j1Player(iPoint pos);
	~j1Player();

	bool Awake(pugi::xml_node&);
	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool CleanUp();
	void Pushbacks();
	//LOADING AND SAVING OPTIONS
	bool Save(pugi::xml_node& data);
	bool Load(pugi::xml_node& data);	
	
	//COLLISION MANAGER
	void OnCollision(Collider* c1, Collider* c2);

	//PLAYER STATE MANAGER
	void Player_Position();
	void Player_State_Machine();
	void Set_Player_State(states state);
	void Restart();

public:
	
	std::string		current_points;
	uint			score;
	p2SString	folder;
	pugi::xml_node	node;
	PlayerInfo playerinfo;
	input Input;
	p2SString file;
	bool keyup = true;
	SDL_Texture* graphics = nullptr;
	//STATES DOEN'T WORK INSIDE PLAYERINFO. SO THATS WHY ITS IN HERE
	states state;

	
};

#endif