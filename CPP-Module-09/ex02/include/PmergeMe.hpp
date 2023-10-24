/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:57:40 by asarikha          #+#    #+#             */
/*   Updated: 2023/10/24 15:13:49 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

# define MICROSECOND 100000

class PmergeMe
{
private:
	
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe& src);
	PmergeMe &operator=(const PmergeMe& rhs);
	~PmergeMe(void);

	void sortVec(int argc, char **argv);
    void sortList(int argc, char **argv);
};




#endif