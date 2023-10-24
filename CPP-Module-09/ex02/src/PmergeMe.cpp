/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:57:38 by asarikha          #+#    #+#             */
/*   Updated: 2023/10/24 16:06:35 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe( const PmergeMe& src ){
	*this = src;
}

PmergeMe& PmergeMe::operator=( const PmergeMe& rhs ){
	(void) rhs;
	return *this;
}

PmergeMe::~PmergeMe(){
}

static unsigned int ft_stou(const std::string& str)
{
    unsigned int num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

static void printVec(std::vector<unsigned int>& vec)
{
	std::vector<unsigned int>::const_iterator itr;
	for (itr = vec.begin(); itr != vec.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

static std::vector<unsigned int> mergeInsertVec(std::vector<unsigned int>& vec) {
    // Base case: a vector with zero or one elements is already sorted
    if (vec.size() <= 1) {
        return vec;
    }

    // Divide the vector into two halves
    int mid = vec.size() / 2;
    std::vector<unsigned int> left(vec.begin(), vec.begin() + mid);
    std::vector<unsigned int> right(vec.begin() + mid, vec.end());

    // Recursively sort the left and right halves
    left = mergeInsertVec(left);
    right = mergeInsertVec(right);

    // Merge the sorted halves
    return mergeVecs(left, right);
}

void PmergeMe::sortVec(int argc, char **argv){
	
	std::vector<unsigned int> storage;

	for (int i = 1; i < argc; i += 1) {
		storage.push_back(ft_stou(argv[i]));
	}

	std::cout << "<vec>Before: ";
	printVec(storage);

	std::clock_t start = std::clock();
	std::cout << "start " << start << " / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND " << start / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND << std::endl;
	//storage = mergeInsertVec(storage);

	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

	std::cout << "<vec>After: ";
	printVec(storage);

	std::cout << "Time to process a range of " << argc - 1
		 << " elements " << "with std::vector<unsigned int> : " 
		 << time_taken << " microsecond" << std::endl;
}

static void printList(std::list<unsigned int>& lst)
{
	std::list<unsigned int>::const_iterator itr;
	for (itr = lst.begin(); itr != lst.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

void PmergeMe::sortList(int argc, char **argv){
	
	std::list<unsigned int> storage;

	for (int i = 1; i < argc; i += 1)
		storage.push_back(ft_stou(argv[i]));

    std::cout << "<list>Before: ";
	printList(storage);

	std::clock_t start = std::clock();

	//storage = mergeInsertList(storage);

	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

    std::cout << "<list>After: ";
	printList(storage);

	std::cout << "Time to process a range of " << argc - 1
		 << " elements " << "with std::list<unsigned int> : " 
		 << time_taken << " microsecond" << std::endl;
	
}
