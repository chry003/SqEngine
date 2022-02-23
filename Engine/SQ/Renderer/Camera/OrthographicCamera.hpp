#pragma once

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include "Core/Base.hpp"

namespace Sq {

	class OrthographicCamera
	{
	public:
		OrthographicCamera(f32 left, f32 right, f32 bottom, f32 top);

		void SetPosition(const glm::vec3& pos) 
		{ 
			m_Position = pos;
			CalculateViewMatrix();
		}

		void SetRotation(f32 rotation) 
		{ 
			m_Rotation = rotation;
			CalculateViewMatrix();
		}

		void SetRatio(const glm::vec4& ratio)
		{
			m_ProjectionMatrix = glm::ortho(ratio.x, ratio.y, ratio.z, ratio.w, -1.0f, 1.0f);
			m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
		}

		const glm::vec3 GetPosition() { return m_Position; }
		f32 GetRotation() { return m_Rotation; }

		const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }

	private:
		void CalculateViewMatrix();

	private:
		glm::vec3 m_Position = glm::vec3(1.0f);
		f32 m_Rotation = 0.0f;

		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;
	};

}