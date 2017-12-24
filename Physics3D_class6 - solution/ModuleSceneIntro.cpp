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
	s5.SetRotation(33, vec3(0, 1, 0));
	s6.size = vec3(1, 2, 30);//pdereta3
	s6.SetRotation(52, vec3(0, 1, 0));
	s7.size = vec3(1, 2, 25);//pesquerra3
	s7.SetRotation(56, vec3(0, 1, 0));
	s8.size = vec3(11, 2, 25);//3
	s8.SetRotation(53, vec3(0, 1, 0));

	s.SetPos(0, 2.5f, 20);//terro
	s1.SetPos(-5, 3.5f, 20);
	s2.SetPos(5.2f, 3.5f, 20);
	s3.SetPos(11, 3.5f, 103);
	s4.SetPos(0, 3.5f, 104);
	s5.SetPos(5, 2, 103);//2terra
	s6.SetPos(16.8f, 3.5f, 122);
	s7.SetPos(27.2f, 3.5f, 118);
	s8.SetPos(21, 2, 120);//3rterrra

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
	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("Hit!");
}