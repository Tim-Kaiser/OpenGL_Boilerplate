#pragma once

#include <vector>
#include <iostream>

#include "include/glad/gl.h"
#include "lodepng.h"

class ImageUtils
{
public:
	static void saveTextureImageAsPng(GLuint& textureID, std::string filename, int width, int height);
	static void saveFramebufferAsPng(std::string filename, int width, int height);
};