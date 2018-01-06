#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "Timer.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	//sounds
	checkpoint_fx = App->audio->LoadFx("RacingGame/checkpoint_fx.wav");
	meta_fx = App->audio->LoadFx("RacingGame/meta_fx.wav");

	//meta
	sensormeta.size = vec3(15, 15, 1);
	sensormeta.SetPos(0, 0, -20);
	sensormeta1 = App->physics->AddBody(sensormeta, 0.0f);
	sensormeta1->SetAsSensor(true);
	sensormeta1->collision_listeners.add(this);

	s100 = App->physics->CreateCube(1,5,1, 5.2f,7,-20, 0.0f, Green);
	s101 = App->physics->CreateCube(1, 5, 1, -5, 7, -20, 0.0f, Green);
	s102 = App->physics->CreateCube(11.3f, 1, 1, 0.1f, 10, -20, 0.0f, Green);

	checkpoint1.size = vec3(1, 15, 15);
	checkpoint1.SetPos(130, 2, 66.5f);
	sensorcheckpoint1 = App->physics->AddBody(checkpoint1, 0.0f);
	sensorcheckpoint1->SetAsSensor(true);
	sensorcheckpoint1->collision_listeners.add(this);


	checkpoint2.size = vec3(1, 15, 15);
	checkpoint2.SetPos(158.4f, 2, 166.1f);
	sensorcheckpoint2 = App->physics->AddBody(checkpoint2, 0.0f);
	sensorcheckpoint2->SetAsSensor(true);
	sensorcheckpoint2->collision_listeners.add(this);

	checkpoint3.size = vec3(15,15,1);
	checkpoint3.SetPos(-132.7f, 2, 96);
	sensorcheckpoint3 = App->physics->AddBody(checkpoint3, 0.0f);
	sensorcheckpoint3->SetAsSensor(true);
	sensorcheckpoint3->collision_listeners.add(this);

	checkpoint4.size = vec3(1, 15, 15);
	checkpoint4.SetPos(-82.7f, 2, -99);
	sensorcheckpoint4 = App->physics->AddBody(checkpoint4, 0.0f);
	sensorcheckpoint4->SetAsSensor(true);
	sensorcheckpoint4->collision_listeners.add(this);
	
	//constraint
	constraint_1 = Createconstraint(constraint1, vec3(1, 16, 3), vec3(-161.7f, 11, 26), 90);
	engine_1 = Createengine(engine1, vec3(-161.7f, 11, 28), 90);
	App->physics->AddConstraintHinge(*engine_1, *constraint_1, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0), true, true);

	constraint_2 = Createconstraint(constraint2, vec3(1, 16, 3), vec3(-161.7f, 11, -52), 90);
	engine_2 = Createengine(engine2, vec3(-161.7f, 11, -50), 90);
	App->physics->AddConstraintHinge(*engine_2, *constraint_2, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0), true, true);

	constraint_3 = Createconstraint(constraint3, vec3(1, 16, 3), vec3(-122.7f, 11, -25), 90);
	engine_3 = Createengine(engine3, vec3(-122.7f, 11, -27), 90);
	App->physics->AddConstraintHinge(*engine_3, *constraint_3, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0), true, true);

	constraint_4 = Createconstraint(constraint4, vec3(1, 16, 3), vec3(10, 11, 175), 180);
	engine_4 = Createengine(engine4, vec3(10, 11, 175), 180);
	App->physics->AddConstraintHinge(*engine_4, *constraint_4, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0), true, true);

	constraint_5 = Createconstraint(constraint5, vec3(1, 16, 3), vec3(30, 11, 175), 190);
	engine_5 = Createengine(engine5, vec3(30, 11, 175), 0);
	App->physics->AddConstraintHinge(*engine_5, *constraint_5, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0), true, true);


	//generalcubes
	s = App->physics->CreateCube(10, 1, 150, 0, 2.5f, 20,0.0f, Green);
	s1 = App->physics->CreateCube(1, 2, 150, -5, 3.5f, 20, 0.0f,Purple);
	s2 = App->physics->CreateCube(1, 2, 150, 5.2f, 3.5f, 20,0.0f, Purple);
	s3 = App->physics->CreateCubeXrotation(1, 2, 20, 11, 3.5f, 103,0.0f, Purple, 36);
	s4 = App->physics->CreateCubeXrotation(1, 2, 20, 0, 3.5f, 104,0.0f, Purple, 30);
	s5 = App->physics->CreateCubeXrotation(9, 2, 25, 5, 2, 103,0.0f, Green, 35);
	s6 = App->physics->CreateCubeXrotation(1, 2, 30, 16.8f, 3.5f, 122,0.0f, Purple, 52);
	s7 = App->physics->CreateCubeXrotation(1, 2, 18, 24.1f, 3.5f, 115.8f,0.0f, Purple, 56);
	s8 = App->physics->CreateCubeXrotation(10, 2, 25, 20.7f, 2, 119,0.0f, Green, 55);
	s9 = App->physics->CreateCubeXrotation(11, 2, 70, 62, 2, 126, 0.0f,Green, 270);
	s10 = App->physics->CreateCubeXrotation(1, 2, 70, 62.8f, 3.5f, 131, 0.0f, Purple, 270);
	s11 = App->physics->CreateCubeXrotation(1, 2, 65, 63.8f, 3.5f, 120.7f,0.0f, Purple, 270);
	s12 = App->physics->CreateCube(11, 2, 60, 102.5f, 2, 101,0.0f, Green);
	s13 = App->physics->CreateCubeXrotation(1, 2, 10, 102.8f, 3.5f, 131, 0.0f, Purple, 270);
	s14 = App->physics->CreateCube(1, 2, 58, 108.3f, 3.5f, 102.6f, 0.0f, Purple);
	s15 = App->physics->CreateCube(1, 2, 60, 96.7f, 3.5f, 91.2f, 0.0f, Purple);
	s16 = App->physics->CreateCubeXrotation(9, 2, 30, 112, 2, 66.5f, 0.0f, Green, 90);
	s17 = App->physics->CreateCubeXrotation(2.5f, 2, 20, 117.8f, 3.5f, 72.2f, 0.0f, Purple, 90);
	s18 = App->physics->CreateCubeXrotation(1, 2, 80, 136, 3.5f, 61.7f, 0.0f, Purple, 90);
	s19 = App->physics->CreateCubeXrotation(9, 2, 50, 152, 2, 66.5f, 0.0f, Green, 90);
	s20 = App->physics->CreateCube(9, 2, 80, 172.6f, 2, 111,0.0f,Green);
	s21 = App->physics->CreateCubeXrotation(2.5f, 2, 40, 147.8f, 3.5f, 72.2f,0.0f, Purple, 90);
	s22 = App->physics->CreateCube(1, 2, 80, 176.5f, 3.5f, 101.2f,0.0f, Purple);
	s23 = App->physics->CreateCube(1, 2, 70, 168.3f, 3.5f, 106,0.0f, Purple);
	s24 = App->physics->CreateCube(1, 2, 10, 168.3f, 3.5f, 145,0.0f, Purple);
	s25 = App->physics->CreateCube(1, 2, 10, 176.5f, 3.5f, 145,0.0f, Purple);
	s26 = App->physics->CreateCubeXrotation(9, 2, 15, 169.2f, 2, 156,0.0f, Green, -30);
	s27 = App->physics->CreateCubeXrotation(1, 2, 10, 174.6f, 3.5f, 154.2f,0.0f, Purple, -23);
	s28 = App->physics->CreateCubeXrotation(1, 2, 10, 165.7f, 3.5f, 154,0.0f, Purple, -32);
	s29 = App->physics->CreateCubeXrotation(9, 2, 20, 158.4f, 2, 166.1f,0.0f, Green, -60);
	s30 = App->physics->CreateCubeXrotation(1, 2, 5, 171.5f, 3.5f, 160.5f, 0.0f, Purple, -34);
	s31 = App->physics->CreateCubeXrotation(1, 2, 20, 154.6f, 3.5f, 163,0.0f, Purple, -60);
	s32 = App->physics->CreateCubeXrotation(1, 2, 20, 162.1f, 3.5f, 168.3f,0.0f, Purple, -55);
	s33 = App->physics->CreateCubeXrotation(20, 2, 300, -20, 2, 175,0.0f, Green, -90);
	s34 = App->physics->CreateCubeXrotation(8, 2, 15, 145, 2, 171,0.0f, Green, -90);
	s35 = App->physics->CreateCubeXrotation(20, 2, 10, 136, 2, 176.5f,0.0f, Green, 30);
	s36 = App->physics->CreateCubeXrotation(10, 2, 10, 133.5f, 2, 171,0.0f, Green, -13);
	s37 = App->physics->CreateCubeXrotation(1, 2, 20, 144.6f, 3.5f, 177.4f,0.0f, Purple, -70);
	s38 = App->physics->CreateCubeXrotation(3, 2, 7, 148, 2, 175,0.0f, Green, -70);
	s39 = App->physics->CreateCubeXrotation(1, 2, 17, 137.8f, 3.5f, 166.51f,0.0f, Purple, -100);
	s40 = App->physics->CreateCubeXrotation(1, 2, 9, 132.3f, 3.5f, 181.9f,0.0f, Purple, -70);
	s41 = App->physics->CreateCubeXrotation(1, 2, 300, -21.6f, 3.5f, 183.4f,0.0f, Purple, -90);
	s42 = App->physics->CreateCubeXrotation(1, 2, 300, -20.5f, 3.5f, 165.045f,0.0f, Purple, -90);
	s43 = App->physics->CreateCubeXrotation(13, 2, 13, -170, 2, 176,0.0f, Green, -130);
	s44 = App->physics->CreateCubeXrotation(13, 2, 15, -175, 2, 170,0.0f, Green, 125);
	s45 = App->physics->CreateCubeXrotation(1, 2, 19, -178, 3.5f, 177.2f,0.0f, Purple, -135);
	s46 = App->physics->CreateCubeXrotation(1, 2, 6, -172.2f, 3.5f, 163,0.0f, Purple, -135);
	s47 = App->physics->CreateCubeXrotation(13, 2, 15, -180, 2, 162,0.0f, Green, -170);
	s48 = App->physics->CreateCubeXrotation(1, 2, 15, -185.9f, 3.5f, 163.3f,0.0f, Purple, -170);
	s49 = App->physics->CreateCubeXrotation(1, 2, 7, -174.767f, 3.5f, 157.7f,0.0f, Purple, -170);
	s50 = App->physics->CreateCube(13, 2, 30, -181.3f, 2, 141,0.0f, Green);
	s51 = App->physics->CreateCubeXrotation(10, 2, 50, -162.7f, 2, 121,0.0f, Green, 90);
	s52 = App->physics->CreateCube(1, 2, 41, -187.2f, 3.5f, 136,0.0f, Purple);
	s53 = App->physics->CreateCube(1, 2, 28, -175.2f, 3.5f, 140.7f,0.0f, Purple);
	s54 = App->physics->CreateCubeXrotation(1, 2, 50, -162.3f, 3.5f, 116,0.0f, Purple, 90);
	s55 = App->physics->CreateCubeXrotation(1, 2, 40, -155.7f, 3.5f, 126.4f,0.0f, Purple, 90);
	s56 = App->physics->CreateCube(10, 2, 60, -132.7f, 2, 96,0.0f, Green);
	s57 = App->physics->CreateCube(1, 2, 60, -127.7f,3.5f,96.4f,0.0f, Purple);
	s58 = App->physics->CreateCube(1, 2, 50, -137,3.5f,91.5f,0.0f, Purple);
	s59 = App->physics->CreateCubeXrotation(1, 2, 10, -132.2f, 3.5f, 126.4f,0.0f, Purple, 90);
	s60 = App->physics->CreateCubeXrotation(10, 2, 30, -142.7f, 2, 61,0.0f, Green,90);
	s61 = App->physics->CreateCube(1, 2, 10, -127.7f, 3.5f, 61.4f,0.0f, Purple);
	s62 = App->physics->CreateCubeXrotation(1, 2, 20, -146.5f, 3.5f, 66,0.0f, Purple, 90);
	s63 = App->physics->CreateCubeXrotation(1, 2, 30, -142.2f, 3.5f, 55.9f, 0.0f,Purple, 90);
	s64 = App->physics->CreateCube(10, 2, 60, -162.7f, 2, 35.9f, 0.0f,Green);
	s65 = App->physics->CreateCubeXrotation(10, 2, 30, -142.8f, 2, 10.88f,0.0f, Green, 90);
	s66 = App->physics->CreateCube(10, 2, 60, -122.8f, 2, -14, 0.0f,Green);
	s67 = App->physics->CreateCubeXrotation(10, 2, 30, -142.7f, 2, -39,0.0f, Green, 90);
	s68 = App->physics->CreateCube(10, 2, 60, -162.7f, 2, -64, 0.0f,Green);
	s69 = App->physics->CreateCubeXrotation(10, 2, 170, -82.7f, 2, -99, 0.0f,Green, 90);
	s70 = App->physics->CreateCubeXrotation(1, 2, 170, -82.7f, 3.5, -104, 0.0f,Purple, 90);
	s71 = App->physics->CreateCubeXrotation(1, 2, 140, -87.7f, 3.5, -94, 0.0f, Purple, 90);
	s72 = App->physics->CreateCubeYrotation(10, 2, 20, -122.8f, 0.30f, 25.8f, 0.0f, Green, 10 );
	s73 = App->physics->CreateCubeYrotation(10, 2, 20, -162.7f, 0.30f, 75.4f, 0.0f, Green, 10 );
	s74 = App->physics->CreateCube(10, 1, 50, 0, 2.5f, -79, 0.0f, Green);
	s75 = App->physics->CreateCube(1, 2, 50, 5.2f, 3.5f, -79, 0.0f, Purple);
	s76 = App->physics->CreateCube(1, 2, 30, -5, 3.5f, -70, 0.0f, Purple);
	s77 = App->physics->CreateCubeXrotation(1, 2, 140, -64.3f, 3.5f, -104, 0.0f, Purple, 90);
	s78 = App->physics->CreateCube(1, 2, 10, -5, 3.5f, -89, 0.0f, Purple);
	s79 = App->physics->CreateCubeXrotation(1, 2, 140, -74.5f, 3.5, -94, 0.0f, Purple, 90);
	s80 = App->physics->CreateCube(50, 2, 400, 200, 0, 0, 0.0f, Brown);
	s81 = App->physics->CreateCubeXrotation(50, 2, 400, 0, 0, 200, 0.0f, Brown, 90);
	s82 = App->physics->CreateCubeXrotation(50, 2, 400, 0, 0, -200, 0.0f, Brown, 90);
	s83 = App->physics->CreateCube(50, 2, 400,-200, 0, 0, 0.0f, Brown);
	s84 = App->physics->CreateCube(350, 2, 350, 0, 0, 0, 0.0f, Lightblue);
	s90 = App->physics->CreateCube(1, 3, 5, -35, 4.5f, 179, 0.0f, Brown);
	s91 = App->physics->CreateCube(1, 3, 5, 45, 4.5f, 179, 0.0f, Brown);
	s92 = App->physics->CreateCube(1, 3, 5, -60, 4.5f, 179, 0.0f, Brown);
	s93 = App->physics->CreateCube(1, 3, 5, -125, 4.5f, 179, 0.0f, Brown);
	s94 = App->physics->CreateCube(1, 3, 5, 80, 4.5f, 179, 0.0f, Brown);
	s95 = App->physics->CreateCube(1, 3, 5, -35, 4.5f, 168.5f, 0.0f, Brown);
	s96 = App->physics->CreateCube(1, 3, 5, 45, 4.5f, 168.5f, 0.0f, Brown);
	s97 = App->physics->CreateCube(1, 3, 5, -110, 4.5f, 168.5f, 0.0f, Brown);
	s98 = App->physics->CreateCube(1, 3, 5, -125, 4.5f, 168.5f, 0.0f, Brown);
	s99 = App->physics->CreateCube(1, 3, 5, 80, 4.5f, 168.5f, 0.0f, Brown);

	s85.radius = 3;
	s85.color = Red;
	s86.radius = 3;
	s86.color = Red;
	s87.radius = 3;
	s87.color = Red;
	s88.radius = 3;
	s88.color = Red;
	s89.radius = 3;
	s89.color = Red;

	s85.SetPos(-20, 2, 173);
	s86.SetPos(50, 2, 173);
	s87.SetPos(-70, 2, 173);
	s88.SetPos(-100, 2, 173);
	s89.SetPos(90, 2, 173);


	sensor85 = App->physics->AddBody(s85, 0.0f);
	sensor85->SetAsSensor(false);
	sensor85->collision_listeners.add(this);

	sensor86 = App->physics->AddBody(s86, 0.0f);
	sensor86->SetAsSensor(false);
	sensor86->collision_listeners.add(this);

	sensor87 = App->physics->AddBody(s87, 0.0f);
	sensor87->SetAsSensor(false);
	sensor87->collision_listeners.add(this);

	sensor88 = App->physics->AddBody(s88, 0.0f);
	sensor88->SetAsSensor(false);
	sensor88->collision_listeners.add(this);

	sensor89 = App->physics->AddBody(s89, 0.0f);
	sensor89->SetAsSensor(false);
	sensor89->collision_listeners.add(this);


	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	//constraints
	constraint1.Render();
	constraint_1->GetTransform(&constraint1.transform);
	constraint2.Render();
	constraint_2->GetTransform(&constraint2.transform);
	constraint3.Render();
	constraint_3->GetTransform(&constraint3.transform);
	constraint4.Render();
	constraint_4->GetTransform(&constraint4.transform);
	constraint5.Render();
	constraint_5->GetTransform(&constraint5.transform);

	//circuito
	s100.Render();
	s101.Render();
	s102.Render();
	s.Render();
	s1.Render();
	s2.Render();
	s3.Render();
	s4.Render();
	s5.Render();
	s6.Render();
	s7.Render();
	s8.Render();
	s9.Render();
	s10.Render();
	s11.Render();
	s12.Render();
	s13.Render();
	s14.Render();
	s15.Render();
	s16.Render();
	s17.Render();
	s18.Render();
	s19.Render();
	s20.Render();
	s21.Render();
	s22.Render();
	s23.Render();
	s24.Render();
	s25.Render();
	s26.Render();
	s27.Render();
	s28.Render();
	s29.Render();
	s30.Render();
	s31.Render();
	s32.Render();
	s33.Render();
	s34.Render();
	s35.Render();
	s36.Render();
	s37.Render();
	s38.Render();
	s39.Render();
	s40.Render();
	s41.Render();
	s42.Render();
	s43.Render();
	s44.Render();
	s45.Render();
	s46.Render();
	s47.Render();
	s48.Render();
	s49.Render();
	s50.Render();
	s51.Render();
	s52.Render();
	s53.Render();
	s54.Render();
	s55.Render();
	s56.Render();
	s57.Render();
	s58.Render();
	s59.Render();
	s60.Render();
	s61.Render();
	s62.Render();
	s63.Render();
	s64.Render();
	s65.Render();
	s66.Render();
	s67.Render();
	s68.Render();
	s69.Render();
	s70.Render();
	s71.Render();
	s72.Render();
	s73.Render();
	s74.Render();
	s75.Render();
	s76.Render();
	s77.Render();
	s78.Render();
	s79.Render();
	s80.Render();
	s81.Render();
	s82.Render();
	s83.Render();
	s84.Render();
	s85.Render();
	s86.Render();
	s87.Render();
	s88.Render();
	s89.Render();
	s90.Render();
	s91.Render();
	s92.Render();
	s93.Render();
	s94.Render();
	s95.Render();
	s96.Render();
	s97.Render();
	s98.Render();
	s99.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	if ((body1 == sensormeta1) && (collision == false))
	{
		App->audio->PlayFx(meta_fx);
		App->player->timelap[laps] = (App->scene_intro->lap_timer.Read() / 1000) + (App->player->minutes * 60);
		if (laps <= 1)fastlap = App->player->timelap[laps];
		else if ((laps > 1) && (fastlap>(App->player->timelap[laps])))
		{
			fastlap = App->player->timelap[laps];
		}
		App->player->minutes = 0;
		App->scene_intro->lap_timer.Start();
		checkpoint = 0;
		laps = laps + 1;
		collision = true;
	}



	if (body1 == sensorcheckpoint1) 
	{
		App->audio->PlayFx(checkpoint_fx);
		checkpoint = 1;
		collision = false;
	}

	if(body1 == sensorcheckpoint2) 
	{
		App->audio->PlayFx(checkpoint_fx);
		checkpoint = 2;
	}

	if (body1 == sensorcheckpoint3)
	{
		App->audio->PlayFx(checkpoint_fx);
		checkpoint = 3;
	}

	if (body1 == sensorcheckpoint4) 
	{
		App->audio->PlayFx(checkpoint_fx);
		checkpoint = 4;
	}

	LOG("Hit!");
}

PhysBody3D* ModuleSceneIntro::Createconstraint(Cube &cube, vec3 size, vec3 pos, float angle) {

	PhysBody3D* wall_pbody;
	cube.size = size;
	cube.SetPos(pos.x, pos.y, pos.z);
	cube.SetRotation(angle, vec3(0, 1, 0));
	cube.color = Blue;
	wall_pbody = App->physics->AddBody(cube, 10000.0f);
	wall_pbody->GetBody()->setLinearFactor(btVector3(0, 0, 0));
	return wall_pbody;
}

PhysBody3D* ModuleSceneIntro::Createengine(Cylinder &cylinder, vec3 pos, float angle) {

	PhysBody3D* wall_pbody;
	cylinder.height = 2;
	cylinder.radius = 0.1f;
	cylinder.SetPos(pos.x, pos.y, pos.z);
	cylinder.SetRotation(angle, vec3(0, 1, 0));
	wall_pbody = App->physics->AddBody(cylinder, 10000.0f);
	wall_pbody->GetBody()->setLinearFactor(btVector3(0, 0, 0));
	return wall_pbody;
}
