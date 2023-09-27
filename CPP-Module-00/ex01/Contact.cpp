/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:02:13 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/25 10:47:22 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::_getInput(std::string str) const {
    std::string input = "";
    bool        valid = false;
    do
    {
        std::cout << str << std::flush;
        if (!std::getline(std::cin, input))
        {
            std::cout << std::endl << "Exiting ";
			return (input);
        }
        if (std::cin.good() && !input.empty())
            valid = true;
        else {
            std::cin.clear();
            std::cout << "Invalid input; please try again." << std::endl;
        }
    } while (!valid);
    return (input);
}

int    Contact::setInput(void) {
    std::cin.ignore();
    this->_firstName = this->_getInput("Please enter you first name: ");
    if (this->_firstName == "")
        return(EXIT_FAILURE);
    this->_lastName = this->_getInput("Please enter your last name: ");
    if (this->_lastName == "")
        return(EXIT_FAILURE);
    this->_nickName = this->_getInput("Please enter your nickname: ");
    if (this->_nickName == "")
        return(EXIT_FAILURE);
    this->_phoneNum = this->_getInput("Please enter your phone number: ");
    if (this->_phoneNum == "")
        return(EXIT_FAILURE);
    this->_darkSecret = this->_getInput("Please enter your darkest secret: ");
    if (this->_darkSecret == "")
        return(EXIT_FAILURE);
    std::cout << std::endl;
    return (EXIT_SUCCESS);
}

void Contact::setIndex(int i) { 
	this->_index = i;
}

std::string	Contact::get_fname(void) const{
	return (this->_firstName);
}
std::string	Contact::get_lname(void) const{
	return (this->_lastName);
}
std::string	Contact::get_nick(void) const{
	return (this->_nickName);
}
std::string	Contact::get_phone_num(void) const{
	return (this->_firstName);
}
std::string	Contact::get_secret(void) const{
	return (this->_darkSecret);
}
