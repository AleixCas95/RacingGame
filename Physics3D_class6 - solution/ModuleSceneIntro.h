#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:
	Cube s, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21;
	
	PhysBody3D* sensor, *sensor1, *sensor2, *sensor3, *sensor4, *sensor5, *sensor6, *sensor7, *sensor8, *sensor9, *sensor10, *sensor11, *sensor12, *sensor13, *sensor14;
	PhysBody3D* sensor15, *sensor16, *sensor17, *sensor18, *sensor19, *sensor20, *sensor21;
	
};
