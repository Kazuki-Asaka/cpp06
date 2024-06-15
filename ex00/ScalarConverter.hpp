#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>

#define TYPE_INT	"int"
#define TYPE_CHAR 	"char"
#define TYPE_FLOAT	"float"
#define TYPE_DOUBLE	"double"
#define TYPE_NO		""

class ScalarConverter {
public:
	static bool convert(char *str);
private:
	ScalarConverter();
	static bool check_int(std::string num);
	static bool check_char(std::string num);
	static bool check_float(std::string num);
	static bool check_double(std::string num);
	static std::string check_type(std::string num);
	static bool toInt(std::string num, std::string type);
	static bool toChar(std::string num, std::string type);
	static bool toFloat(std::string num, std::string type);
	static bool toDouble(std::string num, std::string type);
};

#endif

//0.0, 0の時の対応