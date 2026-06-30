#include <iostream>

#include "app/app_builder.hpp"
#include "TestScene.hpp"

int main() {
	auto app = AppBuilder()
		.with_config(1280, 720, "Test Game")
		.with_scene<TestScene>(GameStage::Game)
		.build();

	app->main_loop();

	return 0;
}