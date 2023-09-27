/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:03:53 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/21 16:20:01 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


// int main (void){
// 	int intArray[] = { 1, 2, 3, 4, 5 };
// 	std::cout << "printing members" << std::endl;
// 	iter(intArray, 5, &print);
// 	//std::cout << "printing incremented  members" << std::endl;
// 	//iter(intArray, 5, &printIncrementedMember); //

// 	std::cout << std::endl;
// 	double doubleArray[] = { 1.5, 2.3, 3.9, 4.4, 5.18 };
// 	std::cout << "printing members" << std::endl;
// 	iter(doubleArray, 5, &print);
// 	//std::cout << "printing incremented  members" << std::endl;
// 	//iter(doubleArray, 5, &printIncrementedMember); //

// 	std::cout << std::endl;
// 	char charArray[] = { 'a', 'c', 'q', 'e', 'w' };
// 	std::cout << "printing members" << std::endl;
// 	::iter(charArray, 5, &print);
// 	//std::cout << "printing incremented  members" << std::endl;
// 	//iter(charArray, 5, &printIncrementedMember); //

// 	std::cout << std::endl;
// 	std::string strinngArray[] = { "aka", "cd", "wtf", "brb", "byob" };
// 	std::cout << "printing members" << std::endl;
// 	iter(strinngArray, 5, &print);
// 	//std::cout << "printing incremented  members" << std::endl;
// 	//iter(strinngArray, 5, &printIncrementedMember); //

	
// 	return 0;
// }

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}