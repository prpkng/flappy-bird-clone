#pragma once

enum class Schedule {
	Initialize,

	PreUpdate,
	Update,
	PostUpdate,

	PreFixedUpdate,
	FixedUpdate,
	PostFixedUpdate,

	Render,

	Cleanup
};