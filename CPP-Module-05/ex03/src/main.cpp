/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:36:11 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/12 13:21:36 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){
	Bureaucrat Kelly("Kelly Kapor", 150);
	Bureaucrat AssistantToTheRegionalManager("Dwight Schrute", 1);
	
	{
	Intern someRandomIntern;
	AForm* rrf;
	
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf->beSigned(AssistantToTheRegionalManager);
	rrf->execute(AssistantToTheRegionalManager);
	try
	{
		rrf->execute(Kelly);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (rrf != nullptr)
		delete rrf;
	
	AForm* invalidForm;
	invalidForm = someRandomIntern.makeForm("invalid robotomy request", "Bender");
	if (invalidForm != nullptr)
		delete rrf;
	}

	
	return EXIT_SUCCESS;
}