#include "ScalarConverter.hpp"

int	main() {
	// std::stringstream ss("42.");
	// float f;

	// // ss >> f;
	// // std::cout << 
	// f = nanf;
	// std::cout << f << std::endl;

	float f;
	std::stringstream ss("-nan");

	ss >> f;
	std::cout << f << std::endl;
	
}