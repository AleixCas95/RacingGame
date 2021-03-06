#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 1000.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

public:

	int minutes = 0;
	int timelap[50];
	int fastlapminutes = 0;
	int fastlapseconds = 0;
	uint spawn_fx;

	PhysVehicle3D* vehicle;
	float turn;
	float acceleration;
	mat4x4 matrix;
	vec3 position;
	vec3 cameraPos;
	float brake;
};