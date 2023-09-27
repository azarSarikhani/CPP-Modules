/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:36:11 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/13 12:28:30 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void){
	try
	{
		Bureaucrat AssistantToTheRegionalManager("Dwight Schrute", 1);
		std::cout << AssistantToTheRegionalManager << std::endl;
		AssistantToTheRegionalManager.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	Bureaucrat *Jim = new Bureaucrat("Jim Halpert", 5);
	std::cout << *Jim << std::endl;
	try
	{
		Jim->incrementGrade();
		std::cout << Jim << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete Jim;
	
	std::cout << std::endl;
	Bureaucrat *Angela = NULL;
	try
	{
		Angela = new Bureaucrat("Angela Martin", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (Angela != NULL){
		delete Angela;
	}
	
	std::cout << std::endl;
	Bureaucrat Kelly("Kelly Kapor", 150);
	std::cout << Kelly << std::endl;
	try
	{
		Kelly.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try
	{
		Bureaucrat Tony("Tony Flenderson", 300);
		std::cout << Tony << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
	return EXIT_SUCCESS;
}