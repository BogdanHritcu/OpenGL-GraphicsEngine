#pragma once

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace pix
{
	class Shader
	{
	private:
		GLuint m_ProgramID;

	public:
		Shader();
		Shader(const char* vertexPath, const char* fragmentPath);
		~Shader();

		void use() const;
		int getProgramID() const;

		void setBool(const char* uniformName, bool value) const;
		
		void setInt(const char* uniformName, int value) const;
		
		void setFloat(const char* uniformName, float value) const;
		
		void setVec2(const char* uniformName, const float *value_ptr) const;

		void setVec3(const char* uniformName, const float *value_ptr) const;
		void setVec3(const char* uniformName, int count, const float *value_ptr) const;
		
		void setVec4(const char* uniformName, const float *value_ptr) const;
		
		void setMat4(const char* uniformName, const float *value_ptr) const;
	};
}