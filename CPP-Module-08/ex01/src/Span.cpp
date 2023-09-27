/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:28:54 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/26 16:57:52 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : maxElements_(0){
	std::cout << "Span constructed with: " << maxElements_ << " as max elements" << std::endl;
}

Span::Span( unsigned int N ): maxElements_(N){
	std::cout << "Span constructed with: " << maxElements_ << " as max elements" << std::endl;
}

Span::Span( const Span &src ){
	*this = src;
}

Span& Span::operator=( const Span &rhs ){
	if (this != &rhs){
		this->maxElements_ = rhs.maxElements_;
		this->vector_ = rhs.vector_;
	}
	std::cout << "Span constructed with: " << maxElements_ << " as max elements" << std::endl;
	return *this;
}

Span::~Span(){
	std::cout << "Span destructed" << std::endl;
}

void	Span::addNumber(int x){
	if (this->vector_.size() >= this->maxElements_)
		throw (std::out_of_range("Span is already full, can't add more elements"));
	else
		this->vector_.push_back(x);
}

void	Span::addNumber( unsigned int size, int x ){
	if (this->vector_.size() >= this->maxElements_)
		throw (std::out_of_range("Span is already full, can't add more elements"));
	if ( size + this->vector_.size() >= this->maxElements_ )
		size =  this->maxElements_ - this->vector_.size();
	vector_.insert(vector_.end(), size, x);
}

long int 	Span::shortestSpan(void){
	if (this->vector_.size() <= 1)
		throw (std::length_error("can't calculate shortest span with 1 or less elements on span"));

	std::vector<int> sortedVector = this->vector_;

	std::sort(sortedVector.begin(), sortedVector.end());
	
	long int min_diff = longestSpan();
	for ( std::vector<int>::iterator it1 = sortedVector.begin(); it1 != sortedVector.end(); it1++ ){
		for ( std::vector<int>::iterator it2 = sortedVector.begin(); it2 != sortedVector.end(); it2++ ){
			if (it1 == it2)
				continue;
			if ( std::abs(static_cast<long int>(*it2) - static_cast<long int>(*it1)) <  min_diff )
				min_diff = std::abs(static_cast<long int>(*it2) - static_cast<long int>(*it1));
		}
	}
	return min_diff;
}

long int 	Span::longestSpan(void){
	if (this->vector_.size() <= 1)
		throw (std::length_error("can't calculate shortest span with 1 or less elements on span"));
	return ( static_cast<long int>(*std::max_element(vector_.begin(), vector_.end())) - (*std::min_element(vector_.begin(), vector_.end())));
 
}

void Span::printVector(void){
	for ( std::vector<int>::iterator it = vector_.begin(); it!= vector_.end(); it++ )
		std::cout << *it << "  ,  ";
	std::cout<< std::endl;
}

void Span::printVector(int index){
		std::cout << vector_.at(index) << std::endl;
}
