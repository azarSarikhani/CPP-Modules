/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarsarikhani <azarsarikhani@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:11:36 by azarsarikha       #+#    #+#             */
/*   Updated: 2023/09/17 10:54:25 by azarsarikha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base*   generate( void ) {
	static int i = std::rand();
    if ( i % 3 == 0 ){
		std::cout << "a new A" << std::endl;
		i++;
        return ( new A );
	}
    else if ( i % 3 == 1 ){
		std::cout << "a new B" << std::endl;
		i++;
        return ( new B );
	}
    else{
		std::cout << "a new C" << std::endl;
		i++;
        return ( new C );
	}
	i++;
	std::cout << "a new A" << std::endl;
    return ( new A );
}

void    identify( Base* p ) {
    if ( dynamic_cast< A* >( p ) )
        std::cout << "A" << std::endl;
    else if ( dynamic_cast< B* >( p ) )
        std::cout << "B" << std::endl;
    else if ( dynamic_cast< C* >( p ) )
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown" << std::endl;
}

//when using dynamic_cast with references, it throws a std::bad_cast exception
//if the cast fails, so you should use it within a try-catch
//block to handle exceptions if necessary

void    identify( Base& p ) {
    try {
        A& a = dynamic_cast< A& >( p );
        std::cout << "A" << std::endl;
        (void)a;
    } catch(const std::exception& e) {}
    try {
        B& b = dynamic_cast< B& >( p );
        std::cout << "B" << std::endl;
        (void)b;
    } catch( const std::exception& e ) {}
    try {
        C& c = dynamic_cast< C& >( p );
        std::cout << "C" << std::endl;
        (void)c;
    } catch( const std::exception& e ) {}
}

int main(void){
	std::cout << "generator returns p1 as ";
	Base *p1 = generate();
    std::cout << "p1* identified as ";
	identify(p1);
    std::cout << "p1& identified as ";
	identify(*p1);
	delete p1;
	
	std::cout << std::endl;
	std::cout << "generator returns p2 as ";
	Base *p2 = generate();
    std::cout << "p2* identified as ";
	identify(p2);
	std::cout << "p2& identified as ";
	identify(*p2);
	delete p2;
	
	std::cout << std::endl;
	std::cout << "generator returns p3 as ";
	Base *p3 = generate();
    std::cout << "p3* identified as ";
	identify(p3);
    std::cout << "p3& identified as ";
	identify(*p3);
	delete p3;
	
    return (0);
}


//equivalent type info obtained using std::type_info

// #include <iostream>

// class Base {
// public:
// 	Base() {};
// 	virtual ~Base() {};
//     virtual void foo() {}
// };

// class Derived : public Base {
// };

// int main() {
//     Base* ptr = new Derived;
//     const std::type_info& typeInfo = typeid(*ptr);

//     // compares type information using std::type_info objects
//     if (typeInfo == typeid(Derived)) {
//         std::cout << "Derived type" << std::endl;
//     } else {
//         std::cout << "Not a Derived type" << std::endl;
//     }

//     delete ptr;
//     return 0;
// }
