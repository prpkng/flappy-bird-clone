#pragma once

struct WindowEvent;
class Application;

class Scene
{
public:
	virtual void enter() = 0;
	virtual void update(float delta) = 0;
	virtual void render(float delta) = 0;
	virtual void on_event(const WindowEvent& event) = 0;
	virtual void exit() = 0;
protected:
	friend class SceneStager;
	Application* application;
};

