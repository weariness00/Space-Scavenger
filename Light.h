#pragma once
#include "Sphere.h"
#include "Shader.h"

class Light : public Sphere
{
public:
	static Shader* lightShader;
	static list<Light*> allLight;

	static unsigned int lightPosLocation;
	static unsigned int lightColorLocation;

	static unsigned int lightCount;

public:
	Light();
	~Light();

public:
	void Enable();
	void Disable();
	void Init();
	void Update();

public:
	//Color color;
	//Transform transform;

	//Sphere shape;
private:
	int light_ID;
private:
	unsigned int PosLocation;
	unsigned int ColorLocation;
};

