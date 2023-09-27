/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:38:24 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/04 11:27:15 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string idea_[100];
public:
	Brain( void );
	Brain( const Brain &copy );
	Brain &operator=( const Brain &rhs );
	~Brain( void );
};

#endif
