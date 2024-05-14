#pragma once


#include "RendererImplement.h"
#include "Shader.h"

namespace AmusingDolphins
{
	class RendererOpenGL : public RendererImplement 
	{
	public: 
		RendererOpenGL();
		~RendererOpenGL();

		virtual void Draw(Image& pic, int x, int y) override;
		virtual void Draw(Image& pic, Shader& Shader, int x, int y) override;
		virtual void ClearScreen() override;


	private:
		std::unique_ptr<Shader> mShaderPtr;
	
	};
}