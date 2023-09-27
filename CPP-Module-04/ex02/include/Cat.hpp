/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:31:33 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/04 10:57:30 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain	*brain_;
public:
	Cat();
	Cat( const Cat &copy );
	Cat &operator=( const Cat &rhs );
	~Cat();
	
	virtual void	makeSound( void ) const;
};

#endif