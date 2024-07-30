#include "Serializer.hpp"

int main() {
	{
		std::cout << "=============Test==============" << std::endl;
		Data *test;
		
		test = new Data;
		test->i = 9999;

		uintptr_t ptr;

		ptr = Serializer::serialize(test);
		std::cout << "serialize: " << ptr << std::endl;
		
		// std::cout << "deserialize: " << Serializer::deserialize(ptr) -> i<< std::endl;
		if (ptr != 0)
			std::cout << "deserialize: " << Serializer::deserialize(ptr) -> i<< std::endl;
		else
			std::cout << "cannot deserialize" << std::endl;
		delete(test);
	}
	{
		std::cout << "=============Test==============" << std::endl;
		Data *test1;
		test1 = NULL;

		uintptr_t ptr;

		ptr = Serializer::serialize(test1);
		std::cout << "serialize: " << ptr << std::endl;

		if (ptr != 0)
			std::cout << "deserialize: " << Serializer::deserialize(ptr) -> i<< std::endl;
		else
			std::cout << "cannot deserialize" << std::endl;
	}
}