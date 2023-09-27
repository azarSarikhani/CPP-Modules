/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:40:35 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/04 11:41:41 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "color.hpp"

Brain::Brain( void ){
	std::cout << TURQUOISE << "Brain's constructor creats an instance." <<std::endl;
}

Brain::Brain( const Brain &copy ){
	std::cout << TURQUOISE << " an instance is created by the Brain's copy constructor!" <<  RESET << std::endl;
	*this = copy;
}

Brain& Brain::operator=( const Brain& rhs){
	if (this != &rhs )
	{
		for (int i = 0; i < 100 ; i++){
			this->idea_[i] = rhs.idea_[i];
		}
	std::cout << TURQUOISE << " Brain's assignment operator overload called." <<  RESET << std::endl;
	}
	return *this;
}

Brain::~Brain( void ){
	std::cout << TURQUOISE << "Brain's destructor destroys an instance." <<  RESET << std::endl;
}
