#pragma once

#include "error/assertions.hpp"
#include "scenes/scene_stager.hpp"
#include "app/application.hpp"

#include <magic_enum/magic_enum.hpp>
#include <string>
#include <map>
#include <memory>

struct AppConfig {
	int width, height;
	std::string title;
};

struct [[nodiscard]] AppBuilder {
	AppConfig config{};

	std::map<GameStage, std::unique_ptr<Scene>> scenes{};

	inline AppBuilder();

	inline AppBuilder& with_config(int width, int height, const std::string& title = "Game");
	
	template <typename T>
	inline AppBuilder& with_scene(GameStage stage);

	[[nodiscard]] inline std::unique_ptr<Application> build();
};


inline AppBuilder::AppBuilder() {
	//TODO implement settings loading here
	config.width = 800;
	config.height = 600;
	config.title = "Game";
}

inline AppBuilder& AppBuilder::with_config(int width, int height, const std::string& title) {
	config.width = width;
	config.height = height;
	config.title = title;
	return *this;
}

inline std::unique_ptr<Application> AppBuilder::build()
{
	auto app = std::make_unique<Application>();
	app->initialize(config);
	for (auto& [stage, scene] : scenes) {
		app->get_stager().add_scene(stage, std::move(scene));
	}
	return std::move(app);
}

template<typename T>
inline AppBuilder& AppBuilder::with_scene(GameStage stage)
{
	static_assert(std::is_base_of<Scene, T>::value, "T must inherit from Scene!");
	
	DEV_ASSERT(!scenes.contains(stage), "Stage {0} is already present in the AppBuilder!", magic_enum::enum_name(stage))
	
	scenes[stage] = std::make_unique<T>();
	return *this;
}
