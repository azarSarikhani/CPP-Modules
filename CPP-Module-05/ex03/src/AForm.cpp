/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:49:19 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/11 15:00:42 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name_("Default Aform"), signed_(false), toSignGrade_(150), toExecuteGrade_(150){
	std::cout << "AForm default constructor created " << this->getName() << std::endl;
}

AForm::AForm(const std::string name) : name_(name), signed_(false), toSignGrade_(150), toExecuteGrade_(150){
	std::cout << "AForm constructor created " << this->getName() << std::endl;
}

AForm::AForm(int signGrade, int execGrade) : name_("Unnamed Aform"), signed_(false), toSignGrade_(signGrade), toExecuteGrade_(execGrade){
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	std::cout << "AForm constructor created " << this->getName() << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int execGrade) : name_(name), signed_(false), toSignGrade_(signGrade), toExecuteGrade_(execGrade){
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	std::cout << "AForm constructor created " << this->getName() << std::endl;
}

AForm::AForm(const AForm &src): name_( src.getName() ), toSignGrade_( src.getToSignGrade() ), toExecuteGrade_( getToExecuteGrade() ){
	std::cout << "AForm copy constructor created " << this->getName() << std::endl;
	*this = src;
}

AForm& AForm::operator=(const AForm& rhs ){
	if (this != &rhs )
		this->signed_ = rhs.getToSignGrade();
	std::cout << this->name_ << " is assigned by the AForm's assignment operator overload!" << std::endl;
	return *this;
}

AForm::~AForm(){
	std::cout << "AForm destructor destroyed " << this->getName() << std::endl;
}

const std::string AForm::getName(void) const{
	return ( this->name_ );
}

bool AForm::getIsSignedBool(void)const{
	return ( this->signed_ );
}

int AForm::getToSignGrade(void)const{
	return ( this->toSignGrade_ );
}

int AForm::getToExecuteGrade(void)const{
	return ( this->toExecuteGrade_);
}

void AForm::beSigned(const Bureaucrat &bureaucrat){
	if ( bureaucrat.getGrade() > this->toSignGrade_ )
	throw AForm::GradeTooLowException();
	this->signed_ = true;
}

void	AForm::setIsSignedBool(bool signStatus){
	this->signed_ = signStatus;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("The Form is not signed!");
}

std::ostream	&operator<<(std::ostream &outputStream, AForm const &instance){
	outputStream << "AForm info: " << std::endl;
	outputStream << "AForm name: " << instance.getName() << std::endl;
	outputStream << "Grade to sign: " << instance.getToSignGrade() << std::endl;
	outputStream << "Grade to execute: " << instance.getToExecuteGrade() << std::endl;
	return (outputStream);
}
