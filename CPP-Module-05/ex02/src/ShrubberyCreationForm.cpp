/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:05:12 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/12 15:30:04 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm( "ShrubberyCreationForm" , 145, 137 ){
}

ShrubberyCreationForm::ShrubberyCreationForm( const std:: string target ):
	AForm( "ShrubberyCreationForm" , 145, 137 ) , target_( target ){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) :
	AForm( "ShrubberyCreationForm" , 145, 137 ), target_( src.target_ ){
		*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& rhs ){
	if (this != &rhs ){
		this->AForm::setIsSignedBool(rhs.AForm::getIsSignedBool());
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

void ShrubberyCreationForm::execute( const Bureaucrat& executor ) const{
	if ( this->getIsSignedBool() == false ){
		std::cout << this->target_ << " can't be executed because: ";
		throw AForm::NotSignedException();
	}
	else if ( executor.getGrade() > this->getToExecuteGrade() ){
		std::cout << this->target_ << " can't be executed because: ";
		throw AForm::GradeTooLowException();
	}
	else{
	std::ofstream file;
	if (file.fail())
		std::cerr << "file creation failed." << std::endl;
	file.open( (this->getName() + "_shrubbery ").c_str() );
	file << "                                                                                                                        " << std::endl;
	file << "                                                                                                                        " << std::endl;
	file << "                # #### ####                           # #### ####                           # #### ####                 " << std::endl;
	file << "              ### ###|### |/####                    ### ###|### |/####                    ### ###|### |/####            " << std::endl;
	file << "             #####/ #||/##/_/##/_#                 #####/ #||/##/_/##/_#                 #####/ #||/##/_/##/_#          " << std::endl;
	file << "           ###  #####|/ ## # ###                 ###  #####|/ ## # ###                 ###  #####|/ ## # ###            " << std::endl;
	file << "         ##_#_##_### | #/###_/_####            ##_#_##_### | #/###_/_####            ##_#_##_### | #/###_/_####         " << std::endl;
	file << "        ## #### # # #| /  #### ##/##          ## #### # # #| /  #### ##/##          ## #### # # #| /  #### ##/##        " << std::endl;
	file << "         __#_--###`  |{,###---###-~            __#_--###`  |{,###---###-~            __#_--###`  |{,###---###-~         " << std::endl;
	file << "                    }}{                                   }}{                                   }}{                     " << std::endl;
	file << "                    }}{                                   }}{                                   }}{                     " << std::endl;
	file << "                    }}{                                   }}{                                   }}{                     " << std::endl;
	file << "                    {{}                                   {{}                                   {{}                     " << std::endl;
	file << "              , -=-~{ .-^- _                        , -=-~{ .-^- _                        , -=-~{ .-^- _                " << std::endl;
	file << "                    `}                                    `}                                    `}                      " << std::endl;
	file << "                     {                                     {                                     {                      " << std::endl;
	file << "                                                                                                                        " << std::endl;
	file << "                                                                                                                        " << std::endl;
	file.close();
	}
}