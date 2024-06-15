#include "ScalarConverter.hpp"

bool ScalarConverter::check_int(std::string num) {
	std::stringstream ss(num);
	int i;

	ss >> i;
	if(ss.fail() || !ss.eof()) {
		// std::cout << i << std::endl;
		return (false);
	}
	else
		return (true);
}

bool ScalarConverter::check_char(std::string num) {
	if (num.size() != 1 || std::isprint(num[0] == 0))//
		return (false);
	else
		return (true);
}

bool ScalarConverter::check_float(std::string num) {
	if (num[num.length() -1] == 'f') {
		if (num == "inf" || num == "-inf" || num =="+inf")
			return (true);
		else {
			num.erase(num.length() - 1, 1);
			// std::cout << "num " << num << std::endl;
			std::stringstream ss(num);
			// std::string other;
			float f;
			
			ss >> f;
			if (num == "inf" || num == "-inf" || num =="+inf" ||num == "nan" ||num == "+nan" || num == "-nan")
				return (false);
			// ss >> other;
			// std::cerr << "error check " << f << std::endl;	
			// std::cerr << "error check1 " << other << std::endl;	
			if (ss.fail() || !ss.eof())
				return (false);
			else
				return (true);
		}
	}
	else
		return (false);
}

bool ScalarConverter::check_double(std::string num) {
	std::stringstream ss(num);
	double	d;

	ss >> d;
	if (ss.fail() || !ss.eof()) {
		return (false);
	}
	else
		return (true);
}

std::string ScalarConverter::check_type(std::string num) {
	if (ScalarConverter::check_char(num))
		return (TYPE_CHAR);
	else if(ScalarConverter::check_int(num))
		return (TYPE_INT);
	else if (ScalarConverter::check_float(num))
		return (TYPE_FLOAT);
	else if (ScalarConverter::check_double(num))
		return (TYPE_DOUBLE);
	else
		return (TYPE_NO);
}

bool ScalarConverter::toChar(std::string num, std::string type) {
	if (type == TYPE_CHAR) {
		std::stringstream ss(num);
		char c;

		ss >> c;
		if (ss.fail())
			return (false);
		else {
			std::cout << "char: " << c << std::endl;
			return(true);
		}
	}
	else {
		if (type == TYPE_FLOAT && num != "inf" && num != "-inf" && num !="+inf")
			num.erase(num.length() -1, 1);
		std::stringstream ss(num);
		int i;

		ss >> i;
		// std::cerr << "error check " << i << std::endl;
		if (ss.fail()) {
			std::cout << "char: " << "impossible" << std::endl;
			return (false);
		}
		if (!ss.eof()) {
			std::string other;
			ss >> other;
			// std::cout << "char length " << other.length() << std::endl;
			if (other.length() > 1) {
				for (size_t i=1; i < other.length();i++) {
					if (other[i] != '0') {
						std::cout << "char: " << "impossible" << std::endl;
						return (true);
					}
				}
			}
		}
		if (31 < i && i < 127)
			std::cout << "char: " << static_cast<char>(i) << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;
		return (true);
	}
}

bool ScalarConverter::toInt(std::string num, std::string type) {
	if (type == TYPE_FLOAT && num != "inf" && num != "-inf" && num !="+inf")
		num.erase(num.length() -1, 1);
	std::stringstream ss(num);
	int i;

	ss >> i;
	if (ss.fail()) {
		std::cout << "int: " << "impossible" << std::endl;
		return(false);
	}
	if (!ss.eof()) {
		std::string other;

		ss >> other;
		for (size_t i = 1;i < other.length();i++) {
			if (other[i] != '0') {
				std::cout << "int: " << "impossible" << std::endl;
				return(false);
			}
		}
	}
	std::cout << "int: " << i << std::endl;
	return(true);
}

bool ScalarConverter::toFloat(std::string num, std::string type) {
	if (type == TYPE_FLOAT) {
		if (num[num.length() - 2] == '.'){
			num.erase(num.length() - 2,2);
			num += ".0f";
		}
		if (num == "+inf")
			num = "inf";
		std::cout << "float: " << num << std::endl;
		return (true);
	}
	if (num == "nan" || num == "+nan" ||num == "-nan") {
		std::cout << "float: " << "nan" << std::endl;
		return (true);
	}
	if (type == TYPE_DOUBLE) {
		num += "f";
		std::cout << "float: " << num << std::endl;
		return (true);
	}
	std::stringstream ss(num);
	float f;

	ss >> f;
	if (ss.fail() ||!ss.eof()) {
		std::cout << "float: " << "impossible" << std::endl;
		return (false);
	}
	else { 
		std::cout << "float: " << f << ".0f" << std::endl;
		return (true);
	}
}

bool ScalarConverter::toDouble(std::string num, std::string type) {
	if (type == TYPE_FLOAT && num != "inf" && num != "-inf" && num !="+inf")
		num.erase(num.length() -1, 1);
	std::stringstream ss(num);
	double d;

	ss >> d;
	if (ss.fail() ||!ss.eof()) {
		std::cout << "double: " << "impossible" << std::endl;
		return (false);
	}
	else {
		std::cout << "double: " << d << std::endl;
		return (true);
	}
}

bool ScalarConverter::convert(char *str) {
	std::string num(str);

	// std::cout << "char   "<< ScalarConverter::check_char(num) << std::endl;
	// std::cout << "int    "<< ScalarConverter::check_int(num) << std::endl;
	// std::cout << "float  "<< ScalarConverter::check_float(num) << std::endl;
	// std::cout << "double "<< ScalarConverter::check_double(num) << std::endl;
	std::string type;

	type = check_type(num);
	if (type == TYPE_NO) {
		std::cerr << "input is ivalid" << std::endl;
		return (false);
	}
	else {
		std::cout << type << std::endl;
		toChar(num, type);
		toInt(num, type);
		toFloat(num, type);
		toDouble(num, type);
		return (true);
	}
}