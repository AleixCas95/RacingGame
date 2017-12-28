#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

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

	s.size = vec3(9, 1, 150);//1
	s1.size = vec3(1, 2, 150);//pdreta
	s2.size = vec3(1, 2, 150);//paretesquerra
	s3.size = vec3(1, 2, 20);//pdesquerra2
	s3.SetRotation(36, vec3(0, 1, 0));
	s4.size = vec3(1, 2, 20); //pdreta2
	s4.SetRotation(30, vec3(0, 1, 0));
	s5.size = vec3(9, 2, 25);//2
	s5.SetRotation(35, vec3(0, 1, 0));
	s6.size = vec3(1, 2, 30);//pdereta3
	s6.SetRotation(52, vec3(0, 1, 0));
	s7.size = vec3(1, 2, 18);//pesquerra3
	s7.SetRotation(56, vec3(0, 1, 0));
	s8.size = vec3(10, 2, 25);//3
	s8.SetRotation(55, vec3(0, 1, 0));
	s9.size = vec3(11, 2, 70);//4
	s9.SetRotation(270, vec3(0, 1, 0));
	s10.size = vec3(1, 2, 70);//paretderta4
	s10.SetRotation(270, vec3(0, 1, 0));
	s11.size = vec3(1, 2, 65);//pe4
	s11.SetRotation(270, vec3(0, 1, 0));
	s12.size = vec3(11, 2, 60);
	s13.size = vec3(1, 2, 10);
	s13.SetRotation(270, vec3(0, 1, 0));
	s14.size = vec3(1, 2, 58);
	s15.size = vec3(1, 2, 60);
	s16.size = vec3(9, 2, 30);
	s16.SetRotation(90, vec3(0, 1, 0));
	s17.size = vec3(2.5f, 2, 20);
	s17.SetRotation(90, vec3(0, 1, 0));
	s18.size = vec3(1, 2, 80);
	s18.SetRotation(90, vec3(0, 1, 0));
	s19.size = vec3(9, 2, 50);
	s19.SetRotation(90, vec3(0, 1, 0));
	s20.size = vec3(9, 2, 80);
	s21.size = vec3(2.5f, 2, 40);
	s21.SetRotation(90, vec3(0, 1, 0));
	s22.size = vec3(1, 2, 80);
	s23.size = vec3(1, 2, 70);
	s24.size = vec3(1, 2, 10);
	s25.size = vec3(1, 2, 10);
	s26.size = vec3(9, 2, 15);
	s26.SetRotation(-30, vec3(0, 1, 0));
	s27.size = vec3(1, 2, 10);
	s27.SetRotation(-23, vec3(0, 1, 0));
	s28.size = vec3(1, 2, 10);
	s28.SetRotation(-32, vec3(0, 1, 0));
	s29.size = vec3(9, 2, 20);
	s29.SetRotation(-60, vec3(0, 1, 0));
	s30.size = vec3(1, 2, 5);
	s30.SetRotation(-34, vec3(0, 1, 0));
	s31.size = vec3(1, 2, 20);
	s31.SetRotation(-60, vec3(0, 1, 0));
	s32.size = vec3(1, 2, 20);
	s32.SetRotation(-55, vec3(0, 1, 0));
	s33.size = vec3(20, 2, 300);
	s33.SetRotation(-90, vec3(0, 1, 0));
	s34.size = vec3(8, 2, 15);
	s34.SetRotation(-90, vec3(0, 1, 0));
	s35.size = vec3(20, 2, 10);
	s35.SetRotation(30, vec3(0, 1, 0));
	s36.size = vec3(10, 2, 10);
	s36.SetRotation(-13, vec3(0, 1, 0));
	s37.size = vec3(1, 2, 20);
	s37.SetRotation(-70, vec3(0, 1, 0));
	s38.size = vec3(3, 2, 7);
	s38.SetRotation(-70, vec3(0, 1, 0));
	s39.size = vec3(1, 2, 17);
	s39.SetRotation(-100, vec3(0, 1, 0));
	s40.size = vec3(1, 2, 9);
	s40.SetRotation(-70, vec3(0, 1, 0));
	s41.size = vec3(1, 2, 300);
	s41.SetRotation(-90, vec3(0, 1, 0));
	s42.size = vec3(1, 2, 300);
	s42.SetRotation(-90, vec3(0, 1, 0));


	s.SetPos(0, 2.5f, 20);//terro
	s1.SetPos(-5, 3.5f, 20);
	s2.SetPos(5.2f, 3.5f, 20);
	s3.SetPos(11, 3.5f, 103);
	s4.SetPos(0, 3.5f, 104);
	s5.SetPos(5, 2, 103);//2terra
	s6.SetPos(16.8f, 3.5f, 122);
	s7.SetPos(24.1f, 3.5f, 115.8f);
	s8.SetPos(20.7f, 2, 119);//3rterrra
	s9.SetPos(62, 2, 126);
	s10.SetPos(62.8f, 3.5f, 131);
	s11.SetPos(63.8f, 3.5f, 120.7f);
	s12.SetPos(102.5f, 2, 101);
	s13.SetPos(102.8f, 3.5f, 131);
	s14.SetPos(108.3f, 3.5f, 102.6f);
	s15.SetPos(96.7f, 3.5f, 91.2f);
	s16.SetPos(112, 2, 66.5f);
	s17.SetPos(117.8f, 3.5f, 72.2f);
	s18.SetPos(136, 3.5f, 61.7f);
	s19.SetPos(152, 2, 66.5f);
	s20.SetPos(172.6f, 2, 111);
	s21.SetPos(147.8f, 3.5f, 72.25f);
	s22.SetPos(176.5f, 3.5f, 101.2f);
	s23.SetPos(168.3f, 3.5f, 106);
	s24.SetPos(168.3f, 3.5f, 145);
	s25.SetPos(176.5f,3.5f, 145);
	s26.SetPos(169.2f, 2, 156);
	s27.SetPos(174.6f, 3.5f, 154.2f);
	s28.SetPos(165.7f, 3.5f, 154);
	s29.SetPos(158.4f, 2, 166.1f);
	s30.SetPos(171.5f, 3.5f, 160.5f);
	s31.SetPos(154.6f, 3.5f, 163);
	s32.SetPos(162.1f, 3.5f, 168.3f);
	s33.SetPos(-20, 2, 175);
	s34.SetPos(145, 2, 171);
	s35.SetPos(136, 2, 176.5f);
	s36.SetPos(133.5f, 2, 171);
	s37.SetPos(144.6f, 3.5f, 177.4f);
	s38.SetPos(148, 2, 175);
	s39.SetPos(137.8f, 3.5f, 166.51f);
	s40.SetPos(132.3f, 3.5f, 181.9f);
	s41.SetPos(-21.6f, 3.5f, 183.4f);
	s42.SetPos(-20.5f, 3.5f, 165.045f);

	sensor = App->physics->AddBody(s, 0.0f);
	sensor->SetAsSensor(false);
	sensor->collision_listeners.add(this);

	sensor1 = App->physics->AddBody(s1, 0.0f);
	sensor1->SetAsSensor(false);
	sensor1->collision_listeners.add(this);

	sensor2 = App->physics->AddBody(s2, 0.0f);
	sensor2->SetAsSensor(false);
	sensor2->collision_listeners.add(this);

	sensor3 = App->physics->AddBody(s3, 0.0f);
	sensor3->SetAsSensor(false);
	sensor3->collision_listeners.add(this);
	
	sensor4 = App->physics->AddBody(s4, 0.0f);
	sensor4->SetAsSensor(false);
	sensor4->collision_listeners.add(this);

	sensor5 = App->physics->AddBody(s5, 0.0f);
	sensor5->SetAsSensor(false);
	sensor5->collision_listeners.add(this);

	sensor6 = App->physics->AddBody(s6, 0.0f);
	sensor6->SetAsSensor(false);
	sensor6->collision_listeners.add(this);

	sensor7 = App->physics->AddBody(s7, 0.0f);
	sensor7->SetAsSensor(false);
	sensor7->collision_listeners.add(this);

	sensor8 = App->physics->AddBody(s8, 0.0f);
	sensor8->SetAsSensor(false);
	sensor8->collision_listeners.add(this);


	sensor9 = App->physics->AddBody(s9, 0.0f);
	sensor9->SetAsSensor(false);
	sensor9->collision_listeners.add(this);


	sensor10 = App->physics->AddBody(s10, 0.0f);
	sensor10->SetAsSensor(false);
	sensor10->collision_listeners.add(this);

	sensor11 = App->physics->AddBody(s11, 0.0f);
	sensor11->SetAsSensor(false);
	sensor11->collision_listeners.add(this);

	sensor12 = App->physics->AddBody(s12, 0.0f);
	sensor12->SetAsSensor(false);
	sensor12->collision_listeners.add(this);

	sensor13 = App->physics->AddBody(s13, 0.0f);
	sensor13->SetAsSensor(false);
	sensor13->collision_listeners.add(this);


	sensor14 = App->physics->AddBody(s14, 0.0f);
	sensor14->SetAsSensor(false);
	sensor14->collision_listeners.add(this);

	sensor15 = App->physics->AddBody(s15, 0.0f);
	sensor15->SetAsSensor(false);
	sensor15->collision_listeners.add(this);

	sensor16 = App->physics->AddBody(s16, 0.0f);
	sensor16->SetAsSensor(false);
	sensor16->collision_listeners.add(this);
	
	sensor17 = App->physics->AddBody(s17, 0.0f);
	sensor17->SetAsSensor(false);
	sensor17->collision_listeners.add(this);

	sensor18 = App->physics->AddBody(s18, 0.0f);
	sensor18->SetAsSensor(false);
	sensor18->collision_listeners.add(this);

	sensor19 = App->physics->AddBody(s19, 0.0f);
	sensor19->SetAsSensor(false);
	sensor19->collision_listeners.add(this);

	sensor20 = App->physics->AddBody(s20, 0.0f);
	sensor20->SetAsSensor(false);
	sensor20->collision_listeners.add(this);

	sensor21 = App->physics->AddBody(s21, 0.0f);
	sensor21->SetAsSensor(false);
	sensor21->collision_listeners.add(this);

	sensor22 = App->physics->AddBody(s22, 0.0f);
	sensor22->SetAsSensor(false);
	sensor22->collision_listeners.add(this);

	sensor23 = App->physics->AddBody(s23, 0.0f);
	sensor23->SetAsSensor(false);
	sensor23->collision_listeners.add(this);

	sensor24 = App->physics->AddBody(s24, 0.0f);
	sensor24->SetAsSensor(false);
	sensor24->collision_listeners.add(this);

	sensor25 = App->physics->AddBody(s25, 0.0f);
	sensor25->SetAsSensor(false);
	sensor25->collision_listeners.add(this);

	sensor26 = App->physics->AddBody(s26, 0.0f);
	sensor26->SetAsSensor(false);
	sensor26->collision_listeners.add(this);

	sensor27 = App->physics->AddBody(s27, 0.0f);
	sensor27->SetAsSensor(false);
	sensor27->collision_listeners.add(this);
	
	sensor28 = App->physics->AddBody(s28, 0.0f);
	sensor28->SetAsSensor(false);
	sensor28->collision_listeners.add(this);

	sensor29 = App->physics->AddBody(s29, 0.0f);
	sensor29->SetAsSensor(false);
	sensor29->collision_listeners.add(this);

	sensor30 = App->physics->AddBody(s30, 0.0f);
	sensor30->SetAsSensor(false);
	sensor30->collision_listeners.add(this);

	sensor31 = App->physics->AddBody(s31, 0.0f);
	sensor31->SetAsSensor(false);
	sensor31->collision_listeners.add(this);

	sensor32 = App->physics->AddBody(s32, 0.0f);
	sensor32->SetAsSensor(false);
	sensor32->collision_listeners.add(this);

	sensor33 = App->physics->AddBody(s33, 0.0f);
	sensor33->SetAsSensor(false);
	sensor33->collision_listeners.add(this);

	sensor34 = App->physics->AddBody(s34, 0.0f);
	sensor34->SetAsSensor(false);
	sensor34->collision_listeners.add(this);

	sensor35 = App->physics->AddBody(s35, 0.0f);
	sensor35->SetAsSensor(false);
	sensor35->collision_listeners.add(this);

	sensor36 = App->physics->AddBody(s36, 0.0f);
	sensor36->SetAsSensor(false);
	sensor36->collision_listeners.add(this);

	sensor37 = App->physics->AddBody(s37, 0.0f);
	sensor37->SetAsSensor(false);
	sensor37->collision_listeners.add(this);

	sensor38 = App->physics->AddBody(s38, 0.0f);
	sensor38->SetAsSensor(false);
	sensor38->collision_listeners.add(this);

	sensor39 = App->physics->AddBody(s39, 0.0f);
	sensor39->SetAsSensor(false);
	sensor39->collision_listeners.add(this);

	sensor40 = App->physics->AddBody(s40, 0.0f);
	sensor40->SetAsSensor(false);
	sensor40->collision_listeners.add(this);

	sensor41 = App->physics->AddBody(s41, 0.0f);
	sensor41->SetAsSensor(false);
	sensor41->collision_listeners.add(this);

	sensor42 = App->physics->AddBody(s42, 0.0f);
	sensor42->SetAsSensor(false);
	sensor42->collision_listeners.add(this);
	

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

	/*sensor->GetTransform(&s.transform);
	sensor->GetTransform(&s1.transform);
	sensor->GetTransform(&s2.transform);
	sensor->GetTransform(&s3.transform);
	sensor->GetTransform(&s4.transform);
	sensor->GetTransform(&s5.transform);
	sensor->GetTransform(&s6.transform);
	sensor->GetTransform(&s7.transform);
	sensor->GetTransform(&s8.transform);*/

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


	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("Hit!");
}