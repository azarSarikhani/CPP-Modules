/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:59:36 by asarikha          #+#    #+#             */
/*   Updated: 2023/10/19 09:48:11 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int ScalarConverter::actualInt = 0;
float ScalarConverter::actualFloat = 0;
double ScalarConverter::actualDouble = 0;
char ScalarConverter::actualChar = '\0';

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter& src){
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &rhs){
	(void) rhs;
	return *this;
}

ScalarConverter::~ScalarConverter(){
}

bool ScalarConverter::isChar(std::string &arg){
	if (arg.length() == 1 && std::isprint(arg.at(0)))
		return true;
	return false;
}

bool ScalarConverter::isInRange(std::string &arg, ScalarConverter::data_type type){
	long double n;
	
	if ( !isChar(arg) )
		n = std::stold(arg);
	else
		n = actualChar;
	switch (type) {
		case character:
			if ( n <= std::numeric_limits<char>::max() && n >= std::numeric_limits<char>::min() )
				return true;
			break;
		case double_float:
			if ( n <= std::numeric_limits<double>::max() && n >= -std::numeric_limits<double>::max() )
				return true;
			
			break;
		case floating_point:
			if ( n <= std::numeric_limits<float>::max() && n >= -std::numeric_limits<float>::max() )
				return true;
			break;
		case integer:
			if ( n <= std::numeric_limits<int>::max() && n >= std::numeric_limits<int>::min() )
				return true;
			break;
		default:
			break;
	}
	return false;
} 

bool ScalarConverter::isAlldigit( std::string &arg ){
	int j = 0;
	
	if (arg.at(j) == '-' || arg.at(j) == '+')
		j++;
	for ( int i (j); i < (int) arg.length(); i++){
		if(!std::isdigit(arg[i]))
			return false;
	}
	return true;	
}

bool ScalarConverter::isDoubleNum( std::string &arg ){
	if ( arg.find( '.' ) == 0 || arg.find( '.' ) == arg.length() - 1 )
		return false;
	int points_found = 0;
	int j = 0;
	
	if (arg.at(j) == '-' || arg.at(j) == '+')
		j++;
	for ( int i (j); i < (int) arg.length(); i++){
		if (arg.at(i) == '.'){
			points_found++;
			i++;
		}
		if ( points_found > 1 || !std::isdigit(arg[i]) )
			return false;
	}
	return true;
}

bool ScalarConverter::isFloatNum( std::string &arg ){
	if (arg.find ( '.' ) == std::string::npos || arg.back() != 'f'
		|| arg.find( '.' ) == 0 || arg.find( '.' ) == arg.length() - 2 )
		return false;
	int points_found = 0;
	int j = 0;
	
	if (arg.at(j) == '-' || arg.at(j) == '+')
		j++;
	for ( int i (j); i < (int) arg.length() - 1; i++){
		if (arg.at(i) == '.'){
			points_found++;
			i++;
		}
		if ( points_found > 1 || !std::isdigit(arg[i]) )
			return false;
	}
	return true;	
}

ScalarConverter::data_type	ScalarConverter::isInf_Nan(std::string &arg) {
	// for (std::string::iterator it = arg.begin(); it != arg.end(); it++)
	// 	*it = tolower(*it);
	if (!arg.compare("inf"))
		return (plus_infinite);
	else if (!arg.compare("+inf"))
		return (plus_infinite);
	else if (!arg.compare("-inf"))
		return (neg_infinite);
	else if (!arg.compare("inff"))
		return (plus_f_infinite);
	else if (!arg.compare("+inff"))
		return (plus_f_infinite);
	else if (!arg.compare("-inff"))
		return (neg_f_infinite);
	else if (arg.compare("nan") == 0)
		return not_a_number;
	else if (arg.compare("nanf") == 0)
		return not_a_number_f;
	return (not_found);
}

ScalarConverter::data_type ScalarConverter::setType(std::string &arg) {
	// for (std::string::iterator it = arg.begin(); it != arg.end(); it++)
	// 	*it = std::tolower(*it);
	data_type rvalue = not_found;
	if ( isAlldigit(arg) && isInRange(arg, integer) )
		return integer;
	if ( isChar(arg) ) 
		return character;
	if ( isDoubleNum(arg) && isInRange(arg, double_float) )
		return double_float;
	if ( isFloatNum(arg) && isInRange(arg, floating_point) )
		return floating_point;
	rvalue = isInf_Nan(arg);
	if (rvalue != not_found)
		return rvalue;
	
	return not_found;
}

/* __unused denotes variables and functions that may not be used, preventing
 * the compiler from warning about it if not used.
 */

void ScalarConverter::printChar(std::string  &arg, ScalarConverter::data_type /*__unused*/ type) {
	std::cout << "char: ";
	char c = 0; //char c = {0};
	switch (type)
	{
	case character:
		c = actualChar;
		break;
	case integer:
		c = static_cast< char >( actualInt );
		break;
	case double_float:
		c = static_cast< char >( actualDouble );
		break;
	case floating_point:
		c = static_cast< char >( actualFloat );
		break;
	
	default:
		break;
	}
	if ( !isInRange(arg, character) ){
		std::cout << "impossible" ;
	}
	else if ( isInRange(arg, character) && !std::isprint(c)){
		std::cout << "Not displayable";
	}
	else
		std::cout << "\'"<< c << "\'";
	std::cout << std::endl;
}

void ScalarConverter::printInt(std::string  &arg, ScalarConverter::data_type type) {
	std::cout << "int: ";
	int n = 0; 
	switch (type)
	{
	case character:
		n = static_cast< int >( actualChar );
		break;
	case integer:
		n = actualInt;
		break;
	case double_float:
		n = static_cast< int >( actualDouble );
		break;
	case floating_point:
		n = static_cast< int >( actualFloat );
		break;
	default:
		break;
	}
	if (type >= not_found ||  !isInRange(arg, integer) )
		std::cout << "impossible";
	else
		std::cout << n;
	std::cout << std::endl;
}

void ScalarConverter::printFloat( std::string  &arg, ScalarConverter::data_type type ){
	std::cout << "float: ";
	if (type == not_a_number || type == not_a_number_f )
			std::cout << "nanf";
	else if (type == plus_infinite || type == plus_f_infinite)
		std::cout << "+inff";
	else if (type == neg_infinite || type == neg_f_infinite)
		std::cout << "-inff";
	else{
		float f = 0; 
		switch (type)
		{
		case character:
			f = static_cast< float >( actualChar );
			break;
		case integer:
			f = static_cast< float >( actualInt ) ;
			break;
		case double_float:
			f = static_cast< float >( actualDouble );
			break;
		case floating_point:
			f = actualFloat;
			break;
		default:
			break;
		}
		if (type == not_found ||  !isInRange(arg, floating_point) )
			std::cout << "impossible";
		else if ( f - static_cast< int > (f) == 0 )
			std::cout << f << ".0f";
		else
			std::cout << f << "f";
	}
	std::cout << std::endl;
}

void ScalarConverter::printDouble( std::string &arg, ScalarConverter::data_type type ){
	std::cout << "double: ";
	if (type == not_a_number || type == not_a_number_f )
			std::cout << "nan";
	else if (type == plus_infinite || type == plus_f_infinite)
		std::cout << "+inf";
	else if (type == neg_infinite || type == neg_f_infinite)
		std::cout << "-inf";
	else{
		double d = 0; 
		switch (type)
		{
		case character:
			d = static_cast< double >(actualChar );
			break;
		case integer:
			d = static_cast< double >( actualInt ) ;
			break;
		case double_float:
			d = actualDouble;
			break;
		case floating_point:
			d = static_cast< double >( actualFloat );
			break;
		default:
			break;
		}
		if (type == not_found ||  !isInRange(arg, double_float) )
			std::cout << "impossible";
		else if (d - static_cast< int > (d) == 0)
			std::cout << d << ".0";
		else
			std::cout << d;
	}
	std::cout << std::endl;
}

void ScalarConverter::printImpossible ( void ){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

bool ScalarConverter::isImpossible( std::string &arg , data_type type ){
	try{
		if ( type == integer )
			actualInt = std::stoi( arg );
		else if ( type == floating_point )
			actualFloat = std::stof( arg );
		else if ( type == double_float )
			actualDouble = std::stod( arg );
		else if (  type == character )
			actualChar = arg[0];
	}
	catch ( std::exception &e ){
		printImpossible();
		return true;
	}
	return false;
}

void ScalarConverter::convert( std::string &arg ) {
	data_type type = setType(arg);
	if ( isImpossible(arg, type) )
		return;
	if ( type == not_found ){
		printImpossible();
		return;
	}
	printChar(arg, type);
	printInt(arg, type);
	printFloat(arg, type);
	printDouble(arg, type);
}
