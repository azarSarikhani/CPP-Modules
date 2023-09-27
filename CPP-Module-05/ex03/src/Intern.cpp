/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:40:44 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/13 12:55:34 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
}

Intern::Intern( const Intern& src ){
	*this = src;
}

Intern& Intern::operator=( const Intern& rhs ){
	( void ) rhs;
	return ( *this );
}

Intern::~Intern(){
}

AForm *Intern::makeShrubberyForm( std::string const target ){
	return ( new ShrubberyCreationForm(target) );
}

AForm *Intern::makePresidentialForm( std::string const target ){
	return ( new PresidentialPardonForm( target ) );
}

AForm *Intern::makeRobotomyForm( std::string const target ){
	return ( new RobotomyRequestForm( target ) );
}

AForm* Intern::makeForm ( std::string name, std::string target ){
	std::string names[] = {
		"shrubbery creation",
		"robotomy request", 
		"presidential pardon"
	};
	
	static AForm*	(*funct[])( std::string const target) = {
		&makeShrubberyForm,
		&makeRobotomyForm,
		&makePresidentialForm
	};
	
	AForm	*form = 0;
	for ( int i(0); i < 3; i++ ){
		if ( name == names[i] ){
			std::cout << "Intern creates " << name << std::endl;
			form = funct[i](target);
			return form;
		}
	}
	std::cout << "!!      An explicit error message     !!" << std::endl;
	std::cout << " Intern can not create "  << name << std::endl;
	std::cout << "!! This was an explicit error message !!" << std::endl;
	return nullptr;
}