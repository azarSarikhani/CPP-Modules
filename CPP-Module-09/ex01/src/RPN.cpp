/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:01:05 by asarikha          #+#    #+#             */
/*   Updated: 2023/11/02 11:37:50 by asarikha         ###   ########.fr       */
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
    std::istringstream ss(str);

    ss >> num;
    return num;
}

void	RPN::validateInput(std::string& input){
	if (!(input.find_first_not_of("0123456789+-/* ") == std::string::npos))
	    throw (std::invalid_argument ("Non-numeric characters can not be operated on neither numbers with decimals!"));
	std::stringstream exprecion(input);
    std::string s;
	while (exprecion >> s){
        //std::cout << "s : " << s << std::endl;
		if ( s[0] == '-' && !(s.find_first_of("0123456789") == std::string::npos) )
			throw (std::invalid_argument ("Negetive inputs are not allowd as an input!"));
        if ( s.find_first_of("0123456789") != std::string::npos && s.length() > 1 )
            throw (std::invalid_argument ("Input numbers have to be unsigned and seperated by a space!"));
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
                case '+': 
					if ( std::numeric_limits<int>::max() - left < right )
						throw (std::overflow_error ("RPN has overflowed try again with less operations!"));
					else
						result =  left + right ;
					break;
                case '-':
					if ( std::numeric_limits<int>::min() + right > left )
						throw (std::overflow_error ("RPN has overflowed try again with less operations!"));
					else
						result =  left - right ;	
					break;
                case '/':
					if ( right < 1 && right > 0 && std::numeric_limits<int>::max() * right < left )
						throw (std::overflow_error ("RPN has overflowed try again with less operations!"));
                    else if (right != 0)
                        result =  left / right; 
                    else
                        throw (std::runtime_error ("Division by zero is not possible!"));
                break;
                case '*':
                    if ( right > 0 && std::numeric_limits<int>::max() / right < left )
                            throw (std::overflow_error ("RPN has overflowed try again with less operations!"));
                    else if ( right < 0 && std::numeric_limits<int>::min() / right < left )
                            throw (std::overflow_error ("RPN has overflowed try again with less operations!"));
                    else
                        result =  left * right ;
                    break;
            }
            this->operationStack.push(result);
        }
        else
            this->operationStack.push(ft_stoi(s));
    }
    if (operationStack.size() > 1)
        throw (std::runtime_error ("Wrong format!"));
	std:: cout << "The final result is " <<  this->operationStack.top() << std::endl;
	return ;
}