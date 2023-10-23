/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:59:53 by asarikha          #+#    #+#             */
/*   Updated: 2023/10/23 10:34:59 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
# include <sstream>

class RPN
{
private:
	std::stack<int> operationStack;
public:
	RPN();
	RPN( const RPN& src );
	RPN& operator=( const RPN& rhs );
	~RPN();
	
	void	validateInput(std::string& input);
	void	calculateResult(std::string& input);
	int		ft_stoi(const std::string& str);
};


#endif