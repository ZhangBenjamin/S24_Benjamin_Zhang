#include "pch.h"
#include "RendererOpenGL.h"

 #define GLFW_INCLUDE_NONE
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "ADWindow.h"

namespace AmusingDolphins
{
	RendererOpenGL::RendererOpenGL()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			AMUSING_DOLPHINS_ERROR("Failed to initialize GLAD");
			return;
		}

		mShaderPtr = std::unique_ptr<Shader>{ new Shader{ "../AmusingDolphins/Assets/Shaders/defaultVertexShader.glsl", "../AmusingDolphins/Assets/Shaders/defaultFragmentShader.glsl" } };

		
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	RendererOpenGL::~RendererOpenGL()
	{

	}
	void RendererOpenGL::Draw(Image& pic, int x, int y)
	{
		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		float vertices[] = {
			x, y, 0.0, 0.0, //left
			x + pic.GetWidth(), y, 1.0, 0.0, //right
			x, y + pic.GetHeight(), 0.0, 1.0, //top
			x + pic.GetWidth(), y + pic.GetHeight(), 1.0, 1.0 //upper-right

		};

		unsigned int indices[] = {
			0, 1, 2, //first triangle
			1, 2, 3 //second triangle
		};

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);

		unsigned int EBO;
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		mShaderPtr->Bind(); 
		mShaderPtr->SetUniform2Ints("ScreenSize", AmusingDolphinsWindow::GetWindow()->GetWidth(), AmusingDolphinsWindow::GetWindow()->GetHeight());
		glBindVertexArray(VAO); 
		pic.Bind(); 
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); 
	}
	void RendererOpenGL::Draw(Image& pic, Shader& Shader, int x, int y)
	{
		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		float vertices[] = {
			x, y, 0.0, 0.0, //left
			x + pic.GetWidth(), y, 1.0, 0.0, //right
			x, y + pic.GetHeight(), 0.0, 1.0, //top
			x + pic.GetWidth(), y + pic.GetHeight(), 1.0, 1.0 //upper-right

		};
		//49:17
		unsigned int indices[] = {
			0, 1, 2, //first triangle
			1, 2, 3 //second triangle
		};

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);

		unsigned int EBO;
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		Shader.Bind();
		glBindVertexArray(VAO);
		pic.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
	void RendererOpenGL::ClearScreen()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
		glClear(GL_COLOR_BUFFER_BIT); 
	}
}

