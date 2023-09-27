/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:03:21 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/25 14:05:20 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // Fixed const c( Fixed( 10.05f ) + Fixed( 2.6f ) );
    // Fixed const d( Fixed( 10.05f ) - Fixed( 2.6f ) );
    // Fixed  e( Fixed( 10.05f ) / Fixed( 2.6f ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    // std::cout << c << std::endl;
    // std::cout << d << std::endl;
    // std::cout << e << std::endl;
    // std::cout << e-- << std::endl;
    // std::cout << e << std::endl;
    // std::cout << --e << std::endl;
    // std::cout << e << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    //std::cout << Fixed::min( a, b ) << std::endl;
    
    
    return 0;
}