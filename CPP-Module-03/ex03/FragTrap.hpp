/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:08:25 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/30 12:46:35 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	FragTrap();
public:
	FragTrap(std::string name);
	FragTrap( FragTrap & copy );
	FragTrap &operator=(const FragTrap &rhs);
	~FragTrap();

	void	highFive( void );
};
#endif
