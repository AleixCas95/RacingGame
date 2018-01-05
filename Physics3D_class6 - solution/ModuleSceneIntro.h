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
	bool collision = false;
	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);


	PhysBody3D* Createconstraint(Cube &cube, vec3 size, vec3 pos, float angle);
	PhysBody3D* Createengine(Cylinder &cylinder, vec3 pos, float angle);

public:

	Cube constraint1;
	PhysBody3D *constraint_1;

	Cylinder engine1;
	PhysBody3D *engine_1;

	Cube constraint2;
	PhysBody3D *constraint_2;

	Cylinder engine2;
	PhysBody3D *engine_2;

	Cube constraint3;
	PhysBody3D *constraint_3;

	Cylinder engine3;
	PhysBody3D *engine_3;

	Cube constraint4;
	PhysBody3D *constraint_4;

	Cylinder engine4;
	PhysBody3D *engine_4;

	Cube constraint5;
	PhysBody3D *constraint_5;

	Cylinder engine5;
	PhysBody3D *engine_5;


	Cube meta;

	PhysBody3D* Sensor;

	Cube s, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21;
	Cube s22, s23, s24, s25, s26, s27, s28, s29, s30, s31, s32, s33, s34, s35, s36, s37, s38, s39, s40, s41, s42;
	Cube s43, s44, s45, s46, s47, s48, s49, s50, s51, s52, s53, s54, s55, s56, s57, s58, s59, s60, s61, s62;
	Cube s63, s64, s65, s66, s67, s68, s69, s70, s71, s72, s73, s74, s75, s76, s77, s78, s79;
	Cube s80, s81, s82, s83, s84;
	Sphere s85, s86, s87, s88, s89;
	Cube s90, s91, s92, s93, s94, s95, s96, s97, s98, s99,s100,s101,s102;
	//checkpoints cube
	Cube sensormeta, checkpoint1, checkpoint2, checkpoint3, checkpoint4;

	PhysBody3D *sensor85, *sensor86, *sensor87, *sensor88, *sensor89;

	PhysBody3D *sensormeta1, *sensorcheckpoint1,*sensorcheckpoint2,*sensorcheckpoint3, *sensorcheckpoint4;

	Timer lap_timer;

	int laps = 0;
	int fastlap;
	int checkpoint = 0;

	uint checkpoint_fx;
	uint meta_fx;
	
};
