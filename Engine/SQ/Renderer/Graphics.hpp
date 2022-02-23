#pragma once

#include "Core/Base.hpp"
#include "Shader.hpp"

namespace Sq {

	//////////////////////////////////////
	//			Buffer Layout			//
	//////////////////////////////////////

	class BufferLayout
	{
	public:

		BufferLayout() {}

		BufferLayout(const silst<BufferElement>& elements)
			: m_Elements(elements)
		{
			CalcOffsetandStride();
		}

		inline const svec<BufferElement>& GetElements() const { return m_Elements; }

		inline const u32 GetStride() const { return m_Stride; }

		svec<BufferElement>::iterator begin() { return m_Elements.begin(); }
		svec<BufferElement>::iterator end() { return m_Elements.end(); }
		
		svec<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
		svec<BufferElement>::const_iterator end() const { return m_Elements.end(); }

	private:
		void CalcOffsetandStride()
		{
			u32 offset = 0;
			m_Stride = 0;
			for (auto& element : m_Elements)
			{
				element.Offset = offset;
				offset += element.Size;
				m_Stride += element.Size;
			}
		}
	private:
		svec<BufferElement> m_Elements;
		u32 m_Stride = 0;
	};

	//////////////////////////////////////
	//			Vertex Buffer			//
	//////////////////////////////////////

	class VertexBuffer
	{
	public:
		VertexBuffer(float* data, u32 size);
		~VertexBuffer() {};

		void Bind() const;
		void Unbind() const;

		void SetLayout(const BufferLayout& layout) { m_Layout = layout; };
		inline const BufferLayout& GetLayout() const { return m_Layout; };

	private:
		u32 m_VertexBufferID;
		u32 m_Size;
		BufferLayout m_Layout;
	};

	//////////////////////////////////////
	//			Index Buffer			//
	//////////////////////////////////////

	class IndexBuffer
	{
	public:
		IndexBuffer(usi* data, u32 count);
		IndexBuffer(u32* data, u32 count);
		~IndexBuffer();

		void Bind() const;
		void Unbind() const;

		inline u32 GetCount() const { return m_Count; }

	private:
		u32 m_BufferID;
		u32 m_Count;
	};

	//////////////////////////////////////
	//			Vertex Array			//
	//////////////////////////////////////

	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray() {};

		void Bind() const;
		void Unbind() const;

		void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer);
		void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer);

		const svec<Ref<VertexBuffer>> GetVertexBuffers() const { return m_VertexBuffers; }
		const Ref<IndexBuffer> GetIndexBuffer() const { return m_IndexBuffer; }

	private:
		uint32_t m_VertexArrayID;
		svec<Ref<VertexBuffer>> m_VertexBuffers;
		Ref<IndexBuffer> m_IndexBuffer;
	};

}