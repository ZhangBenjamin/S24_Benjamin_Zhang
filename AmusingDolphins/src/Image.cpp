#include "pch.h"
#include "Image.h"
#include "./codeOpenGL/ImageOpenGL.h"

namespace AmusingDolphins {
	Image::Image(const std::string& filepath)
	{
#ifdef AMUSING_DOLPHINS_OPENGL
	mImplementation = std::unique_ptr<ImageImplement>{ new ImageOpenGL{filepath} };
#else
	#only_openGL_is_supported_so_far
#endif
	}

	Image::Image(std::string&& filepath)
	{
#ifdef AMUSING_DOLPHINS_OPENGL
		mImplementation = std::unique_ptr<ImageImplement>{ new ImageOpenGL{std::move(filepath)} };
#else
		#only_openGL_is_supported_so_far
#endif
	}

	int Image::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	int Image::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	void Image::Bind()
	{
		mImplementation->Bind();
	}

}