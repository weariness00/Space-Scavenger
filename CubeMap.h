#pragma once
#include "Camera.h"
#include "stb_image.h"
#define STB_IMAGE_IMPLEMENTATION
class CubeMap
{
public:
    static Shader* shader;
public:
    CubeMap(string _Path);
public:
    void Draw();
    void Load();

private:
    unsigned int loadCubemap(vector<std::string> faces);
  
private:
    //Shader shader{ "SkyBox" };
    string path;

    unsigned int posLocation;
    unsigned int viewLocation;
    unsigned int projectionLocation;

    unsigned int cubemapTexture;
private:
    GLuint skyboxVAO, skyboxVBO;
};

