/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:38:20 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/13 12:53:12 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern( const Intern& src );
	Intern& operator=( const Intern& rhs );
	~Intern();
	
	AForm* makeForm ( std::string name, std::string target );

private:
	static AForm *makePresidentialForm( std::string const target );
	static AForm *makeRobotomyForm( std::string const target );
	static AForm *makeShrubberyForm( std::string const target );
};

#endif
