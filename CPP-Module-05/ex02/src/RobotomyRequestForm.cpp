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

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm( "RobotomyRequestForm" , 72, 45 ){
}

RobotomyRequestForm::RobotomyRequestForm( const std:: string target ):
	AForm( "RobotomyRequestForm" , 72, 45 ) , target_( target ){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :
	AForm( "RobotomyRequestForm" , 72, 45 ), target_( src.target_ ){
		*this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& rhs ){
	if (this != &rhs ){
		this->AForm::setIsSignedBool(rhs.AForm::getIsSignedBool());
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

void RobotomyRequestForm::execute( const Bureaucrat& executor ) const{
	if ( this->getIsSignedBool() == false ){
		std::cout << this->target_ << " can't be executed because: ";
		throw AForm::NotSignedException();
	}
	else if ( executor.getGrade() > this->getToExecuteGrade() ){
		std::cout << this->target_ << " can't be executed because: ";
		throw AForm::GradeTooLowException();
	}
	else{
		static int i = 0;
		if ( i % 2 == 0 )
			std::cout << "A very clear drill_made vibrating noise " << std::endl << this->target_ << " has been robotomized." << std::endl; 
		else
			std::cout << "Robotomy failed." << std::endl;
		i++;
	}
}