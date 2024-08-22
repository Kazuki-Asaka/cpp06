#include <iostream>
#include <sstream>

// int	main(int argc, char** argv) {
// 	std::string str = "2.14748e+09";
// 	std::stringstream ss(str);
// 	float d;
// 	ss >> d;
// 	if (ss.fail())
// 		std::cout << "error" << std::endl;
// 	else if(!ss.eof())
// 		std::cout << "error1" << std::endl;
// 	else
// 		std::cout << d << std::endl;


// 	float f1 = 2.14748e+09f;
// 	std::cout << f1 << std::endl;
	// char c = 'a';
	// std::cout << "c: " << c << std::endl;

	// int d;

	// d = static_cast<int>(c);
	// std::cout << "d: " << d << std::endl;

	// std::cout << 

	// int i = 42.5;
	// char c1;

	// c1 = static_cast<char>(i);
	// std::cout << "char " << c1 << std::endl;

	// char c2;
	// c2 = reinterpret_cast<char>(i);


// 	int d1 = 42.;
// 	std::cout << "d1: " << d1 << std::endl;
// }

int main() {
	// std::stringstream ss(num);

	// float f;
	// ss >> f;
	// if (ss.fail())
	// 	std::cout << "error" << std::endl;
	// else
	// 	std::cout << "float: " << f << std::endl;

	// std::stringstream ss1(num);
	// int i;

	// ss1 >> i;
	// if (ss1.fail())
	// 	std::cout << "error" << std::endl;
	// else if (!ss1.eof())
	// {
	// 	std::string other;
	// 	ss1 >> other;
	// 	std::cout << other << std::endl;
	// }
	// std::cout << "cast_test: " << i << std::endl; 
	// float b = 42.0f;




	// std::string num = "2147483648";
	// double d = 2147483646.5;
	// // double d = -2147483649;

	// signed char d1 = static_cast<signed char>(d);
	// int  d2 = static_cast<int>(d1);

	// std::cout << d << std::endl;
	// printf("d1: %X\n", d1);
	// // std::cout << std::hex << d1 << std::endl;
	// std::cout << d2 << std::endl;

	// std::string num = "a";
	// std::stringstream ss(num);

	// char c;

	// ss >> c;
	// if (ss.fail())
	// 	std::cerr << "fail" << std::endl;
	// else if (!ss.eof())
	// 	std::cerr << "eof" << std::endl;
	// else
	// 	std::cout << c << std::endl;

	//
	// std::cout << static_cast<float>(i) << std::endl;
	// std::cout << static_cast<double>(i) << std::endl;

	// int d = -100;
	// std::cout << static_cast<char>(i) << std::endl;

	// std::cout << std::isprint(static_cast<char>(i)) << std::endl;

	std::stringstream ss("-2147483649");

	double d;
	ss >> d;
	std::cout << d << std::endl;

	std::stringstream ss1("-2147483648.5");

	float f;
	ss1>> f;
	std::cout << f << std::endl;
}