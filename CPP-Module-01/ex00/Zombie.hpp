/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:04:33 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/11 16:07:19 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

#define RED    "\e[0;31m"
#define GREEN  "\e[0;32m"
#define GRAY_BG   "\e[0;30;100m"
#define BLACK_BG   "\e[0;37m"
#define GREEN_BG  "\e[0;30;42m"
#define YELLOW_BG "\e[0;30;43m"
#define WHITE_BG  "\e[0;30;47m"
#define RESET  "\e[0m"

class Zombie
{
	public:
	Zombie(std::string name);
	~Zombie();
	void	announce(void);
	
	private:
	std::string	_name;
};
 
#endif