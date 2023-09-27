/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 03:21:28 by ael-khni          #+#    #+#             */
/*   Updated: 2023/09/19 16:30:55 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template < typename T >
void swap( T& a, T& b ) {
    T tmp = a;
    a = b;
    b = tmp;
}

template < typename T >
T min( T& a, T& b ) {
    return ( a < b ? a : b );
}

template < typename T >
T max( T& a, T& b ) {
    return ( a > b ? a : b );
}