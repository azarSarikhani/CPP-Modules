/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:55:11 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/21 16:22:32 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T >
void iter( T *array, size_t size, void (*function)(T & ) ){
	for ( size_t i = 0; i < size; i++ ){
		function(array[i]);
	}
}

template <typename T >
void iter( T *array, size_t size, void (*function)(T const & ) ){
	for ( size_t i = 0; i < size; i++ ){
		function(array[i]);
	}
}

// template <typename T >
// void print( T const &member){
// 	std::cout << member << std::endl;
// }


// template <typename T >
// void printIncrementedMember( T &member){
// 	std::cout << member + 1 << std::endl;
// }

#endif