/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:00:19 by azarsarikha       #+#    #+#             */
/*   Updated: 2023/09/18 10:16:53 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

int main() {
	// // understanding uintptr and reinterpret_cast :
    // int* ptr = new int(42);

	// std::cout << ptr << std::endl;
	// std::cout << *ptr << std::endl;
	// std::cout << &ptr << std::endl << std::endl;
    // // Convert a pointer to uintptr_t
    // uintptr_t uintptr = reinterpret_cast<uintptr_t>(ptr);
	// std::cout << uintptr << std::endl;
	// std::cout << &uintptr << std::endl << std::endl;
    // // Do some integer arithmetic with uintptr_t
    // uintptr += 1;
	// std::cout << uintptr << std::endl;
	// std::cout << &uintptr << std::endl << std::endl;
    // // Convert uintptr_t back to a pointer
    // int* newPtr = reinterpret_cast<int*>(uintptr);

    // std::cout << newPtr << std::endl;
	// std::cout << *newPtr << std::endl;
	// std::cout << &newPtr << std::endl;
    // //delete newPtr;  // Don't forget to deallocate the memory



	// actual test for this exercise
	
	Data *data = new Data;
	
	data->age = 35;
	data->firstName = "Azar";
	data->lastName = "Sarikhani";
	std::cout << "The first day of creation there was only God herself" << std::endl;
	std::cout << "memory block that points to data: " << data << " , data's age: " << data->age << "  , data's first name: " << data->firstName << "    , data's last name: " << data->lastName << std::endl;
	
	uintptr_t unintptr = Serializer::serialize(data);
	std::cout << std::endl << "-----After serializition-----" << std::endl;
	std::cout << "integer representation of the pointer pointing to data: " << unintptr << std::endl;
	std::cout << "data's age: " << data->age << " , data's first name: " << data->firstName << " , data's last name: " << data->lastName << std::endl;
	Data *newBornData = Serializer::deserialize(unintptr);
	std::cout << std::endl << "-----After deserializition-----" << std::endl;
	std::cout << "A new data pointer is born." << std::endl;
	std::cout << "memory block that points to newBornData: " << newBornData << " , newBornData's age: " << newBornData->age << " , newBornData's first name: " << newBornData->firstName << " , newBornData's last name: " << newBornData->lastName << std::endl;
	
	delete data;
	
    return 0;
}
