/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:56:04 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/18 13:44:19 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <string>


class ScalarConverter
{
public:
	enum data_type {
			character,
			integer,
			double_float,
			floating_point,
			not_found, 
			plus_infinite,
			neg_infinite,
			plus_f_infinite,
			neg_f_infinite,
			not_a_number,
			not_a_number_f
		};
		
	static  void convert(std::string &arg);
private:
	ScalarConverter();
	ScalarConverter( const ScalarConverter& src );
	ScalarConverter& operator=(const ScalarConverter& rhs);
	~ScalarConverter();
	
	static int		 actualInt;
	static float	 actualFloat;
	static double	 actualDouble;
	static char		 actualChar;
	
	static data_type setType(std::string &arg);
	static bool isChar(std::string &arg);
	static bool isAlldigit(std::string &arg);
	static bool isInRange(std::string &arg, data_type type);
	static data_type isInf_Nan(std::string &arg);
	static bool isDoubleNum( std::string &arg );
	static bool isFloatNum( std::string &arg );
	static void printChar(std::string &arg, data_type type);
	static void printInt(std::string &arg, data_type type);
	static void printFloat( std::string &arg, data_type type );
	static void printDouble(std::string &arg, data_type type);
	static bool isImpossible( std::string &arg, data_type type );
	static void printImpossible ( void );
};

#endif