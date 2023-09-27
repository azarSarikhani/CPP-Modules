/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:20:46 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/13 12:51:02 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("default"), grade_(150){
	std::cout << "Bureaucrat Default Constructor created " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : name_("default"){
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
	" with grade of " << grade << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade_ = grade;
	
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name_(name) {
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
	" with grade of " << grade << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src){
	std::cout << "Bureaucrat Copy Constructor created a copy of " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs ){
	if (this != &rhs )
	{
		this->grade_ = rhs.grade_;
	}
	std::cout << this->grade_ << " is assigned by the Bureaucrat's assignment operator overload!" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat Destructor destroyed " << this->getName() << std::endl;
}

void Bureaucrat::incrementGrade(){
	if (this->grade_ - 1 < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else
		grade_--;
}

void Bureaucrat::decrementGrade(){
	if (this->grade_ + 1 > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else
		grade_--;
}

const std::string	Bureaucrat::getName(void)const
{
	return (this->name_);
}

int	Bureaucrat::getGrade( void )const
{
	return (this->grade_);
}


void	Bureaucrat::signForm( AForm &form )
{
	try{
		form.beSigned( *this );
		std::cout << *this << "signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e){
		std::cout << *this << "can't sign " << form.getName() << "because" << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm( AForm const & form ){
	try{
		form.execute( *this );
		std::cout << *this << "executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e){
		std::cout << *this << "can't execute " << form.getName() << "because" << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &outputStream, Bureaucrat const &instance)
{
	outputStream << "Bureaucrat :" << instance.getName() << "    grade: " << instance.getGrade() << " ";
	return (outputStream);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}
