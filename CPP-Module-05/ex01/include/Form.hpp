/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:44:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/07 13:45:08 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string	name_;
	bool				signed_;
	const int			toSignGrade_;
	const int			toExecuteGrade_;
	
	Form();
	
public:
// Constructors
	Form(const Form &src);
	Form(int signGrade, int execGrade);
	Form(const std::string name);
	Form(const std::string name, int signGrade, int execGrade);
	
	Form &operator=(const Form &rhs);

// Destructors	
	~Form();
	
// Getter
	const std::string getName(void)const;
	bool getIsSignedBool(void)const;
	int getToSignGrade(void)const;
	int getToExecuteGrade(void)const;
	
// Public Methods
	void beSigned(const Bureaucrat &bureaucrat);
	
//Exceptions
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
		//virtual const char *what() override noexcept;
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
		//virtual const char *what() override noexcept;
	};
};
// ostream Overload
std::ostream	&operator<<(std::ostream &outputStream, Form const &instance);

#endif