#define GLFW_INCLUDE_NONE

#include "Window.h"
#include "ShaderLoader.h"
#include "ObjectLoader.h"
#include "Model.h"
#include "ImageUtils.h"

#include <vector>
#include <glm.hpp>
#include <format>

bool writeToFile = false;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	else
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		writeToFile = true;
	}
}


int main(int argc, char* arfv[]) {

	Window window("OpenGL Boilerplate");
	window.setKeycallback(key_callback);

	//===== SHADER INIT =====
	ShaderLoader shaderLoader;

	std::unique_ptr<Shader> renderShader = shaderLoader.CreateShaders("Shaders/main.vert", "Shaders/main.frag");

	Object obj;
	loadObject("Objects/quad.obj", obj);
	Model quadModel(&obj, false);


	// Init FBO for rendering
	int width, height;
	window.getSize(&width, &height);




	double startTime = glfwGetTime();
	long framecount = 0;

	glClearColor(0.0, 0.0, 0.0, 0.0);
	while (window.Open()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		GLfloat timeSinceStart = (float(glfwGetTime()) - float(startTime));
		shaderLoader.SendUniformData("time", timeSinceStart);

		quadModel.Render();

		if (writeToFile)
		{
			const std::string filename = std::format("../Screenshots/frame_{}.png", framecount);
			ImageUtils::saveFramebufferAsPng(filename, width, height);
			writeToFile = false;
		}

		window.Update();
		framecount++;
	}

	shaderLoader.DetachShaders(*renderShader);

	shaderLoader.DestroyShaders(*renderShader);
	shaderLoader.DestroyProgram(renderShader->m_shaderProgramID);

	return 0;
}