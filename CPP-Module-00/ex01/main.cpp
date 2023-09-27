#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook PhBook;
	std::string	input = "";
	while (input.compare("EXIT")){
		std::cout << "Enter a command > " << std::flush;
		std::cin >> input;
		if(std::cin.eof())
		{
			std::cout << std::endl << "Exiting ";
			break ;
		}
		if (!input.compare("ADD"))
		{
			if (PhBook.addContact() == EXIT_FAILURE)
				break;
		}
		else if (!input.compare("SEARCH")){
			if(PhBook.printContacts() == EXIT_SUCCESS)
				if (PhBook.search() == EXIT_FAILURE)
					break ;
		}
		std::cout << std::flush;
	}
	return (0);
}