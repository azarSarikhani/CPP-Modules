/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarsarikhani <azarsarikhani@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 08:47:45 by azarsarikha       #+#    #+#             */
/*   Updated: 2023/09/16 09:54:47 by azarsarikha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){
}

Serializer::~Serializer(){
}

Serializer::Serializer( Serializer &src ){
	*this = src;
}

Serializer & Serializer::operator=( Serializer &rhs ){
	( void ) rhs;
	return *this;
}


//creates an integer representation of the pointer aka unintptr_t from a pointer
uintptr_t    Serializer::serialize( Data *dataPtr ) {
    return ( reinterpret_cast< uintptr_t >( dataPtr ) );
}


//converts the integer representation of the pointer aka unintptr_t back to a pointer
Data*   Serializer::deserialize( uintptr_t data ) {
    return ( reinterpret_cast< Data* >( data ) );
}