#pragma once

#include "../renderer/renderer2d.h"

namespace pix
{
	class Layer : public Renderer2D
	{
	public:
		Layer(const char* vertShaderPath, const char* fragShaderPath, const glm::mat4 &projectionMat);
		~Layer();

	public:
		void submit(Renderable2D &renderable);
		void flush(bool reset = false);
	};
}