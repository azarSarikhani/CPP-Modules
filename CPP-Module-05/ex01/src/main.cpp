/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:36:11 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/14 09:48:32 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void){
	Form someVeryTopSecrectForm("Top secrect form", 1, 1);
	Bureaucrat Kelly("Kelly Kapor", 150);
	std::cout << Kelly << std::endl;
	try
	{
		Kelly.signForm(someVeryTopSecrectForm);
		std::cout << someVeryTopSecrectForm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try
	{
		Bureaucrat AssistantToTheRegionalManager("Dwight Schrute", 1);
		std::cout << AssistantToTheRegionalManager << std::endl;
		AssistantToTheRegionalManager.signForm(someVeryTopSecrectForm);
		std::cout << someVeryTopSecrectForm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form notValidForm("not valid", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return EXIT_SUCCESS;
}