#pragma once

class Application;

class Scene
{
public:
	virtual void OnEnter() = 0;
	virtual void update(float delta) = 0;
	virtual void render(float delta) = 0;
	virtual void OnExit() = 0;
protected:
	friend class SceneStager;
	Application* application;
};

