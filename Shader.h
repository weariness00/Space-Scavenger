#pragma once
#include <iostream>
#include <map>
#include <string>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>
#define PI 3.1415923565

using namespace std;
using namespace glm;

#pragma warning(disable:4996)

class Shader
{
public:
	static map<string, Shader*> allProgram;
public:
	Shader(string _Name);
	~Shader();
public:
	void CreatVertexShader(string shaderFileName);
	void CreatFragmentShader(string shaderFileName);
	void CreatProgram();

public:
	void SetFloat(string naem, float value);

private:
	char* FileToBuffer(const char* file);

public:
	GLuint program;

private:
	string name;
	GLuint vertexShader;
	GLuint fragmentShader;
};

