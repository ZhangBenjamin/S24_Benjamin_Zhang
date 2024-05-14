#pragma once
#include "pch.h"

#include "Utility.h"
#include "ImageImplement.h"

namespace AmusingDolphins {
	class AMUSING_DOLPHINS_API Image {
	public:
		Image(const std::string& filepath);
		Image(std::string&& filepath);

		int GetWidth() const;
		int GetHeight() const;

		void Bind();
	private:
		std::unique_ptr<ImageImplement> mImplementation;
	};
}