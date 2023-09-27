/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:31:33 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/04 10:57:52 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*brain_;
public:
	Dog();
	Dog( const Dog &copy );
	Dog &operator=( const Dog &rhs );
	~Dog();
	
	virtual void	makeSound( void ) const;
};

#endif