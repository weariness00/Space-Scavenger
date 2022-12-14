#pragma once
#include "Object.h"

class Camera : public Object {
public:
 	static Camera* mainCamera;

	static unsigned int viewLocation;
	static unsigned int projectionLocation;
	static unsigned int viewPosLocation;

public:
	Camera();
	~Camera();

public:
	void Draw();
	mat4& SetMatrix();

public:
	void LookAtView(float speed);
	void Info();

public:
	Transform* target_Pos;

	mat4 view;
	mat4 projection;
public:
	bool isProjection;
	bool isProjection_XY;
	bool isProjection_XZ;
	bool isPitch;
	vec3 cameraPos; //--- 카메라 위치
	vec3 cameraDirection; //--- 카메라 바라보는 방향

private:
	vec3 velocity; // 이동방향
	vec3 realCameraPos;	// 실제 카메라 위치
	vec3 cameraFront = vec3(0, 0, -1);
	vec3 cameraUp = vec3(0.0f, 1.0f, 0.0f);
	// 문제를 풀기 위한 임시 변수들
	float yRotate;
	float speed;
};