#ifndef __LIST_H
#define __LIST_H

namespace m34
{
	template<class T>
	class Node
	{
	public:
		T data;
		Node* next;
		Node(T data)
		{
			this->data = data;
			this->next = nullptr;
		}	
		Node(T data, Node* next)
		{
			this->data = data;
			this->next = next;
			next->next = nullptr;
		}
		
		void operator=(Node* other)
		{
			this->data = other->data;
			this->next = other->next;
		}

		static Node* CreateNode(T data)
		{
			Node<T>* node = new Node<T>(data);
			return node;
		}


	};
}

#endif
