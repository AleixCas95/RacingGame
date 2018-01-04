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

	//sensor meta
	sensormeta.size = vec3(15, 15, 1);
	sensormeta.SetPos(0, 0, -20);
	sensormeta1 = App->physics->AddBody(sensormeta, 0.0f);
	sensormeta1->SetAsSensor(true);
	sensormeta1->collision_listeners.add(this);

	//checkpoint1
	checkpoint1.size = vec3(1, 15, 15);
	checkpoint1.SetPos(130, 2, 66.5f);
	sensorcheckpoint1 = App->physics->AddBody(checkpoint1, 0.0f);
	sensorcheckpoint1->SetAsSensor(true);
	sensorcheckpoint1->collision_listeners.add(this);

	//checkpoint2
	checkpoint2.size = vec3(1, 15, 15);
	checkpoint2.SetPos(158.4f, 2, 166.1f);
	sensorcheckpoint2 = App->physics->AddBody(checkpoint2, 0.0f);
	sensorcheckpoint2->SetAsSensor(true);
	sensorcheckpoint2->collision_listeners.add(this); 

	//checkpoint3
	checkpoint3.size = vec3(15, 15, 1);
	checkpoint3.SetPos(-132.7f, 2, 96);
	sensorcheckpoint3 = App->physics->AddBody(checkpoint3, 0.0f);
	sensorcheckpoint3->SetAsSensor(true);
	sensorcheckpoint3->collision_listeners.add(this);

	//checkpoint4
	checkpoint4.size = vec3(1, 15, 15);
	checkpoint4.SetPos(-82.7f, 2, -99);
	sensorcheckpoint4 = App->physics->AddBody(checkpoint4, 0.0f);
	sensorcheckpoint4->SetAsSensor(true);
	sensorcheckpoint4->collision_listeners.add(this);


	s.size = vec3(10, 1, 150);//1
	s.color = Green;
	s1.size = vec3(1, 2, 150);//pdreta
	s1.color = Purple;
	s2.size = vec3(1, 2, 150);//paretesquerra
	s2.color = Purple;
	s3.size = vec3(1, 2, 20);//pdesquerra2
	s3.color = Purple;
	s3.SetRotation(36, vec3(0, 1, 0));
	s4.size = vec3(1, 2, 20); //pdreta2
	s4.color = Purple;
	s4.SetRotation(30, vec3(0, 1, 0));
	s5.size = vec3(9, 2, 25);//2
	s5.SetRotation(35, vec3(0, 1, 0));
	s5.color = Green;
	s6.size = vec3(1, 2, 30);//pdereta3
	s6.color = Purple;
	s6.SetRotation(52, vec3(0, 1, 0));
	s7.size = vec3(1, 2, 18);//pesquerra3
	s7.color = Purple;
	s7.SetRotation(56, vec3(0, 1, 0));
	s8.size = vec3(10, 2, 25);//3
	s8.color = Green;
	s8.SetRotation(55, vec3(0, 1, 0));
	s9.size = vec3(11, 2, 70);//4
	s9.color = Green;
	s9.SetRotation(270, vec3(0, 1, 0));
	s10.size = vec3(1, 2, 70);//paretderta4
	s10.color = Purple;
	s10.SetRotation(270, vec3(0, 1, 0));
	s11.size = vec3(1, 2, 65);//pe4
	s11.color = Purple;
	s11.SetRotation(270, vec3(0, 1, 0));
	s12.size = vec3(11, 2, 60);
	s12.color = Green;
	s13.size = vec3(1, 2, 10);
	s13.color = Purple;
	s13.SetRotation(270, vec3(0, 1, 0));
	s14.size = vec3(1, 2, 58);
	s14.color = Purple;
	s15.size = vec3(1, 2, 60);
	s15.color = Purple;
	s16.size = vec3(9, 2, 30);
	s16.color = Green;
	s16.SetRotation(90, vec3(0, 1, 0));
	s17.size = vec3(2.5f, 2, 20);
	s17.color = Purple;
	s17.SetRotation(90, vec3(0, 1, 0));
	s18.size = vec3(1, 2, 80);
	s18.color = Purple;
	s18.SetRotation(90, vec3(0, 1, 0));
	s19.size = vec3(9, 2, 50);
	s19.color = Green;
	s19.SetRotation(90, vec3(0, 1, 0));
	s20.size = vec3(9, 2, 80);
	s20.color = Green;
	s21.size = vec3(2.5f, 2, 40);
	s21.color = Purple;
	s21.SetRotation(90, vec3(0, 1, 0));
	s22.size = vec3(1, 2, 80);
	s22.color = Purple;
	s23.size = vec3(1, 2, 70);
	s23.color = Purple;
	s24.size = vec3(1, 2, 10);
	s24.color = Purple;
	s25.size = vec3(1, 2, 10);
	s25.color = Purple;
	s26.size = vec3(9, 2, 15);
	s26.color = Green;
	s26.SetRotation(-30, vec3(0, 1, 0));
	s27.size = vec3(1, 2, 10);
	s27.color = Purple;
	s27.SetRotation(-23, vec3(0, 1, 0));
	s28.size = vec3(1, 2, 10);
	s28.color = Purple;
	s28.SetRotation(-32, vec3(0, 1, 0));
	s29.size = vec3(9, 2, 20);
	s29.color = Green;
	s29.SetRotation(-60, vec3(0, 1, 0));
	s30.size = vec3(1, 2, 5);
	s30.color = Purple;
	s30.SetRotation(-34, vec3(0, 1, 0));
	s31.size = vec3(1, 2, 20);
	s31.color = Purple;
	s31.SetRotation(-60, vec3(0, 1, 0));
	s32.size = vec3(1, 2, 20);
	s32.color = Purple;
	s32.SetRotation(-55, vec3(0, 1, 0));
	s33.size = vec3(20, 2, 300);
	s33.color = Green;
	s33.SetRotation(-90, vec3(0, 1, 0));
	s34.size = vec3(8, 2, 15);
	s34.color = Green;
	s34.SetRotation(-90, vec3(0, 1, 0));
	s35.size = vec3(20, 2, 10);
	s35.color = Green;
	s35.SetRotation(30, vec3(0, 1, 0));
	s36.size = vec3(10, 2, 10);
	s36.color = Green;
	s36.SetRotation(-13, vec3(0, 1, 0));
	s37.size = vec3(1, 2, 20);
	s37.color = Purple;
	s37.SetRotation(-70, vec3(0, 1, 0));
	s38.size = vec3(3, 2, 7);
	s38.color = Green;
	s38.SetRotation(-70, vec3(0, 1, 0));
	s39.size = vec3(1, 2, 17);
	s39.color = Purple;
	s39.SetRotation(-100, vec3(0, 1, 0));
	s40.size = vec3(1, 2, 9);
	s40.color = Purple;
	s40.SetRotation(-70, vec3(0, 1, 0));
	s41.size = vec3(1, 2, 300);
	s41.color = Purple;
	s41.SetRotation(-90, vec3(0, 1, 0));
	s42.size = vec3(1, 2, 300);
	s42.color = Purple;
	s42.SetRotation(-90, vec3(0, 1, 0));
	s43.size = vec3(13, 2, 13);
	s43.color = Green;
	s43.SetRotation(-130, vec3(0, 1, 0));
	s44.size = vec3(13, 2, 15);
	s44.color = Green;
	s44.SetRotation(125, vec3(0, 1, 0));
	s45.size = vec3 ( 1, 2, 19);
	s45.color = Purple;
	s45.SetRotation(-135, vec3(0, 1, 0));
	s46.size = vec3(1, 2, 6);
	s46.color = Purple;
	s46.SetRotation(-135, vec3(0, 1, 0));
	s47.size = vec3(13, 2, 15);
	s47.color = Green;
	s47.SetRotation(-170, vec3(0, 1, 0));
	s48.size = vec3(1, 2, 15);
	s48.color = Purple;
	s48.SetRotation(-170, vec3(0, 1, 0));
	s49.size = vec3(1, 2, 7);
	s49.color = Purple;
	s49.SetRotation(-170, vec3(0, 1, 0));
	s50.size = vec3(13, 2, 30);
	s50.color = Green;
	s51.size = vec3(10, 2, 50);
	s51.color = Green;
	s51.SetRotation(90, vec3(0, 1, 0));
	s52.size = vec3(1, 2, 41);
	s52.color = Purple;
	s53.size = vec3(1, 2, 28);
	s53.color = Purple;
	s54.size = vec3(1, 2, 50);
	s54.color = Purple;
	s54.SetRotation(90, vec3(0, 1, 0));
	s55.size = vec3(1, 2, 40);
	s55.color = Purple;
	s55.SetRotation(90, vec3(0, 1, 0));
	s56.size = vec3(10, 2, 60);
	s56.color = Green;
	s57.size = vec3(1, 2, 60);
	s57.color = Purple;
	s58.size = vec3(1, 2, 50);
	s58.color = Purple;
	s59.size = vec3(1, 2, 10);
	s59.color = Purple;
	s59.SetRotation(90, vec3(0, 1, 0));
	s60.size = vec3(10, 2, 30);
	s60.color = Green;
	s60.SetRotation(90, vec3(0, 1, 0));
	s61.size = vec3(1, 2, 10);
	s61.color = Purple;
	s62.size = vec3(1, 2, 20);
	s62.color = Purple;
	s62.SetRotation(90, vec3(0, 1, 0));
	s63.size = vec3(1, 2, 30);
	s63.color = Purple;
	s63.SetRotation(90, vec3(0, 1, 0));
	s64.size = vec3(10, 2, 60);
	s64.color = Green;
	s65.size = vec3(10, 2, 30);
	s65.color = Green;
	s65.SetRotation(90, vec3(0, 1, 0));
	s66.size = vec3(10, 2, 60);
	s66.color = Green;
	s67.size = vec3(10, 2, 30);
	s67.color = Green;
	s67.SetRotation(90, vec3(0, 1, 0));
	s68.size = vec3(10, 2, 60);
	s68.color = Green;
	s69.size = vec3(10, 2, 170);
	s69.color = Green;
	s69.SetRotation(90, vec3(0, 1, 0));
	s70.size = vec3(1, 2, 170);
	s70.color = Purple;
	s70.SetRotation(90, vec3(0, 1, 0));
	s71.size = vec3(1, 2, 140);
	s71.color = Purple;
	s71.SetRotation(90, vec3(0, 1, 0));
	s72.size = vec3(10, 2, 20);
	s72.color = Green;
	/*s72.SetRotation(90, vec3(0, 1, 0));*/
	s72.SetRotation(10, vec3(1, 0, 0));
	s73.size = vec3(10, 2, 20);
	s73.color = Green;
	/*s73.SetRotation(90, vec3(0, 1, 0));*/
	s73.SetRotation(10, vec3(1, 0, 0));
	s74.size = vec3(10, 1, 50);
	s74.color = Green;
	s75.size = vec3(1, 2, 50);
	s75.color = Purple;
	s76.size = vec3(1, 2, 30);
	s76.color = Purple;
	s77.size = vec3(1, 2, 140);
	s77.color = Purple;
	s77.SetRotation(90, vec3(0, 1, 0));
	s78.size = vec3(1, 2, 10);
	s78.color = Purple;
	s79.size = vec3(1, 2, 140);
	s79.color = Purple;
	s79.SetRotation(90, vec3(0, 1, 0));
	s80.size = vec3(50, 2, 400);
	s80.color = Brown;
	s81.size = vec3(50, 2, 400);
	s81.color = Brown;
	s81.SetRotation(90, vec3(0, 1, 0));
	s82.size = vec3(50, 2, 400);
	s82.color = Brown;
	s82.SetRotation(90, vec3(0, 1, 0));
	s83.size = vec3(50, 2, 400);
	s83.color = Brown;
	s84.size = vec3(350, 2, 350);
	s84.color = Lightblue;
	//spheres
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
	//pareds recta
	s90.size = vec3(1, 3, 5);
	s90.color = Brown;
	s91.size = vec3(1, 3, 5);
	s91.color = Brown;
	s92.size = vec3(1, 3, 5);
	s92.color = Brown;
	s93.size = vec3(1, 3, 5);
	s93.color = Brown;
	s94.size = vec3(1, 3, 5);
	s94.color = Brown;
	s95.size = vec3(1, 3, 5);
	s95.color = Brown;
	s96.size = vec3(1, 3, 5);
	s96.color = Brown;
	s97.size = vec3(1, 3, 5);
	s97.color = Brown;
	s98.size = vec3(1, 3, 5);
	s98.color = Brown;
	s99.size = vec3(1, 3, 5);
	s99.color = Brown;


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
	//check point 1
	s17.SetPos(117.8f, 3.5f, 72.2f);
	s18.SetPos(136, 3.5f, 61.7f);
	s19.SetPos(152, 2, 66.5f);
	s20.SetPos(172.6f, 2, 111);
	s21.SetPos(147.8f, 3.5f, 72.2f);
	s22.SetPos(176.5f, 3.5f, 101.2f);
	s23.SetPos(168.3f, 3.5f, 106);
	s24.SetPos(168.3f, 3.5f, 145);
	s25.SetPos(176.5f,3.5f, 145);
	s26.SetPos(169.2f, 2, 156);
	s27.SetPos(174.6f, 3.5f, 154.2f);
	s28.SetPos(165.7f, 3.5f, 154);
	s29.SetPos(158.4f, 2, 166.1f);
	//check point 2
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
	s43.SetPos(-170, 2, 176);
	s44.SetPos(-175, 2, 170);
	s45.SetPos(-178, 3.5f, 177.2f);
	s46.SetPos(-172.2f, 3.5f, 163);
	s47.SetPos(-180, 2, 162);
	s48.SetPos(-185.9f, 3.5f, 163.3f);
	s49.SetPos(-174.767f, 3.5f, 157.7f);
	s50.SetPos(-181.3f, 2, 141);
	s51.SetPos(-162.7f, 2, 121);
	s52.SetPos(-187.2f, 3.5f, 136);
	s53.SetPos(-175.2f, 3.5f, 140.7f);
	s54.SetPos(-162.3f, 3.5f, 116);
	s55.SetPos(-155.7f, 3.5f, 126.4f);
	s59.SetPos(-132.2f, 3.5f, 126.4f);//parxe
	s56.SetPos(-132.7f, 2, 96);
	//check point 3
	s57.SetPos(-127.7f, 3.5f, 96.4f);
	s58.SetPos(-137, 3.5f, 91.5f);
	s60.SetPos(-142.7f, 2, 61);
	s61.SetPos(-127.7f, 3.5f, 61.4f);
	s62.SetPos(-146.5f, 3.5f, 66);
	s63.SetPos(-142.2f, 3.5f, 55.9f);
	s64.SetPos(-162.7f, 2, 35.9f);
	s65.SetPos(-142.8f, 2, 10.88f);
	s66.SetPos(-122.8f, 2, -14);
	s67.SetPos(-142.7f, 2, -39);
	s68.SetPos(-162.7f, 2, -64);
	s69.SetPos(-82.7f, 2, -99);
//check point 4
	s70.SetPos(-82.7f, 3.5, -104);
	s71.SetPos(-87.7f, 3.5, -94);
	s72.SetPos(-122.8f, 0.30f, 25.8f);
	s73.SetPos(-162.7f, 0.30f, 75.4f);
	s74.SetPos(0, 2.5f, -79);
	s75.SetPos(5.2f, 3.5f, -79);
	s76.SetPos(-5, 3.5f, -70);
	s77.SetPos(-64.3f, 3.5f, -104);
	s78.SetPos(-5, 3.5f, -89);
	s79.SetPos(-74.5f, 3.5, -94);
	s80.SetPos(200, 0, 0);
	s81.SetPos(0, 0, 200);
	s82.SetPos(0, 0, -200);
	s83.SetPos(-200, 0, 0);
	s84.SetPos(0, 0, 0);
	s85.SetPos(-20, 2, 173);
	s86.SetPos(50, 2, 173);
	s87.SetPos(-70, 2, 173);
	s88.SetPos(-100, 2, 173);
	s89.SetPos(90, 2, 173);
	s90.SetPos(-35, 4.5f, 179);
	s91.SetPos(45, 4.5f, 179);
	s92.SetPos(-60, 4.5f, 179);
	s93.SetPos(-125, 4.5f, 179);
	s94.SetPos(80, 4.5f, 179);
	s95.SetPos(-35, 4.5f, 168.5f);
	s96.SetPos(45, 4.5f, 168.5f);
	s97.SetPos(-110, 4.5f, 168.5f);
	s98.SetPos(-125, 4.5f, 168.5f);
	s99.SetPos(80, 4.5f, 168.5f);





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

	sensor43 = App->physics->AddBody(s43, 0.0f);
	sensor43->SetAsSensor(false);
	sensor43->collision_listeners.add(this);

	sensor44 = App->physics->AddBody(s44, 0.0f);
	sensor44->SetAsSensor(false);
	sensor44->collision_listeners.add(this);

	sensor45 = App->physics->AddBody(s45, 0.0f);
	sensor45->SetAsSensor(false);
	sensor45->collision_listeners.add(this);

	sensor46 = App->physics->AddBody(s46, 0.0f);
	sensor46->SetAsSensor(false);
	sensor46->collision_listeners.add(this);

	sensor47 = App->physics->AddBody(s47, 0.0f);
	sensor47->SetAsSensor(false);
	sensor47->collision_listeners.add(this);

	sensor48 = App->physics->AddBody(s48, 0.0f);
	sensor48->SetAsSensor(false);
	sensor48->collision_listeners.add(this);

	sensor49 = App->physics->AddBody(s49, 0.0f);
	sensor49->SetAsSensor(false);
	sensor49->collision_listeners.add(this);

	sensor50 = App->physics->AddBody(s50, 0.0f);
	sensor50->SetAsSensor(false);
	sensor50->collision_listeners.add(this);

	sensor51 = App->physics->AddBody(s51, 0.0f);
	sensor51->SetAsSensor(false);
	sensor51->collision_listeners.add(this);

	sensor52 = App->physics->AddBody(s52, 0.0f);
	sensor52->SetAsSensor(false);
	sensor52->collision_listeners.add(this);

	sensor53 = App->physics->AddBody(s53, 0.0f);
	sensor53->SetAsSensor(false);
	sensor53->collision_listeners.add(this);

	sensor54 = App->physics->AddBody(s54, 0.0f);
	sensor54->SetAsSensor(false);
	sensor54->collision_listeners.add(this);

	sensor55 = App->physics->AddBody(s55, 0.0f);
	sensor55->SetAsSensor(false);
	sensor55->collision_listeners.add(this);

	sensor56 = App->physics->AddBody(s56, 0.0f);
	sensor56->SetAsSensor(false);
	sensor56->collision_listeners.add(this);

	sensor57 = App->physics->AddBody(s57, 0.0f);
	sensor57->SetAsSensor(false);
	sensor57->collision_listeners.add(this);

	sensor58 = App->physics->AddBody(s58, 0.0f);
	sensor58->SetAsSensor(false);
	sensor58->collision_listeners.add(this);

	sensor59 = App->physics->AddBody(s59, 0.0f);
	sensor59->SetAsSensor(false);
	sensor59->collision_listeners.add(this);

	sensor60 = App->physics->AddBody(s60, 0.0f);
	sensor60->SetAsSensor(false);
	sensor60->collision_listeners.add(this);

	sensor61 = App->physics->AddBody(s61, 0.0f);
	sensor61->SetAsSensor(false);
	sensor61->collision_listeners.add(this);

	sensor62 = App->physics->AddBody(s62, 0.0f);
	sensor62->SetAsSensor(false);
	sensor62->collision_listeners.add(this);

	sensor63 = App->physics->AddBody(s63, 0.0f);
	sensor63->SetAsSensor(false);
	sensor63->collision_listeners.add(this);

	sensor64 = App->physics->AddBody(s64, 0.0f);
	sensor64->SetAsSensor(false);
	sensor64->collision_listeners.add(this);

	sensor65 = App->physics->AddBody(s65, 0.0f);
	sensor65->SetAsSensor(false);
	sensor65->collision_listeners.add(this);

	sensor66 = App->physics->AddBody(s66, 0.0f);
	sensor66->SetAsSensor(false);
	sensor66->collision_listeners.add(this);

	sensor67 = App->physics->AddBody(s67, 0.0f);
	sensor67->SetAsSensor(false);
	sensor67->collision_listeners.add(this);

	sensor68 = App->physics->AddBody(s68, 0.0f);
	sensor68->SetAsSensor(false);
	sensor68->collision_listeners.add(this);

	sensor69 = App->physics->AddBody(s69, 0.0f);
	sensor69->SetAsSensor(false);
	sensor69->collision_listeners.add(this);

	sensor70 = App->physics->AddBody(s70, 0.0f);
	sensor70->SetAsSensor(false);
	sensor70->collision_listeners.add(this);

	sensor71 = App->physics->AddBody(s71, 0.0f);
	sensor71->SetAsSensor(false);
	sensor71->collision_listeners.add(this);

	sensor72 = App->physics->AddBody(s72, 0.0f);
	sensor72->SetAsSensor(false);
	sensor72->collision_listeners.add(this);

	sensor73 = App->physics->AddBody(s73, 0.0f);
	sensor73->SetAsSensor(false);
	sensor73->collision_listeners.add(this);

	sensor74 = App->physics->AddBody(s74, 0.0f);
	sensor74->SetAsSensor(false);
	sensor74->collision_listeners.add(this);

	sensor75 = App->physics->AddBody(s75, 0.0f);
	sensor75->SetAsSensor(false);
	sensor75->collision_listeners.add(this);

	sensor76 = App->physics->AddBody(s76, 0.0f);
	sensor76->SetAsSensor(false);
	sensor76->collision_listeners.add(this);

	sensor77 = App->physics->AddBody(s77, 0.0f);
	sensor77->SetAsSensor(false);
	sensor77->collision_listeners.add(this);

	sensor78 = App->physics->AddBody(s78, 0.0f);
	sensor78->SetAsSensor(false);
	sensor78->collision_listeners.add(this);

	sensor79 = App->physics->AddBody(s79, 0.0f);
	sensor79->SetAsSensor(false);
	sensor79->collision_listeners.add(this);


	sensor80 = App->physics->AddBody(s70, 0.0f);
	sensor80->SetAsSensor(false);
	sensor80->collision_listeners.add(this);

	sensor81 = App->physics->AddBody(s81, 0.0f);
	sensor81->SetAsSensor(false);
	sensor81->collision_listeners.add(this);

	sensor82 = App->physics->AddBody(s82, 0.0f);
	sensor82->SetAsSensor(false);
	sensor82->collision_listeners.add(this);

	sensor83 = App->physics->AddBody(s83, 0.0f);
	sensor83->SetAsSensor(false);
	sensor83->collision_listeners.add(this);

	//sensor84 = App->physics->AddBody(s84, 0.0f);
	//sensor84->SetAsSensor(false);
	//sensor84->collision_listeners.add(this);
	//aigua

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

	sensor90 = App->physics->AddBody(s90, 0.0f);
	sensor90->SetAsSensor(false);
	sensor90->collision_listeners.add(this);

	sensor91 = App->physics->AddBody(s91, 0.0f);
	sensor91->SetAsSensor(false);
	sensor91->collision_listeners.add(this);

	sensor92 = App->physics->AddBody(s92, 0.0f);
	sensor92->SetAsSensor(false);
	sensor92->collision_listeners.add(this);

	sensor93 = App->physics->AddBody(s93, 0.0f);
	sensor93->SetAsSensor(false);
	sensor93->collision_listeners.add(this);

	sensor94 = App->physics->AddBody(s94, 0.0f);
	sensor94->SetAsSensor(false);
	sensor94->collision_listeners.add(this);

	sensor95 = App->physics->AddBody(s95, 0.0f);
	sensor95->SetAsSensor(false);
	sensor95->collision_listeners.add(this);

	sensor96 = App->physics->AddBody(s96, 0.0f);
	sensor96->SetAsSensor(false);
	sensor96->collision_listeners.add(this);

	sensor97 = App->physics->AddBody(s97, 0.0f);
	sensor97->SetAsSensor(false);
	sensor97->collision_listeners.add(this);

	sensor98 = App->physics->AddBody(s98, 0.0f);
	sensor98->SetAsSensor(false);
	sensor98->collision_listeners.add(this);

	sensor99 = App->physics->AddBody(s99, 0.0f);
	sensor99->SetAsSensor(false);
	sensor99->collision_listeners.add(this);

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

	//checkpoints y meta
	sensormeta.Render();
	checkpoint1.Render();
	checkpoint2.Render();
	checkpoint3.Render();
	checkpoint4.Render();

	//circuito
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
		App->scene_intro->lap_timer.Start();
		checkpoint = 0;
		laps = laps + 1;
		collision = true;
	}

	if (body1 == sensorcheckpoint1) 
	{
		checkpoint = 1;
		collision = false;
	}

	if(body1 == sensorcheckpoint2) 
	{
		checkpoint = 2;
	}

	if (body1 == sensorcheckpoint3)
	{
		checkpoint = 3;
	}

	if (body1 == sensorcheckpoint4) 
	{
		checkpoint = 4;
	}

	LOG("Hit!");
}