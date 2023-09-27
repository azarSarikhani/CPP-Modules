/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:56:04 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/01 13:59:56 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type_;
	
public:
	WrongAnimal();
	WrongAnimal( std::string type );
	WrongAnimal( const WrongAnimal &copy );
	WrongAnimal &operator=( const WrongAnimal &rhs );
	
	virtual ~WrongAnimal( void );
	
	void	makeSound( void ) const;
	std::string		getType( void ) const;
};

#endif