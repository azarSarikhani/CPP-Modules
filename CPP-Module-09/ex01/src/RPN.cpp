/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:01:05 by asarikha          #+#    #+#             */
/*   Updated: 2023/10/23 10:50:12 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN( const RPN& src ){
	*this = src;
}

RPN&  RPN::operator=( const RPN &rhs ){
	(void) rhs;
	return *this;
}

RPN::~RPN()
{
}

int RPN::ft_stoi(const std::string& str)
{
    int num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

void	RPN::validateInput(std::string& input){
	if (input.find_first_not_of("0123456789+-/* ") == std::string::npos)
	    return ;
	throw (std::invalid_argument ("Non-numeric characters can not be operated on!"));
	std::stringstream exprecion(input);
    std::string s;
	while (exprecion >> s){
		if ( s[0] == '-' && s.find_first_not_of("0123456789") != std::string::npos )
			throw (std::invalid_argument ("Negetiive numbers are not allowd as an input!"));
	}
	
}

void	RPN::calculateResult(std::string& input){
	int left;
    int right;
    int result;
    std::stringstream postfix(input);
    std::string s;

    while (postfix >> s)
    {
        if (s == "+" || s == "-" || s == "/" || s == "*")
        {
            if (this->operationStack.size() < 2)
                throw (std::runtime_error ("Wrong format!"));                
            right = this->operationStack.top();
            this->operationStack.pop();
            left = this->operationStack.top();
            this->operationStack.pop();
            switch (s[0])
            {
                case '+': result =  left + right ; break;
                case '-': result =  left - right ; break;
                case '/':
                    if (right != 0)
                        result =  left / right; 
                    else
                        throw (std::runtime_error ("Division by zero is not possible!"));
                break;
                case '*': result =  left * right ; break;
            }
            this->operationStack.push(result);
        }
        else
            this->operationStack.push(ft_stoi(s));
    }
	std:: cout << "The final result is " <<  this->operationStack.top() << std::endl;
	return ;
}