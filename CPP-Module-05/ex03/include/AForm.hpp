/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:44:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/11 15:36:31 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string	name_;
	bool				signed_;
	const int			toSignGrade_;
	const int			toExecuteGrade_;
	AForm();
protected:
	void	setIsSignedBool(bool signStatus);
public:
// Constructors
	AForm(const AForm &src);
	AForm(int signGrade, int execGrade);
	AForm(const std::string name);
	AForm(const std::string name, int signGrade, int execGrade);
	
	AForm &operator=(const AForm &rhs);

// Destructors	
	virtual ~AForm();
	
// Getter
	const std::string getName(void)const;
	bool getIsSignedBool(void)const;
	int getToSignGrade(void)const;
	int getToExecuteGrade(void)const;
	
// Public Methods
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute ( Bureaucrat const & executor ) const = 0;
	
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
	class NotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
		//virtual const char *what() override noexcept;
			
	};
};
// ostream Overload
std::ostream	&operator<<(std::ostream &outputStream, AForm const &instance);

#endif