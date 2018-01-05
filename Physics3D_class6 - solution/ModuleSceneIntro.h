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

	Cube s, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21;
	Cube s22, s23, s24, s25, s26, s27, s28, s29, s30, s31, s32, s33, s34, s35, s36, s37, s38, s39, s40, s41, s42;
	Cube s43, s44, s45, s46, s47, s48, s49, s50, s51, s52, s53, s54, s55, s56, s57, s58, s59, s60, s61, s62;
	Cube s63, s64, s65, s66, s67, s68, s69, s70, s71, s72, s73, s74, s75, s76, s77, s78, s79;

	Cube s80, s81, s82, s83, s84;


	Sphere s85, s86, s87, s88, s89;

	Cube s90, s91, s92, s93, s94, s95, s96, s97, s98, s99;
	//checkpoints cube
	Cube sensormeta, checkpoint1, checkpoint2, checkpoint3, checkpoint4;

	PhysBody3D* sensor, *sensor1, *sensor2, *sensor3, *sensor4, *sensor5, *sensor6, *sensor7, *sensor8, *sensor9, *sensor10, *sensor11, *sensor12, *sensor13, *sensor14;
	PhysBody3D* sensor15, *sensor16, *sensor17, *sensor18, *sensor19, *sensor20, *sensor21, *sensor22, *sensor23, *sensor24, *sensor25, *sensor26, *sensor27, *sensor28;
	PhysBody3D* sensor29, *sensor30, *sensor31, *sensor32, *sensor33, *sensor34, *sensor35, *sensor36, *sensor37, *sensor38, *sensor39, *sensor40, *sensor41, *sensor42;
	PhysBody3D* sensor43, *sensor44, *sensor45, *sensor46, *sensor47, *sensor48, *sensor49, *sensor50, *sensor51, *sensor52, *sensor53, *sensor54, *sensor55, *sensor56;
	PhysBody3D *sensor57, *sensor58, *sensor59, *sensor60, *sensor61, *sensor62, *sensor63, *sensor64, *sensor65, *sensor66, *sensor67, *sensor68, *sensor69;
	PhysBody3D *sensor70, *sensor71, *sensor72, *sensor73, *sensor74, *sensor75, *sensor76, *sensor77, *sensor78, *sensor79;
	PhysBody3D *sensor80, *sensor81, *sensor82, *sensor83, *sensor84, *sensor85, *sensor86, *sensor87, *sensor88, *sensor89;
	PhysBody3D *sensor90, *sensor91, *sensor92, *sensor93, *sensor94, *sensor95, *sensor96, *sensor97, *sensor98, *sensor99;
	//checkpoints sensors
	PhysBody3D *sensormeta1, *sensorcheckpoint1,*sensorcheckpoint2,*sensorcheckpoint3, *sensorcheckpoint4;

	Timer lap_timer;

	int laps = 0;
	int fastlap;
	int checkpoint = 0;

	uint checkpoint_fx;
	uint meta_fx;
	
};
