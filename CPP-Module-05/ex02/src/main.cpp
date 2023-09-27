/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:36:11 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/13 12:48:29 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){
	std::cout << " ------------ Creation and construction test -------------" << std::endl << std::endl;
	Bureaucrat Kelly("Kelly Kapor", 150);
	std::cout << Kelly << std::endl;
	
	Bureaucrat AssistantToTheRegionalManager("Dwight Schrute", 1);
	
	RobotomyRequestForm form28B("Andy");
	ShrubberyCreationForm form16C("Oscar");
	PresidentialPardonForm form71D("Kevin");
	//coment the signature for execution before signing or move the copies to be constructed here
	// form16C.beSigned(AssistantToTheRegionalManager);
	// form71D.beSigned(AssistantToTheRegionalManager);
	// form28B.beSigned(AssistantToTheRegionalManager);
	ShrubberyCreationForm form16C_copy = form16C;
	RobotomyRequestForm form28B_copy = form28B ;
	PresidentialPardonForm form71D_copy = form71D;
	std::cout << " ------------ Form class execute test by unqualified Bureaucrat-------------" << std::endl << std::endl;
	try
	{
		form71D.execute(Kelly);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		form28B.execute(Kelly);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		form16C.execute(Kelly);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << " ------------ Bureaucrat class executeForm test -------------" << std::endl << std::endl;
	Kelly.executeForm(form16C_copy);
	Kelly.executeForm(form71D_copy);
	Kelly.executeForm(form28B_copy);
	Kelly.executeForm(form16C);
	Kelly.executeForm(form71D);
	Kelly.executeForm(form28B);
	
	AssistantToTheRegionalManager.executeForm(form16C_copy);
	AssistantToTheRegionalManager.executeForm(form71D_copy);
	AssistantToTheRegionalManager.executeForm(form28B_copy);
	AssistantToTheRegionalManager.executeForm(form16C);
	AssistantToTheRegionalManager.executeForm(form71D);
	AssistantToTheRegionalManager.executeForm(form28B);

	std::cout << " ------------ Form class execute test by qualified Bureaucrat-------------" << std::endl << std::endl;
	try
	{
		form71D.execute(AssistantToTheRegionalManager);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		form28B.execute(AssistantToTheRegionalManager);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		form28B.execute(AssistantToTheRegionalManager);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		form16C.execute(AssistantToTheRegionalManager);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	AssistantToTheRegionalManager.executeForm(form16C);
	AssistantToTheRegionalManager.executeForm(form71D);
	AssistantToTheRegionalManager.executeForm(form28B);
		
	return EXIT_SUCCESS;
}