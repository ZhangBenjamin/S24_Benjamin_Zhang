#include "pch.h"
#include "ShaderOpenGL.h"
#include "glad/glad.h"
#include "Utility.h"

AmusingDolphins::ShaderOpenGL::ShaderOpenGL(const std::string& vertexFile, const std::string& fragmentFile)
{
	std::string vertexShaderCode{ ReadFile(vertexFile) };
	const char* vertexShaderSource{ vertexShaderCode.c_str()};

	std::string fragmentShaderCode{ ReadFile(fragmentFile) };
	const char* fragmentShaderSource{ fragmentShaderCode.c_str() }; 

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		AMUSING_DOLPHINS_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
	}

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		AMUSING_DOLPHINS_ERROR("Error::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
	}

	mShaderProg = glCreateProgram();
	glAttachShader(mShaderProg, vertexShader);
	glAttachShader(mShaderProg, fragmentShader);
	glLinkProgram(mShaderProg);

	glGetProgramiv(mShaderProg, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(mShaderProg, 512, NULL, infoLog);
		AMUSING_DOLPHINS_ERROR("Error::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

AmusingDolphins::ShaderOpenGL::ShaderOpenGL(std::string&& vertexFile, std::string&& fragmentFile)
{
	std::string vertexShaderCode{ ReadFile(move(vertexFile)) };
	const char* vertexShaderSource{ vertexShaderCode.c_str() };

	std::string fragmentShaderCode{ ReadFile(move(fragmentFile)) };
	const char* fragmentShaderSource{ fragmentShaderCode.c_str() };

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		AMUSING_DOLPHINS_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
	}

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		AMUSING_DOLPHINS_ERROR("Error::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
	}

	mShaderProg = glCreateProgram();
	glAttachShader(mShaderProg, vertexShader);
	glAttachShader(mShaderProg, fragmentShader);
	glLinkProgram(mShaderProg);

	glGetProgramiv(mShaderProg, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(mShaderProg, 512, NULL, infoLog);
		AMUSING_DOLPHINS_ERROR("Error::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

AmusingDolphins::ShaderOpenGL::~ShaderOpenGL()
{
	glDeleteProgram(mShaderProg);
}

void AmusingDolphins::ShaderOpenGL::Bind()
{
	glUseProgram(mShaderProg);
}

void AmusingDolphins::ShaderOpenGL::SetUniform2Ints(const std::string& uniformName, int val1, int val2)
{
	glUseProgram(mShaderProg);
	GLint location{ glGetUniformLocation(mShaderProg, uniformName.c_str()) };
	glUniform2i(location, val1, val2);
}

void AmusingDolphins::ShaderOpenGL::SetUniform2Ints(std::string&& uniformName, int val1, int val2)
{
	glUseProgram(mShaderProg);
	GLint location{ glGetUniformLocation(mShaderProg, uniformName.c_str()) };
	glUniform2i(location, val1, val2);
}

std::string AmusingDolphins::ShaderOpenGL::ReadFile(const std::string& fileName)
{
	std::string result;
	std::ifstream inputFile{ fileName };

	std::string line;
	while (inputFile) 
	{
		line.clear();
		std::getline(inputFile, line);
		result.append(line);
		result.append("\n");
	}

	return result;
}

std::string AmusingDolphins::ShaderOpenGL::ReadFile(std::string&& fileName)
{
	std::string result;
	std::ifstream inputFile{ move(fileName) };

	std::string line;
	while (inputFile)
	{
		line.clear();
		std::getline(inputFile, line);
		result.append(line);
		result.append("\n"); 
	}

	return result;
}
