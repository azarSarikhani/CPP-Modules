/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:32:58 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/11 15:59:11 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	target_;
	
	PresidentialPardonForm();
	
public:
	PresidentialPardonForm( const std:: string target );
	PresidentialPardonForm( const PresidentialPardonForm& src );
	PresidentialPardonForm&  operator=( const PresidentialPardonForm& rhs );
	
	~PresidentialPardonForm();

	void execute( Bureaucrat const & executor ) const;
};

#endif