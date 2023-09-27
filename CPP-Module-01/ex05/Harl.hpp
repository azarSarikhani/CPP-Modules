/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarsarikhani <azarsarikhani@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:43:55 by azarsarikha       #+#    #+#             */
/*   Updated: 2023/08/16 15:26:48 by azarsarikha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class	Harl{
	public:
		Harl();
    	~Harl();
		void    complain( std::string level );
	private:
	    void    debug( void );
		void    info( void );
		void    warning( void );
		void    error( void );
};

typedef void (Harl::*t_functions) ( void );

#endif