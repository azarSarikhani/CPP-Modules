/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarsarikhani <azarsarikhani@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 08:43:18 by azarsarikha       #+#    #+#             */
/*   Updated: 2023/09/16 10:11:50 by azarsarikha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

struct Data
{
    std::string firstName;
    int         age;
    std::string lastName;
};

class Serializer
{
private:
	Serializer();
	Serializer( Serializer &src );
	Serializer & operator=( Serializer &rhs );
	~Serializer();
	
public:
	static uintptr_t    serialize( Data *dataPtr );
	static Data*   deserialize( uintptr_t rawData );
};

#endif