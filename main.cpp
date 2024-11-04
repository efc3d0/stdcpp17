#include <iostream>
#include "IO.hpp"
#include "string.hpp"
#include "list.hpp"

int
main (void)
{
	m34::RWIo<char*> t;
		
	char* buffer = "kengg";
	char* buffer2 = "gubami";
	m34::Node<char*> root(buffer, m34::Node<char*>::CreateNode(buffer2));

	std::cout << root.data << "\n"; 
	root = root.next;
	std::cout << root.data << "\n";

}
