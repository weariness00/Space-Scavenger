#include "Transform.h"

Transform::Transform()
{
	worldPivot = localPivot = vec3(0);
	worldPosition = localPosition = vec3(0);
	worldRotation = localRotation = vec3(0);
	worldScale = localScale = vec3(1);
	model = mat4(1);
}

Transform::~Transform()
{
}

Transform& Transform::operator=(const Transform& other)
{
	worldPosition = other.worldPosition;
	localPosition = other.localPosition;

	worldRotation.x = other.worldRotation.x;
	worldRotation.y = other.worldRotation.y;
	localRotation.x = other.localRotation.x;
	localRotation.y = other.localRotation.y;

	worldPivot = other.worldPivot;
	localPivot = other.worldPivot;

	return *this;
}

void Transform::Update()
{

}

void Transform::SetScale()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomPos(-1, 1);

	vec3 randomSacle = { (float)randomPos(gen), (float)randomPos(gen),  (float)randomPos(gen) };

	randomSacle = randomSacle + worldScale;

	randomSacle.x = (randomSacle.x <= 0) ? 1 : randomSacle.x;
	randomSacle.y = (randomSacle.y <= 0) ? 1 : randomSacle.y;

	worldScale = randomSacle;
}

void Transform::SetRandomRotate()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomPos(0, 360);

	worldRotation = { (float)randomPos(gen), 0 , 0};
}

void Transform::Info()
{
	cout << worldPivot << " : worldPivot" << endl;
	cout << worldPosition << " : worldPosition" << endl;
	cout << worldRotation << " : worldRotation" << endl;
	cout << worldScale << " : worldScale" << endl;
}

void Transform::ReSet()
{
	worldPosition = localPosition = vec3(0, 0, 0);

	worldScale = localScale = vec3(1, 1, 1);

	worldRotation = localRotation = vec3(0, 0, 0);

	worldPivot = localPivot = vec3(0, 0, 0);
}


void Transform::LookAt(float speed)
{
	vec3 pos = model * vec4(0, 0, 0, 1);
	vec3 dir = translate(model, vec3(0, 0, -1)) * vec4(0, 0, 0, 1);
	vec3 norm = normalize(dir - pos);

	worldPosition += norm * FrameTime::oneFrame * speed;
}

// 목표하는 Target에 Speed 만큼 전진
void Transform::LookAtTarget(const Transform& _Target, const float _Speed)
{
	vec3 myPos = model * vec4(0, 0, 0, 1);
	vec3 targetPos = _Target.model * vec4(0, 0, 0, 1);
	vec3 dir = normalize(targetPos - myPos);

	worldPosition += dir * FrameTime::oneFrame * _Speed;
}