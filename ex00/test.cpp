#include <iostream>
#include <sstream>

int	main() {
	// std::string str("2147483648");
	// std::stringstream ss(str);

	// int d;
	// ss >> d;
	// if (ss.fail())
	// 	std::cerr << "fail" << std::endl;
	// else if (!ss.eof()) {
	// 	std::string other;
	// 	ss >> other;
	// 	std::cerr << "EOF Error " << other << std::endl;  
	// }
	// else {
	// 	std::cout << d << std::endl;
	// }
	double d;
	d = 30000000000000000000000000000000000000000000000000000000000000000000000000000.;
	// std::cout << static_cast<int>(d) << std::endl;
	std::cout << d << std::endl;

}

//30000000000000000000000000000000000000000000000000000000000000000000000000000.
