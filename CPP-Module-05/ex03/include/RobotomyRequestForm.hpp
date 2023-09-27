/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:32:58 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/11 15:59:23 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string	target_;
	
	RobotomyRequestForm();
	
public:
	RobotomyRequestForm( const std:: string target );
	RobotomyRequestForm( const RobotomyRequestForm& src );
	RobotomyRequestForm&  operator=( const RobotomyRequestForm& rhs );
	
	~RobotomyRequestForm();

	void execute( Bureaucrat const & executor ) const;
};

#endif