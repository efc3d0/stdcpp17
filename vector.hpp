#ifndef __VECTOR_H
#define __VECTOR_H

#include "iterator.hpp"

namespace m34
{
	template<class T>
	void swap(T& first, T& second)
	{
		T tmp = first;
		first = second;
		second = tmp;
	}

	template<class T>
	class vector
	{
		T* buffer;
		unsigned int size;
		int putchar;

	public:
		vector(unsigned int value)
		{
			size = 0;
			putchar = 0;
			buffer = new T[value * sizeof(T)];
		}

		~vector()
		{
			delete[] buffer;
		}
		
		void add(T value)
		{
			buffer[putchar] = value;
			++putchar;
		}

		T& operator[](unsigned int index)
		{
			if(index > putchar)
				putchar = index;
			return buffer[index];
		}
		
		T& operator=(T other)
		{
			swap(buffer, other.buffer);
			return *this;
		}

		iterators::BackwardIterator<T> begin()
		{
			return iterators::BackwardIterator<T>(buffer[0]);
		}

		iterators::BackwardIterator<T> end()
		{
			return iterators::BackwardIterator<T>(putchar);
		}


	};
}

#endif
