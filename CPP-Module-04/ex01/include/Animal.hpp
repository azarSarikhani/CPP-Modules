/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:54:53 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/01 13:59:41 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string type_;
	
public:
	Animal();
	Animal( std::string type );
	Animal( const Animal &copy );
	Animal &operator=( const Animal &rhs );
	
	virtual ~Animal( void );
	
	virtual void	makeSound( void ) const;
	std::string		getType( void ) const;
};

#endif

