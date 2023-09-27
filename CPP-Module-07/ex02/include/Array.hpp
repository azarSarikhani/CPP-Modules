/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:16:55 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/25 10:58:47 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// *.tpp C++ template
// *.ipp C++ interface (abstract class) or simply and amgiguous C++ include file

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template < typename T >
class Array
{
private:
	T*	array_;
	unsigned int size_;
public:
	Array(): array_(NULL), size_(0) {
	std::cout << "Empty array constructed by default constructor" << std::endl;
	}
	
	Array( unsigned int n ): array_(new T[n]), size_( n ) {
	std::cout << "Array constructed with size: " << n << std::endl;
	}

	Array ( const Array & src ){
	array_ = NULL;
	*this = src;
	std::cout << "Array constructed by copy constructor" << std::endl;
	}
	
	Array& operator=( const Array& rhs ){
	if ( this != &rhs ){
		if (this->array_)
			delete [] array_;
		array_ = new T[rhs.size()];
		size_ = rhs.size();
		for ( unsigned int i( 0 ); i < size_; i++ )
			array_[i] = rhs.array_[i];	
	}
	return *this;
	}
	
	~Array(){
	if (this->array_)
		delete [] array_;
	std::cout << "Array destroyed" << std::endl;
	}
	
	unsigned int size( void ) const{ return(size_);}
	T& operator[]( std::size_t index ){
	if (index >= size_ )
		throw (std::invalid_argument("Error accesing array, bad index"));
	return (array_[index]);
	}
	
	const T& operator[]( std::size_t index ) const{
	if (index > size_ )
		throw (std::invalid_argument("Error accesing array, bad index"));
	return (array_[index]);
	}
};

#endif