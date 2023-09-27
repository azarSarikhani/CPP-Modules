/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarsarikhani <azarsarikhani@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:43:51 by azarsarikha       #+#    #+#             */
/*   Updated: 2023/08/16 16:20:17 by azarsarikha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void    Harl::debug( void ) {
    std::cout << "\"DEBUG\" love having extra bacon for my";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << " I really do!" << std::endl;
}

void    Harl::info( void ) {
    std::cout << "\"INFO\" I cannot believe adding extra bacon costs more money.";
	std::cout << "You didn't put enough bacon in my burger! If you did,";
	std::cout << "I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning( void ) {
    std::cout << "\"WARNING\" I think I deserve to have some extra bacon for free.";
	std::cout << "I've been coming foryears whereas you started working";
	std::cout << "here since last month." << std::endl;
}

void    Harl::error( void ) {
    std::cout << "\"ERROR\" This is unacceptable! I want to speak";
	std::cout << "to the manager now." << std::endl;
}

void    Harl::complain( std:: string level ) {
    t_functions  funct[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4 && levels[i].compare(level))
        i++ ;
    if (i < 4)
        (this->*funct[i])();
}