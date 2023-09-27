/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 03:20:11 by ael-khni          #+#    #+#             */
/*   Updated: 2023/09/21 16:18:52 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"


int main( void )
{
    int a = 2;
    int b = 3;

    swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;

    std::cout << "min( c, d ) = " << min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << max( c, d ) << std::endl;

    return 0;
}

// class mindBlowingClass{

// public:
//     mindBlowingClass(void) : _n(0){}
//     mindBlowingClass(int n) : _n(n) {}

//     mindBlowingClass &operator= (mindBlowingClass &a) {_n = a._n; return *this;}

//     bool operator>(mindBlowingClass &a) {return this->_n > a.get_n();}
//     bool operator<(mindBlowingClass &a) {return this->_n < a.get_n();}

//     int get_n()const {return _n;}

// private:
//     int _n;
// };

// std::ostream &operator << (std::ostream &o, const mindBlowingClass& a){o << a.get_n(); return o;}

// int main()
// {
//     mindBlowingClass a(22), b(14);

//     swap (a,b);
//     std::cout << "a: " << a << " b: " << b << std::endl;
//     std::cout << "max: " << max<mindBlowingClass>(a,b) << std::endl;
//     std::cout << "min: " << min(a,b) << std::endl;
//     return 0;
// }