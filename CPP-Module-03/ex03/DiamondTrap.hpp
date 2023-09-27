/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:19:34 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/30 11:10:49 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  DIAMONDTRAP_HPP
#define	DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string name_;
	DiamondTrap();
public:
	DiamondTrap(std::string name);
	DiamondTrap( DiamondTrap & copy );
	DiamondTrap &operator=(const DiamondTrap &rhs);
	~DiamondTrap();
	
	using ScavTrap::attack;
	void	whoAmI(void);
};

#endif
