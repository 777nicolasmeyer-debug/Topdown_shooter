#pragma once
#include "raylib.h"

class Player {
	public:
		Vector2 position;
		float speed;
		float dimension;
		float rotation;
		Color color;

		void Update();
		void Draw();
		void FaceMouse();
};