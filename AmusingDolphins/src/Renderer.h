#pragma once
#include "pch.h"
#include "Utility.h"
#include "image.h"
#include "RendererImplement.h"

namespace AmusingDolphins 
{
	class AMUSING_DOLPHINS_API Renderer {
	public: 
		static void Init();
		static Renderer* GetInstance();

		static void Draw(Image& pic, int x, int y);
		static void Draw(Image& pic, Shader& shader, int x, int y);
		static void ClearScreen();

	private:
		std::unique_ptr<RendererImplement> mImplementation;
		
		inline static Renderer* mInstance{ nullptr };
		Renderer();
	};
}