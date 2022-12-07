#include "Harpoon.h"

OBJ* Harpoon::_Obj = nullptr;

Harpoon::Harpoon()
{
	SetType(EqType::HARPOON);
	name = "Harpoon";

	if (_Obj == nullptr)
	{
		_Obj = new OBJ;
		_Obj->ReadObj((char*)"Harpoon.obj");
	}

	obj = _Obj;

	collider.tag = "Harpoon";
	collider.SetBox_OBB(vec3(2));
	collider.object = this;

	Render::meshtRender->AddObject(this, "Harpoon");
}

Harpoon::~Harpoon()
{
}

void Harpoon::Init()
{
	curEnergy = 0;
	chargedEnergy = 0;
	speed = 100;
	color.SetRandomColor();
	transform.worldScale *= 0.5;
}

void Harpoon::Update()
{

}

void Harpoon::ChargingEnergy()
{
	startTime = clock();

	cout << "Charging energy..." << endl;

	curEnergy = 0;
	chargedEnergy = 0;

	SetState(State::CHARGING);
}

void Harpoon::FinishCharging()
{
	endTime = clock();

	cout << "Finish Charging" << endl;
	double chargingTime = (endTime - startTime) / CLOCKS_PER_SEC;
	if (chargingTime > maxEnergy) chargingTime = maxEnergy;
	cout << "Charging Time : " << chargingTime << endl;

	chargedEnergy = chargingTime * 10;

	SetState(State::FIRING);
}

void Harpoon::MyTimer()
{
	switch (GetState()) {
	case State::IDLE:
		break;
	case State::CHARGING:
		break;
	case State::FIRING:
		Fire();
		break;
	}
}

void Harpoon::Fire()
{
	float frameSpeed = speed * FrameTime::oneFrame;

	if (curEnergy < chargedEnergy)
	{
		transform.localPosition.z -= frameSpeed * chargedEnergy / 30.0;
		transform.worldScale.z += frameSpeed * chargedEnergy / 30.0;
	}
	else {
		transform.localPosition.z += frameSpeed * chargedEnergy / 150.0;
		transform.worldScale.z -= frameSpeed * chargedEnergy / 150.0;

		if (transform.worldScale.z < 0.5) {
			transform.localPosition.z = 0;
			transform.worldScale.z = 0.5;
			chargedEnergy = 0;
			SetState(State::IDLE);
		}
	}
	curEnergy++;
}
