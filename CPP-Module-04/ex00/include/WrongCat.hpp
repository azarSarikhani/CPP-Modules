/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:31:33 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/01 14:34:30 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:

public:
	WrongCat();
	WrongCat( const WrongCat &copy );
	WrongCat &operator=( const WrongCat &rhs );
	~WrongCat();
	
	void	makeSound( void ) const;
};

#endif