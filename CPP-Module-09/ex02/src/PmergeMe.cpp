/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:57:38 by asarikha          #+#    #+#             */
/*   Updated: 2023/11/02 16:04:34 by asarikha         ###   ########.fr       */
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

static void mergeVec(std::vector<unsigned int>& vec, int start , int mid, int end)
{
    int n1 = mid - start + 1; 
	int n2 = end - mid; 

	std::vector<int> Left(n1); // two arrays for sorting
	std::vector<int> Right(n2);

	// copy from start to mid into left
	for (int i = 0; i < n1; i++)
	{
		Left[i] = vec[start + i];
	}

    // copy from mid to end into right
	for (int i = 0; i < n2; i++)
	{
		Right[i] = vec[mid + 1 + i];
	}

	int RIDX = 0;
	int LIDX = 0;

	for (int i = start; i <= end; i++) // sorting+merging the split arrays into vec, starts each round at 0
	{
		if (RIDX == n2)
		{
			vec[i] = Left[LIDX];
			LIDX++;
		}
		else if (LIDX == n1)
		{
			vec[i] = Right[RIDX];
			RIDX++;
		}
		else if (Right[RIDX] > Left[LIDX])
		{
			vec[i] = Left[LIDX];
			LIDX++;
		}
		else
		{
			vec[i] = Right[RIDX];
			RIDX++;
		}
	}
}

static void insertionSortVec(std::vector<unsigned int>& vec, int start, int end ) {
    
    for (int i = start; i < end; i++)
	{
        unsigned int tempVal = vec[i + 1];
        int j = i + 1;
        while (j > start && vec[j - 1] > tempVal) // if curr pos is bigger than next pos
		{
            vec[j] = vec[j - 1];
            j--; // count down till 0
        }
        vec[j] = tempVal;
	}
}

static void mergeInsertVec(std::vector<unsigned int>& vec, int start, int end ) {
		
	if (end - start > 2)
	{
		int mid = (start + end) / 2;
		mergeInsertVec(vec, start, mid);
		mergeInsertVec(vec, mid + 1, end); 
		mergeVec(vec, start, mid, end); // merge sort
	}
	else
	{
		insertionSortVec(vec, start, end);
	}
}

void PmergeMe::sortVec(int argc, char **argv){
	
	std::vector<unsigned int> storage;

	std::clock_t start = std::clock();
	for (int i = 1; i < argc; i += 1) {
		storage.push_back(ft_stou(argv[i]));
	}

	std::cout << "<vec>Before: ";
	printVec(storage);

	mergeInsertVec(storage, 0, storage.size() - 1);
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

static std::list<unsigned int>::iterator advance(std::list<unsigned int>::iterator it, int n) {
    if (n > 0) {
        for (int i = 0; i < n; ++i) {
            ++it;
        }
    } else if (n < 0) {
        for (int i = 0; i > n; --i) {
            --it;
        }
    }
	return it;
}

static void mergeList(std::list<unsigned int>& list, int start , int mid, int end){

	int n1 = mid - start + 1; 
	int n2 = end - mid;

	std::list<int> Left; // two arrays for sorting
	std::list<int> Right;

	// fill the halfes with the numbers (0 till half and half till end)
	for (int i = 0; i < n1; i++)
	{ 
		Left.push_back(*advance(list.begin(), start + i)); // std:next : gives next iterator, at pos n after the start pos
	}

	for (int i = 0; i < n2; i++)
	{
		Right.push_back(*advance(list.begin(), mid + 1 + i));
	}

	int RIDX = 0;
	int LIDX = 0;

	for (int i = start; i <= end; i++) // sorting+merging the split arrays into int_vec, starts each round at 0
	{
		if (RIDX == n2)
		{
			*advance(list.begin(), i) = Left.front(); // front returns reference to first element in the list
			Left.pop_front();
			LIDX++;
		}
		else if (LIDX == n1)
		{
			*advance(list.begin(), i) = Right.front();
			Right.pop_front();
			RIDX++;
		}
		else if (Right.front() > Left.front())
		{
			*advance(list.begin(), i) = Left.front(); // insert front element from left array into list at post after i;
			Left.pop_front(); // then take it out
			LIDX++;
		}
		else
		{
			*advance(list.begin(), i) = Right.front();
			Right.pop_front();
			RIDX++;
		}
	}
}

static void insertionSortList(std::list<unsigned int>& list, int start, int end ) {
	
	for (int i = start; i < end; i++)
	{
        unsigned int tempVal = *advance(list.begin(), i + 1);
        int j = i + 1;
        while (j > start && *advance(list.begin(), j - 1) > tempVal) // if curr pos is bigger than next pos
		{
            *advance(list.begin(), j) = *advance(list.begin(), j - 1);
            j--; // count down till 0
        }
        *advance(list.begin(), j) = tempVal; //insert element at correct position
	}
}

static void mergeInsertList(std::list<unsigned int>& list, int start, int end ) {
	if (end - start > 2) // divide into paired groups until num of groups wanted reached
	{
		int mid = ( start + end ) / 2;
		mergeInsertList(list, start, mid);
		mergeInsertList(list, mid + 1, end); 
		mergeList(list, start, mid, end);
	}
	else
	{
		insertionSortList(list, start, end);
	}
}

void PmergeMe::sortList(int argc, char **argv){
	
	std::list<unsigned int> storage;

	std::clock_t start = std::clock();
	for (int i = 1; i < argc; i += 1)
		storage.push_back(ft_stou(argv[i]));

    std::cout << "<list>Before: ";
	printList(storage);


	mergeInsertList(storage, 0, storage.size() - 1);
	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

    std::cout << "<list>After: ";
	printList(storage);

	std::cout << "Time to process a range of " << argc - 1
		 << " elements " << "with std::list<unsigned int> : " 
		 << time_taken << " microsecond" << std::endl;
	
}