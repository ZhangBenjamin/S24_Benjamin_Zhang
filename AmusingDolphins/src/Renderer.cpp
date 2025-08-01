#include "pch.h"
#include "Renderer.h"
#include "codeOpenGL/RendererOpenGL.h"


namespace AmusingDolphins 
{
	void Renderer::Init()
	{
		if (!mInstance)
			mInstance = new Renderer;
	}

	Renderer* Renderer::GetInstance()
	{
		return mInstance;
	}

	void Renderer::Draw(Image& pic, int x, int y)
	{
		mInstance->mImplementation->Draw(pic, x, y);
	}

	void Renderer::Draw(Image& pic, Shader& shader, int x, int y)
	{
		mInstance->mImplementation->Draw(pic, shader, x, y);
	}

	void Renderer::Draw(Unit& Unit)
	{
		mInstance->mImplementation->Draw(Unit.mImage, Unit.mXPosition, Unit.mYPosition);
	}

	void Renderer::ClearScreen()
	{
		mInstance->mImplementation->ClearScreen();
	}
	Renderer::Renderer() 
	{
#ifdef AMUSING_DOLPHINS_OPENGL
		mImplementation = std::unique_ptr<RendererImplement>{ new RendererOpenGL };
#else
		#only_openGL_is_supported_so_far
#endif
	}


}

