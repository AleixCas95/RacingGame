#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"
#include "Timer.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(0.9f, 0.9f, 1.5f);
	car.chassis_offset.Set(0, 1.5, 0);
	car.mass = 750.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 1.2f;
	car.suspensionDamping = 3.2f;
	car.maxSuspensionTravelCm = 3000.0f;
	car.frictionSlip = 50.5f;
	car.maxSuspensionForce = 3000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.45;
	float wheel_width = 0.18f;
	float suspensionRestLength = 0.35f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;

	vec3 direction(0, -1, 0);
	vec3 axis(-1, 0, 0);

	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.25f * wheel_width + 0.25f, connection_height, half_length - wheel_radius + 0.25f);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.25f * wheel_width - 0.25f, connection_height, half_length - wheel_radius + 0.25f);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.25f * wheel_width + 0.25f, connection_height, -half_length + wheel_radius - 0.25f);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.25f * wheel_width - 0.25f, connection_height, -half_length + wheel_radius - 0.25f);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(0, 3.5f, -50);
	App->camera->Follow(vehicle, 10, 10, 1.f);

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	turn = acceleration = brake = 0.0f;

	if (App->scene_intro->fastlap < 60)
	{
		fastlapseconds = App->scene_intro->fastlap;
	}
	else
	{
		fastlapminutes = App->scene_intro->fastlap / 60;
		fastlapseconds = App->scene_intro->fastlap % 60;
	}

	//move
	if ((App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT) && (vehicle->GetKmh()<90))
	{
		acceleration = MAX_ACCELERATION;
	}

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		if (turn < TURN_DEGREES)
			turn += TURN_DEGREES;
	}

	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		if (turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	if ((App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT) && ((vehicle->GetKmh())>0))
	{
		brake = BRAKE_POWER;
	}
	else if ((App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT) && ((vehicle->GetKmh()) <= 0))
	{
		acceleration = -MAX_ACCELERATION;
	}

	//Respawn
	if (App->input->GetKey(SDL_SCANCODE_R))
	{
		brake = BRAKE_POWER;
		switch (App->scene_intro->checkpoint)
		{
		case 0:
			vehicle->SetPos(0, 2, -20);
			break;
		case 1:
			vehicle->SetPos(130, 2, 66.5f);
			break;
		case 2:
			vehicle->SetPos(158.4f, 2, 166.1f);
			break;
		case 3:
			vehicle->SetPos(-132.7f, 2, 96);
			break;
		case 4:
			vehicle->SetPos(-82.7f, 2, -99);
			break;
		}
	}

	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);

	vehicle->Render();

	char title[80];
	if (App->scene_intro->laps <= 1) {
		if (((App->scene_intro->lap_timer.Read()) / 1000 >= 60))
		{
			App->scene_intro->lap_timer.Start();
			minutes = minutes + 1;
			sprintf_s(title, "%.1f Km/h\t    LAP TIME: 0%i : %i\t    LAP: %i\t     FASTLAP: %i min %i sec", vehicle->GetKmh(), minutes, (App->scene_intro->lap_timer.Read()) / 1000, App->scene_intro->laps, minutes, (App->scene_intro->lap_timer.Read()) / 1000);
		}
		else if (((App->scene_intro->lap_timer.Read()) / 1000 >= 60) && (minutes >= 10))
		{
			App->scene_intro->lap_timer.Start();
			minutes = minutes + 1;
			sprintf_s(title, "%.1f Km/h \t    LAP TIME: %i : %i\t     LAP: %i\t      FASTLAP: %i min %i sec", vehicle->GetKmh(), minutes, (App->scene_intro->lap_timer.Read()) / 1000, App->scene_intro->laps, minutes, (App->scene_intro->lap_timer.Read()) / 1000);
		}
		else if ((App->scene_intro->lap_timer.Read() / 1000 < 10) && (minutes < 10))
		{
			sprintf_s(title, "%.1f Km/h \t     LAP TIME: 0%i : 0%i\t     LAP: %i\t      FASTLAP: %i min %i sec", vehicle->GetKmh(), minutes, (App->scene_intro->lap_timer.Read()) / 1000, App->scene_intro->laps, minutes, (App->scene_intro->lap_timer.Read()) / 1000);
		}
		else if ((App->scene_intro->lap_timer.Read() / 1000 >= 10) && (minutes < 10))
		{
			sprintf_s(title, "%.1f Km/h \t      LAP TIME: 0%i : %i\t     LAP: %i\t      FASTLAP: %i min %i sec", vehicle->GetKmh(), minutes, (App->scene_intro->lap_timer.Read()) / 1000, App->scene_intro->laps, minutes, (App->scene_intro->lap_timer.Read()) / 1000);
		}
	}
	else
 {
		if (((App->scene_intro->lap_timer.Read()) / 1000 >= 60))
		{
			App->scene_intro->lap_timer.Start();
			minutes = minutes + 1;
			sprintf_s(title, "%.1f Km/h\t    LAP TIME: 0%i : %i\t     LAP: %i\t     FASTLAP: %i min %i sec", vehicle->GetKmh(), minutes, (App->scene_intro->lap_timer.Read()) / 1000, App->scene_intro->laps, fastlapminutes, fastlapseconds);
		}
		else if (((App->scene_intro->lap_timer.Read()) / 1000 >= 60) && (minutes >= 10))
		{
			App->scene_intro->lap_timer.Start();
			minutes = minutes + 1;
			sprintf_s(title, "%.1f Km/h\t    LAP TIME: %i : %i\t     LAP: %i\t      FASTLAP: %i min %i sec", vehicle->GetKmh(), minutes, (App->scene_intro->lap_timer.Read()) / 1000, App->scene_intro->laps, fastlapminutes, fastlapseconds);
		}
		else if ((App->scene_intro->lap_timer.Read() / 1000 < 10) && (minutes < 10))
		{
			sprintf_s(title, "%.1f Km/h\t    LAP TIME: 0%i : 0%i\t     LAP: %i\t      FASTLAP: %i min %i sec", vehicle->GetKmh(), minutes, (App->scene_intro->lap_timer.Read()) / 1000, App->scene_intro->laps, fastlapminutes, fastlapseconds);
		}
		else if ((App->scene_intro->lap_timer.Read() / 1000 >= 10) && (minutes < 10))
		{
			sprintf_s(title, "%.1f Km/h\t    LAP TIME: 0%i : %i\t      LAP: %i\t      FASTLAP: %i min %i sec", vehicle->GetKmh(), minutes, (App->scene_intro->lap_timer.Read()) / 1000, App->scene_intro->laps, fastlapminutes, fastlapseconds);
		}
	}

	App->window->SetTitle(title);

	vehicle->GetTransform(&matrix);
	position = matrix.translation();
	cameraPos = position;
	cameraPos.y += vehicle->info.chassis_size.y + 2;
	cameraPos.z += -vehicle->info.chassis_size.z - 10;

	//App->camera->Look(cameraPos, position, true);

	return UPDATE_CONTINUE;
}
