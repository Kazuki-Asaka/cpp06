#include <iostream>
#include <sstream>

int	main(int argc, char** argv) {
	std::string str = "-inf";
	std::stringstream ss(str);
	float d;
	ss >> d;
	if (ss.fail() || !ss.eof())
		std::cout << "error" << std::endl;
	else
		std::cout << d << std::endl;
}