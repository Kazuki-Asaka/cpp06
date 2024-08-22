#include "ScalarConverter.hpp"
#include <sstream>

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
	if (num.size() != 1 || std::isdigit(num[0]) != 0)//
		return (false);
	else
		return (true);
}

bool ScalarConverter::check_float(std::string num) {
	if (num[num.length() -1 ] == 'f') {
		if (num == "inff" || num == "-inff" || num =="+inff")
			return (true);
		else {
			num.erase(num.length() - 1, 1);
			// std::cout << "num " << num << std::endl;
			std::stringstream ss(num);
			// std::string other;
			float f;
			
			ss >> f;
			// if (num == "inf" || num == "-inf" || num =="+inf" ||num == "nan" ||num == "+nan" || num == "-nan")
			// 	return (false);

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

// bool ScalarConverter::toChar(std::string num, std::string type) {
// 	if (type == TYPE_CHAR) {
// 		std::stringstream ss(num);
// 		char c;

// 		ss >> c;
// 		if (ss.fail()) {
// 			// std::cout << "test" << std::endl;
// 			// std::cout <<"'"<<c<<"'"<<std::endl;
// 			return (false);
// 		}
// 		else {
// 			// std::cout << "test1" << std::endl;

// 			std::cout << "char: " << "'" << c << "'" << std::endl;
// 			return(true);
// 		}
// 	}
// 	else {
// 		if (type == TYPE_FLOAT && num != "inf" && num != "-inf" && num !="+inf")
// 			num.erase(num.length() -1, 1);
// 		std::stringstream ss(num);
// 		int i;

// 		ss >> i;
// 		// std::cerr << "error check " << i << std::endl;
// 		if (ss.fail()) {
// 			std::cout << "char: " << "impossible" << std::endl;
// 			return (false);
// 		}
// 		if (!ss.eof()) {
// 			std::string other;
// 			ss >> other;
// 			// std::cout << "char length " << other.length() << std::endl;
// 			if (other.length() > 1) {
// 				for (size_t i=1; i < other.length();i++) {
// 					if (other[i] != '0') {
// 						std::cout << "char: " << "impossible" << std::endl;
// 						return (true);
// 					}
// 				}
// 			}
// 		}
// 		if (31 < i && i < 127)
// 			std::cout << "char: " << "'"<< static_cast<char>(i) << "'"<< std::endl;
// 		else
// 			std::cout << "char: " << "Non displayable" << std::endl;
// 		return (true);
// 	}
// }

// bool ScalarConverter::toInt(std::string num, std::string type) {
// 	if (type == TYPE_FLOAT && num != "inf" && num != "-inf" && num !="+inf")
// 		num.erase(num.length() -1, 1);
// 	std::stringstream ss(num);
// 	int i;

// 	ss >> i;
// 	if (ss.fail()) {
// 		std::cout << "int: " << "impossible" << std::endl;
// 		return(false);
// 	}
// 	if (!ss.eof()) {
// 		std::string other;

// 		ss >> other;
// 		for (size_t i = 1;i < other.length();i++) {
// 			if (other[i] != '0') {
// 				std::cout << "int: " << "impossible" << std::endl;
// 				return(false);
// 			}
// 		}
// 	}
// 	std::cout << "int: " << i << std::endl;
// 	return(true);
// }

// bool ScalarConverter::toFloat(std::string num, std::string type) {
// 	if (type == TYPE_FLOAT) {
// 		if (num[num.length() - 2] == '.'){
// 			num.erase(num.length() - 2,2);
// 			num += ".0f";
// 		}
// 		if (num == "+inf")
// 			num = "inf";
// 		std::cout << "float: " << num << std::endl;
// 		return (true);
// 	}
// 	if (num == "nan" || num == "+nan" ||num == "-nan") {
// 		std::cout << "float: " << "nanf" << std::endl;
// 		return (true);
// 	}
// 	if (type == TYPE_DOUBLE) {
// 		std::stringstream ss(num);
// 		float f;
// 		ss >> f;
// 		// num += "f";
		
// 		std::ostringstream oss;
// 		oss << f;
// 		std::string check_dot = oss.str();
// 		if (check_dot.find('.') != std::string::npos)
// 			std::cout << "float: " << f << "f"<< std::endl;
// 		else
// 			std::cout << "float: " << f << ".0f"<< std::endl;
// 		return (true);
// 	}
// 	std::stringstream ss1(num);
// 	float f;

// 	ss1 >> f;
// 	if (ss1.fail() ||!ss1.eof()) {
// 		std::cout << "float: " << "impossible" << std::endl;
// 		return (false);
// 	}
// 	else { 
// 		std::cout << "float: " << f << ".0f" << std::endl;
// 		return (true);
// 	}
// }

// bool ScalarConverter::toDouble(std::string num, std::string type) {
// 	if (type == TYPE_FLOAT && num != "inf" && num != "-inf" && num !="+inf")
// 		num.erase(num.length() -1, 1);
// 	std::stringstream ss(num);
// 	double d;

// 	ss >> d;
// 	if (ss.fail() ||!ss.eof()) {
// 		std::cout << "double: " << "impossible" << std::endl;
// 		return (false);
// 	}
// 	else {
//     	std::ostringstream ss1;
//     	std::string check_dot;
//     	ss1 << d;
// 		check_dot = ss1.str();
// 	// std::cout << "d " << d << std::endl;
//     	if (check_dot.find('.') != std::string::npos)
//     		std::cout << "double: " << d << std::endl;
//     	else
// 			std::cout << "double: " << d << ".0"<< std::endl;//
// 		// std::cout << "double: " << d << std::endl;//
// 		return (true);
// 	}
// }

bool ScalarConverter::printCharType(std::string num) {
	std::stringstream ss(num);
	char c;

	// std::cout << "num " << num << std::endl;
	ss >> c;
	// if (ss.fail() || !ss.eof()) {
	// 	std::cout << "char: " << "impossible" << std::endl;
	// 	std::cout << "here" << std::endl;
	// }
	// else {
	if (std::isprint(c) != 0)
		std::cout << "char: " << "'" << c << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	// }
	int i = static_cast<int>(c);
	std::cout << "int: " << i << std::endl;

	float f = static_cast<float>(c);
	std::cout << "float: " << f << ".0f"<< std::endl;

	double d = static_cast<double>(c);
	std::cout << "double: " << d << ".0" << std::endl;

	return (true);
}

bool ScalarConverter::printIntType(std::string num) {
	std::stringstream ss(num);
	int i;

	ss >> i;

	
	// char c = static_cast<char>(i);
	// if (std::isprint(c) != 0)
	// 	std::cout << "char: " << "'" << c << "'" << std::endl;
	// else
	// 	std::cout << "char: " << "Non displayable" << std::endl;

	if (0 <= i && i <= 127) {
		char c = static_cast<char>(i);
		if (std::isprint(c) != 0)
			std::cout << "char: " << "'" << c << "'" << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;
	}
	else
		std::cout << "char: " << "impossible" << std::endl;

	std::cout << "int: " << i << std::endl;

	float f = static_cast<float>(i);

	std::ostringstream oss;

	oss << f;
	std::string check_dotf(oss.str());
	if (check_dotf.find(".") == std::string::npos)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

	double d = static_cast<double>(i);
	oss.str("");
	oss << d;
	if (check_dotf.find(".") == std::string::npos)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;

	return (true);
}
//一回文字列に直して.を入れるか決める
//intmaxの場合floatは最後にfをつける

bool ScalarConverter::printFloatType(std::string num) {
	num.erase(num.length() - 1, 1);//ここでfを消さないとエラーになる
	std::stringstream ss(num);
	float f;

	ss >> f;
	// f = INT_MAX + 1;
	// if (!ss.eof() || ss.fail()) {
	// 	std::string other;
	// 	ss >> other;
	// 	std::cout << "other: "<< other << std::endl;
	// }
	// std::cout << "f: " << f << std::endl;

	// if ()
	if (num == "inf" || num == "+inf" || num == "-inf" || num == "nan" || num == "+nan" || num == "-nan") {//inffはfが消されてinfになる
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
	}
	else {
		// if (0 <= f && f <= 128)
		// std::cout << char_i << std::endl;
		std::stringstream ss1(num);
		int check;

		ss1 >> check;
		if (ss1.fail() || (check < 0 || check > 128))
			std::cout << "char: " << "impossible" << std::endl;
		else {
			char c;
			c = static_cast<char>(f);
			if (std::isprint(c) == 0)
				std::cout << "char: " << "Non displayable" << std::endl;
			else
				std::cout << "char: " << "'"<< c << "'" << std::endl;
		}

		int	i;
		i = static_cast<int>(f);
		std::cout << "int: " << i << std::endl;
	}
	std::ostringstream	oss;
	
	oss << f;
	std::string check_dotf(oss.str());
	if (check_dotf.find(".") != std::string::npos || check_dotf == "inf" || check_dotf == "-inf" || check_dotf == "nan")
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << f << ".0f" << std::endl;

	double d = static_cast<double>(f);
	oss.str("");
	oss << d;
	if (check_dotf.find(".") != std::string::npos || check_dotf == "inf" || check_dotf == "-inf" || check_dotf == "nan")
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;

	return (true);

}

bool ScalarConverter::printDoubleType(std::string num) {
	std::stringstream ss(num);
	double d;

	ss >> d;
	// if (!ss.eof() || ss.fail()) {
	// 	std::string other;
	// 	ss >> other;
	// 	std::cout << "other: "<< other << std::endl;
	// }
	// std::cout << "f: " << f << std::endl;

	// if ()
	if (num == "inf" || num == "+inf" || num == "-inf" || num == "nan" || num == "+nan" || num == "-nan") {//inffはfが消されてinfになる
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
	}
	else {
		std::stringstream ss1(num);

		int	check;

		ss1 >> check;
		if (ss1.fail() || (check < 0 || check > 128))
			std::cout << "char: " << "impossible" << std::endl;
		else {
			char c;
			c = static_cast<char>(d);
			if (std::isprint(c) == 0)
				std::cout << "char: " << "Non displayable" << std::endl;
			else
				std::cout << "char: " << "'"<< c << "'" << std::endl;
		}
		int	i;
		i = static_cast<int>(d);
		std::cout << "int: " << i << std::endl;
	}
	std::ostringstream	oss;
	
	oss << d;
	std::string check_dotf(oss.str());
	float f = static_cast<float>(d);
	if (check_dotf.find(".") != std::string::npos || check_dotf == "inf" || check_dotf == "-inf" || check_dotf == "nan")
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << f << ".0f" << std::endl;
	
	oss.str("");
	oss << d;
	if (check_dotf.find(".") != std::string::npos || check_dotf == "inf" || check_dotf == "-inf" || check_dotf == "nan")
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;

	return (true);
}

bool ScalarConverter::convert(char *str) {
	std::string num(str);

	// std::cout << "char   "<< ScalarConverter::check_char(num) << std::endl;
	// std::cout << "int    "<< ScalarConverter::check_int(num) << std::endl;
	// std::cout << "float  "<< ScalarConverter::check_float(num) << std::endl;
	// std::cout << "double "<< ScalarConverter::check_double(num) << std::endl;
	std::string type;
	type = check_type(num);
	// std::cout << "type: " << type << std::endl;
	if (type == TYPE_NO) {
		std::cerr << "input is invalid" << std::endl;
		return (false);
	}
	else if  (type == TYPE_CHAR) {
		printCharType(num);
		return(true);
	}
	else if (type == TYPE_INT) {
		printIntType(num);
		return(true);
	}
	else if (type == TYPE_FLOAT){
		printFloatType(num);
		return (true);
	}
	else if (type == TYPE_DOUBLE){
		printDoubleType(num);
		return (true);
	}
	else {
		std::cerr << "No Type" << std::endl;
		return (true);
	}
}
