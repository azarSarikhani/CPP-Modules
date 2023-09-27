/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:19:05 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/07 14:56:20 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	const std::string	name_;
	int					grade_;
	
	Bureaucrat();
	
public:
// Constructors
	Bureaucrat(int grade);
	Bureaucrat(const std::string name, int grade) throw (GradeTooLowException, GradeTooHighException);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat& rhs );
// Destructors
	~Bureaucrat();
// Public Methods
	void				incrementGrade(void);
	void 				decrementGrade(void);
// Getter
	const std::string	getName(void)const;
	int 				getGrade(void)const;
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
std::ostream	&operator<<(std::ostream &outputStream, Bureaucrat const &instance);

#endif
