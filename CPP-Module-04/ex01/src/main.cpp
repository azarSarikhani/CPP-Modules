/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:29:02 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/04 13:01:16 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "test.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <new>

int main( void ){
	std::cout <<"Animal tests:" << std::endl;
	AnimalTest();
	std::cout << std::endl <<"Cat-Animal tests:" << std::endl;
	CatAnimalTest();
	std::cout << std::endl <<"Dog-Animal tests:" << std::endl;
	DogAnimalTest();
	std::cout << std::endl <<"Extra Animal tests:" << std::endl;
	ExtraAnimalTest();
	std::cout << std::endl <<"Wrong Animal tests:" << std::endl;
	WrongAnimalTest();
	std::cout << std::endl <<"Wrong Cat tests:" << std::endl;
	WrongCatTest();
	std::cout << std::endl <<"Extra Memory tests:" << std::endl;
	MemoryTest();
	return 0;
}