/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:52:45 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/10 15:23:03 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNum;
	std::string _darkSecret;
	int			_index;
	
	std::string _getInput(std::string str) const;
	
public:
	Contact();
	~Contact();
	std::string	get_fname(void) const;
	std::string	get_lname(void) const;
	std::string	get_nick(void) const;
	std::string	get_phone_num(void) const;
	std::string	get_secret(void) const;
	int			setInput(void);
	void		setIndex(int i);
};

#endif
