/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:32:58 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/11 15:58:48 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string	target_;
	
	ShrubberyCreationForm();
	
public:
	ShrubberyCreationForm( const std:: string target );
	ShrubberyCreationForm( const ShrubberyCreationForm& src );
	ShrubberyCreationForm&  operator=( const ShrubberyCreationForm& rhs );
	
	~ShrubberyCreationForm();

	void execute( Bureaucrat const & executor ) const;
};




#endif