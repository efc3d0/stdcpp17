#ifndef __ITERATOR_H
#define __ITERATOR_H

namespace m34
{
	namespace iterators
	{
		template<class T>
		class Iterator
		{
			using value_type = T;
			using pointer_type = T*;
			using reference_type = T&;

			T* pointer;
		public:
			Iterator(T* ptr) : pointer(ptr){}
			
			T& operator*() { return *pointer; }
			
			T& operator++()
			{
				++pointer;
				return *this;
			}
			
			T& operator++(int)
			{
				auto tmp = *this;
				++tmp;
				return tmp;
			}	

		};

		template<class T>
		class BackwardIterator : public Iterator<T>
		{
			T* pointer;
		public:
			BackwardIterator(T* ptr) 
			{
				pointer = ptr;
			}

			T& operator--()
			{
				--pointer;
				return *this;
			}

			T& operator--(int)
			{
				auto tmp = *this;
				--tmp;
				return tmp;
			}
		};
	}
}

#endif
