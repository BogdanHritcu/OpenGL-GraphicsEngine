#include "shader.h"

namespace pix
{
	Shader::Shader()
	{

	}

	Shader::Shader(const char *vertexPath, const char *fragmentPath)
	{
		std::fstream file;
		unsigned long size;
		int success;
		char infoLog[512];

		/*START READ VERTEX SHADER*/
		file.open(vertexPath, std::ios::in | std::ios::binary);

		//get the file size
		file.seekg(0, file.end);
		size = (unsigned long)file.tellg();
		file.seekg(0, file.beg);

		//read the file contents in a buffer
		char* vertexBuffer = new char[size + 1];
		file.read(vertexBuffer, size);
		vertexBuffer[size] = '\0';

		//close the file
		file.close();

		//create the vertex shader
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexBuffer, NULL);

		//compile the vertex shader
		glCompileShader(vertexShader);

		//check for errors
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			std::cout << "ERROR: Vertex shader compilation failed!" << std::endl;

			glGetShaderInfoLog(vertexShader, sizeof(infoLog), NULL, infoLog);

			std::cout << infoLog << std::endl;
		}
		/*END READ VERTEX SHADER*/

		/*START READ FRAGMENT SHADER*/
		file.open(fragmentPath, std::ios::in | std::ios::binary);

		//get the file size
		file.seekg(0, file.end);
		size = (unsigned long)file.tellg();
		file.seekg(0, file.beg);

		//read the file contents in a buffer
		char* fragmentBuffer = new char[size + 1];
		file.read(fragmentBuffer, size);
		fragmentBuffer[size] = '\0';

		//close the file
		file.close();

		//create the fragment shader
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentBuffer, NULL);

		//compile the fragment shader
		glCompileShader(fragmentShader);

		//check for errors
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			std::cout << "ERROR: Fragment shader compilation failed!" << std::endl;

			glGetShaderInfoLog(fragmentShader, sizeof(infoLog), NULL, infoLog);

			std::cout << infoLog << std::endl;
		}
		/*END READ FRAGMENT SHADER*/

		/*START CREATE PROGRAM*/
		m_ProgramID = glCreateProgram();

		//attach the shaders to the program
		glAttachShader(m_ProgramID, vertexShader);
		glAttachShader(m_ProgramID, fragmentShader);

		//link the program
		glLinkProgram(m_ProgramID);

		//check for errors
		glGetProgramiv(m_ProgramID, GL_LINK_STATUS, &success);

		if (!success)
		{
			std::cout << "ERROR: Program linking failed!" << std::endl;

			glGetProgramInfoLog(m_ProgramID, sizeof(infoLog), NULL, infoLog);

			std::cout << infoLog << std::endl;
		}
		/*END CREATE PROGRAM*/

		/*START DELETE DATA*/
		//delete the shaders
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		//delete the buffers
		delete[] vertexBuffer;
		delete[] fragmentBuffer;
		/*END DELETE DATA*/
	}

	Shader::~Shader()
	{

	}

	void Shader::use() const
	{
		glUseProgram(m_ProgramID);
	}

	int Shader::getProgramID() const
	{
		return m_ProgramID;
	}

	void Shader::setBool(const char *uniformName, bool value) const
	{
		glUniform1i(glGetUniformLocation(m_ProgramID, uniformName), (int)value);
	}

	void Shader::setInt(const char *uniformName, int value) const
	{
		glUniform1i(glGetUniformLocation(m_ProgramID, uniformName), value);
	}

	void Shader::setFloat(const char *uniformName, float value) const
	{
		glUniform1f(glGetUniformLocation(m_ProgramID, uniformName), value);
	}

	void Shader::setVec2(const char* uniformName, const float *value_ptr) const
	{
		glUniform2f(glGetUniformLocation(m_ProgramID, uniformName), *value_ptr, *(value_ptr + 1));
	}

	void Shader::setVec3(const char* uniformName, const float *value_ptr) const
	{
		glUniform3f(glGetUniformLocation(m_ProgramID, uniformName), *value_ptr, *(value_ptr + 1), *(value_ptr + 2));
	}

	void Shader::setVec3(const char* uniformName, int count, const float *value_ptr) const
	{
		glUniform3fv(glGetUniformLocation(m_ProgramID, uniformName), count, value_ptr);
	}

	void Shader::setVec4(const char* uniformName, const float *value_ptr) const
	{
		glUniform4f(glGetUniformLocation(m_ProgramID, uniformName), *value_ptr, *(value_ptr + 1), *(value_ptr + 2), *(value_ptr + 3));
	}

	void Shader::setMat4(const char* uniformName, const float *value_ptr) const
	{
		glUniformMatrix4fv(glGetUniformLocation(m_ProgramID, uniformName), 1, GL_FALSE, value_ptr);
	}
}