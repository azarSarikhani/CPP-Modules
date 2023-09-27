/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:13:16 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/25 10:47:13 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_index = 0;
	std::cout << std::endl;
	std::cout << "📞  Welcome to Your Awesome PhoneBook " << std::endl;
	std::cout << std::endl;
	std::cout << "--------------USAGE---------------" << std::endl;
	std::cout << "ADD\t: To add a contact." << std::endl;
	std::cout << "SEARCH\t: To search for a contact." << std::endl;
	std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
}

PhoneBook::~PhoneBook()
{
}

int	PhoneBook::addContact(void)
{
	std::string overwrite;
	
	if (this->_index > 7)
	{
		do{
			std::cout << "Warning: overwriting info about " << this->_contact[this->_index % 8].get_fname() << std::endl;
			std::cout << "Do you want to proceed? y/n ";
			std::cin >> overwrite;
			if (overwrite.compare("n") == 0 || overwrite.compare("N") == 0)
				return (EXIT_SUCCESS);
			else if(overwrite.compare("y") == 0 || overwrite.compare("Y") == 0)
				break ;
		}while(true);
	}
	if (this->_contact[this->_index % 8].setInput() == EXIT_FAILURE)
		return (EXIT_FAILURE);
    this->_contact[this->_index % 8].setIndex(this->_index % 8);
    this->_index++;
	return (EXIT_SUCCESS);
}
std::string	PhoneBook::_fix_width(std::string str, long unsigned max)
{
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	else if (str.size() < max)
	{
		while(str.size() <= max)
		{
			str[max] = ' ';
			max--;
		}
	}
	return (str);
}


int	PhoneBook::printContacts(void)
{
	if (this->_index == 0)
	{
		std::cout << std::endl << "Phonebook is empty!" << std::endl;
		return (EXIT_FAILURE);
	}
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	for(size_t i = 0; i < 8; i++){
		if (this->_contact[i].get_fname().empty() || this->_contact[i].get_lname().empty()
			|| this->_contact[i].get_nick().empty())
			return (EXIT_SUCCESS);
		std::cout << "|" << std::setw(10) << i + 1 << std::flush;
		std::cout << "|" << std::setw(10) << _fix_width(this->_contact[i].get_fname(), 10) << std::flush;
		std::cout << "|" << std::setw(10) << _fix_width(this->_contact[i].get_lname(), 10) << std::flush;
		std::cout << "|" << std::setw(10) << _fix_width(this->_contact[i].get_nick(), 10) << std::flush;
		std::cout << "|" << std::endl;
	}
	std::cout << " ------------------------------------------- " << std::endl;
	return (EXIT_SUCCESS);
}

int	PhoneBook::search(void) const
{
	int     i = -1;
    do
    {
    	std::cout << "Please enter the contact index: " << std::flush;
    	std::cin >> i;
		if(std::cin.eof())
		{
			std::cout << std::endl << "Exiting ";
			return (EXIT_FAILURE);
		}
        if (std::cin.good() && (i >= 0 && i <= 8)) {
            break ;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid index; please re-enter." << std::endl;
        }
    } while (true);
	i--;
    if (this->_contact[i].get_fname().empty() || this->_contact[i].get_lname().empty()
			|| this->_contact[i].get_nick().empty())
			{
				std::cout << "index does not exist" << std::endl;
				return (EXIT_SUCCESS);
			}
    std::cout << std::endl;
    std::cout << "---->> CONTACT #" << i + 1 << " <<----" << std::endl;
    std::cout << "First Name:\t" << this->_contact[i].get_fname() << std::endl;
    std::cout << "Last Name:\t" << this->_contact[i].get_lname() << std::endl;
    std::cout << "Nickname:\t" << this->_contact[i].get_nick() << std::endl;
	std::cout << "Darkest secret:\t" << this->_contact[i].get_secret() << std::endl;
	std::cout << "Phone number:\t" << this->_contact[i].get_phone_num() << std::endl;
    std::cout << std::endl;
	return (EXIT_SUCCESS);
}