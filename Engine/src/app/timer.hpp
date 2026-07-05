#pragma once



class Timer {
private:
	friend class Application;

	static Timer* instance();

	void update();

	float delta;
	float current_time;

public:
	static inline float dt() { return instance()->delta; }
	static inline float time() { return instance()->current_time; }
};