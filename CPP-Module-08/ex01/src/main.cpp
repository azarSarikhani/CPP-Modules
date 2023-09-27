/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:02:07 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/26 17:04:35 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

int main(void){
	{
	Span sp(9);
	sp.addNumber(std::numeric_limits<int>::min());
	sp.addNumber(0);
	sp.addNumber(std::numeric_limits<int>::max());
	
	sp.printVector();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp(5);
		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(30);
		sp.addNumber(40);
		sp.addNumber(50);
		sp.printVector();
		try{
			sp.addNumber(0);
		}
		catch (std::exception & e){
			std::cerr << e.what() << std::endl;
		}
		try{
			sp.addNumber(6, 0);
		}
		catch (std::exception & e){
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Span sp(5);
		
		try{
			sp.addNumber(0);
		}
		catch (std::exception & e){
			std::cerr << e.what() << std::endl;
		}
		try{
			sp.addNumber(6, 20);
		}
		catch (std::exception & e){
			std::cerr << e.what() << std::endl;
		}
		sp.printVector();
	}
	{
		Span sp(15000);
		for (int i = 0; i < 15000; i++)
			sp.addNumber(670);
		try{
			sp.addNumber(0);
		}
		catch (std::exception & e){
			std::cerr << e.what() << std::endl;
		}
		try{
			sp.addNumber(6, 20);
		}
		catch (std::exception & e){
			std::cerr << e.what() << std::endl;
		}
		sp.printVector(96);
		sp.printVector(936);
		sp.printVector(196);
	}
	
	return 0;
}