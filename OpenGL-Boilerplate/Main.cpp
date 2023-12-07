#include <glm.hpp>
#include <iostream>
#include <SDL.h>
#include <glad/glad.h>


#include "Screen.h"
#include "Input.h"

bool running = true;

int main(int argc, char* arfv[]) {
	Screen::Instance()->Init();

	while (running) {
		Screen::Instance()->Clear();
		Input::Instance()->Update();
		if (Input::Instance()->isXClicked()) {
			running = false;
		}

		Screen::Instance()->SwapBuf();
	}
	Screen::Instance()->Close();
	return 0;
}