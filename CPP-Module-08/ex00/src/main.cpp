/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:15:10 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/25 14:59:55 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <set>
#include <list>
#include <deque>

int main(void)
{

	{
		std::cout << "-----Vector Test------" << std::endl;
		int int_array[6];
		for (int i = 0; i < 6; i++ ){
			int_array[i] = i;
		}
		//std::cout << "sizeof(int_array) " << sizeof(int_array) << " sizeof(*int_array) " << sizeof(*int_array) << std::endl;
		std::vector<int> int_vector(int_array, int_array + sizeof(int_array) / sizeof(*int_array)); //creates a vector initializing it to the elements of the int_array

		try {
			std::cout << *easyfind(int_vector, 7) << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		} 

		std::vector<int> vect;
		std::vector<int>::iterator  it;
		for (int i = 1; i <= 5; i++)
			vect.push_back(i * 2);
		for ( std::vector<int>::iterator  i = vect.begin(); i != vect.end(); i++)
			std::cout << *i << " ";
		std::cout << std::endl;
		try {
			it = easyfind(vect, 7);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

		
	{
		std::cout  << std::endl << "-----List Test------" << std::endl;

		std::list<int> int_list;
		int_list.push_back(3);
		int_list.push_back(5);
		int_list.push_back(6);

		try {
			std::cout << *easyfind(int_list, 2) << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		
		std::list<int>::iterator  it;
		try {
			it = easyfind(int_list, 3);
			std::cout << "3 is in the list";
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout  << std::endl << std::endl << "-----Deque Test------" << std::endl;
		std::deque<int> int_deque(9, 42);
		
		for (int i = 0; i < 9; i++)
			int_deque[i] = i - 10;
			
		try {
			std::cout << *easyfind(int_deque, 2) << std::endl;
		}
		catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}
		
		std::deque<int>::iterator it;
		
		try {
			it = easyfind(int_deque, -10);
			std::cout << "-10 is in the list";
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
