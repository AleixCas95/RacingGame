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
	Cube s22, s23, s24, s25, s26, s27, s28, s29, s30, s31, s32, s33, s34, s35, s36, s37, s38, s39, s40, s41, s42;
	Cube s43, s44, s45, s46, s47, s48, s49, s50, s51, s52, s53, s54, s55, s56, s57, s58, s59, s60, s61, s62;

	PhysBody3D* sensor, *sensor1, *sensor2, *sensor3, *sensor4, *sensor5, *sensor6, *sensor7, *sensor8, *sensor9, *sensor10, *sensor11, *sensor12, *sensor13, *sensor14;
	PhysBody3D* sensor15, *sensor16, *sensor17, *sensor18, *sensor19, *sensor20, *sensor21, *sensor22, *sensor23, *sensor24, *sensor25, *sensor26, *sensor27, *sensor28;
	PhysBody3D* sensor29, *sensor30, *sensor31, *sensor32, *sensor33, *sensor34, *sensor35, *sensor36, *sensor37, *sensor38, *sensor39, *sensor40, *sensor41, *sensor42;
	PhysBody3D* sensor43, *sensor44, *sensor45, *sensor46, *sensor47, *sensor48, *sensor49, *sensor50, *sensor51, *sensor52, *sensor53, *sensor54, *sensor55, *sensor56;
	PhysBody3D *sensor57, *sensor58, *sensor59, *sensor60, *sensor61, *sensor62;
};
