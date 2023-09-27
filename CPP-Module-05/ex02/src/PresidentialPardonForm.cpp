/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:09:34 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/11 15:10:44 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm( "PresidentialPardonForm" , 25, 5 ){
}

PresidentialPardonForm::PresidentialPardonForm( const std:: string target ):
	AForm( "PresidentialPardonForm" , 25, 5 ) , target_( target ){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) :
	AForm( "PresidentialPardonForm" , 25, 5 ), target_( src.target_ ){
		*this = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& rhs ){
	if (this != &rhs ){
		this->AForm::setIsSignedBool(rhs.AForm::getIsSignedBool());
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

void PresidentialPardonForm::execute( const Bureaucrat& executor ) const{
	if ( this->getIsSignedBool() == false ){
		std::cout << this->target_ << " can't be executed because: ";
		throw AForm::NotSignedException();
	}
	else if ( executor.getGrade() > this->getToExecuteGrade() ){
		std::cout << this->target_ << " can't be executed because: ";
		throw AForm::GradeTooLowException();
	}
	else{
			std::cout << target_ << " has been pardened by Zaphod Beeblebrox." << std::endl; 
	}
}