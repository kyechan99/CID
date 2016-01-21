#include "Scene.h"


#define AUTO_RELEASE(x) if(x) { x->release(); x = NULL; } 

Scene::Scene()
{

};

Scene::~Scene()
{

};
