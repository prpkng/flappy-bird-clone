#pragma once

enum class Schedule {
	Initialize,

	PreUpdate,
	Update,
	PostUpdate,

	PreFixedUpdate,
	FixedUpdate,
	PostFixedUpdate,

	PreRender,
	Render,
	PostRender,

	Cleanup
};