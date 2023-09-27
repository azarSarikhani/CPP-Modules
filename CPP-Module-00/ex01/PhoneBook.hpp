/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:24:47 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/10 15:25:10 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
# include <iostream>
#include <iomanip>
#include <sstream>

class	PhoneBook 
{
	private: 
		Contact _contact[8];
		int		_index;
		std::string	_fix_width(std::string str, long unsigned max);
		
	public:
		PhoneBook(void);
		~PhoneBook(void);
		int		addContact(void);
		int		search(void) const;
		int		printContacts(void);

		
		

};
#endif