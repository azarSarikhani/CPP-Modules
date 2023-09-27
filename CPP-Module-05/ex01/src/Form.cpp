/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:49:19 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/13 12:39:59 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name_("Default form"), signed_(false), toSignGrade_(150), toExecuteGrade_(150){
	std::cout << "Form default constructor created " << this->getName() << std::endl;
}

Form::Form(const std::string name) : name_(name), signed_(false), toSignGrade_(150), toExecuteGrade_(150){
	std::cout << "Form constructor created " << this->getName() << std::endl;
}

Form::Form(int signGrade, int execGrade) : name_("Unnamed form"), signed_(false), toSignGrade_(signGrade), toExecuteGrade_(execGrade){
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form constructor created " << this->getName() << std::endl;
}

Form::Form(const std::string name, int signGrade, int execGrade) : name_(name), signed_(false), toSignGrade_(signGrade), toExecuteGrade_(execGrade){
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form constructor created " << this->getName() << std::endl;
}

Form::Form(const Form &src): name_( src.getName() ), toSignGrade_( src.getToSignGrade() ), toExecuteGrade_( getToExecuteGrade() ){
	std::cout << "Form copy constructor created " << this->getName() << std::endl;
	*this = src;
}

Form& Form::operator=(const Form& rhs ){
	if (this != &rhs )
		this->signed_ = rhs.getToSignGrade();
	std::cout << this->name_ << " is assigned by the Form's assignment operator overload!" << std::endl;
	return *this;
}

Form::~Form(){
	std::cout << "Form destructor destroyed " << this->getName() << std::endl;
}

const std::string Form::getName(void) const{
	return ( this->name_ );
}

bool Form::getIsSignedBool(void)const{
	return ( this->signed_ );
}

int Form::getToSignGrade(void)const{
	return ( this->toSignGrade_ );
}

int Form::getToExecuteGrade(void)const{
	return ( this->toExecuteGrade_);
}

void Form::beSigned(const Bureaucrat &bureaucrat){
	if ( bureaucrat.getGrade() > this->toSignGrade_ )
		throw Form::GradeTooLowException();
	this->signed_ = true;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}
std::ostream	&operator<<(std::ostream &outputStream, Form const &instance){
	outputStream << "Form info: " << std::endl;
	outputStream << "Form name: " << instance.getName() << std::endl;
	outputStream << "Grade to sign: " << instance.getToSignGrade() << std::endl;
	outputStream << "Grade to execute: " << instance.getToExecuteGrade() << std::endl;
	return (outputStream);
}
