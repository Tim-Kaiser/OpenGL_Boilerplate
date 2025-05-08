#include "ImageUtils.h"

void ImageUtils::saveTextureImageAsPng(GLuint& textureID, std::string filename, int width, int height)
{
	std::vector<unsigned char> pixelData;
	pixelData.resize(width * height * 4);
	GLsizei bufSize = width * height * 4;
	glGetTextureImage(textureID, 0, GL_RGBA, GL_UNSIGNED_BYTE, bufSize, pixelData.data());

	unsigned error = lodepng::encode(filename, pixelData ,width, height );
	if (error) std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}

// Saves the pixel data from the current framebuffer into an image with given filename
void ImageUtils::saveFramebufferAsPng(std::string filename, int width, int height)
{
	std::vector<unsigned char> pixelData;
	pixelData.resize(width * height * 4);
	glReadPixels(0, 0,  width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixelData.data());

	unsigned error = lodepng::encode(filename, pixelData, width, height);
	if (error) std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}
