#pragma once

#include "Vector_AFX.h"

class Transform {
public:
	Transform();
	~Transform();

public:
	Transform& operator=(const Transform&);

public:
	void Update();
	void SetScale(); // ���� ������
	void SetRandomRotate();

	void Info();
	void ReSet();
public:
	void LookAt(float speed);
	void LookAtTarget(const Transform& _Target, const float _Speed);
public:
	vec3 worldPosition;
	vec3 localPosition;

	vec3 worldScale;
	vec3 localScale;

	vec3 worldRotation;
	vec3 localRotation;

	vec3 worldPivot;
	vec3 localPivot;

	mat4 model;
};