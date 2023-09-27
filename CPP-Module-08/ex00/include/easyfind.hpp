/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:15:49 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/25 13:02:54 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int needle)
{
	typename T::iterator res = std::find(container.begin(), container.end(), needle); //find returns an _InputIterator
	if (res == container.end()){
		//std::cout << "res: " << *res << std::endl;
		throw (std::out_of_range("Couldn't find needle."));
	}
	//std::cout << "res: " << *res << std::endl;
	return res;
}

#endif