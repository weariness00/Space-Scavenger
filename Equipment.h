#pragma once
#include "Render.h"
#include "Collider.h"
#include "Gauge.h"

enum class EqType {
	HARPOON,	// 작살
	LOWGUN,		// 총
	BULLET,		// 총알
	GUIDANCE,	// 유도
};

enum class State {
	IDLE,
	CHARGING,
	FIRING,
};

class Equipment :public Object, public Mesh
{
public:
	Equipment();
	~Equipment();

public:
	virtual void ChargingEnergy();
	virtual void FinishCharging();

public:
	void SetType(EqType type);
	EqType GetType();
	void SetState(State state);
	State GetState();

public:
	virtual void Init();
	virtual void Update();
	virtual void Fire();
	void Handle_Evnet(int specialKey);
	void FireSet();

public:
	int strength = 0;
	int max_strength = 0;
	float speed = 100;
	bool firing = false;
	bool charging = false;
	bool isDragged; // 현재 자원을 끓어오고 있는지 체크
	Transform targetPos;

protected:
	EqType myType;
	State myState;
};


