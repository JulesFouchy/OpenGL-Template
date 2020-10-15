#pragma once

#include "ShaderHelper.h"

class Shader {
public:
	Shader(const std::string& vertexShaderFilepath, const std::string& fragmentShaderFilepath);
	~Shader();

	void bind();

	void setUniform1i   (const char* uniformName, int v);
	void setUniform1f   (const char* uniformName, float v);
	void setUniform2f   (const char* uniformName, const glm::vec2& v);
	void setUniform3f   (const char* uniformName, const glm::vec3& v);
	void setUniform4f   (const char* uniformName, const glm::vec4& v);
	void setUniformMat2f(const char* uniformName, const glm::mat2& mat);
	void setUniformMat3f(const char* uniformName, const glm::mat3& mat);
	void setUniformMat4f(const char* uniformName, const glm::mat4& mat);

private:
	std::unordered_map<std::string, int> m_uniformLocationCache;
	int getUniformLocation(const char* uniformName);

private:
	GLuint m_shaderId = 0;
};