#include "Vector_AFX.h"

double Vec3Dot(const vec3 a, const vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z)/ length(b);
}

float DistanceVec3(const vec3 my, const vec3 other)
{
	return sqrt(abs(pow(my.x - other.x, 2)) +
		abs(pow(my.y - other.y, 2)) +
		abs(pow(my.z - other.z, 2))
	);
}

vec2 RealPosition(vec2 pos)
{
	vec2 real_pos;

	real_pos.x = pos.x / windowSize_W * 2;
	real_pos.y = pos.y / windowSize_H * 2;

	return real_pos;
}

vec2 Coordinate(vec2 pos)
{
	vec2 result;
	result.x = pos.x - windowSize_W / 2;
	result.y = pos.y - windowSize_H / 2;

	return result;
}

vec3 RandomVEC3(vec3 frist, vec3 second)
{
	vec3 result;

	result.x = RandomFloat(frist.x, second.x);
	result.y = RandomFloat(frist.y, second.y);
	result.z = RandomFloat(frist.z, second.z);

	return result;
}

bool CompareOverVEC3(const vec3 my, const vec3 other)
{
	if (my.x < other.x) return false;
	if (my.y < other.y) return false;
	if (my.z < other.z) return false;
	return true;
}