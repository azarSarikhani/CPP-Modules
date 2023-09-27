/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:06:10 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/30 10:51:06 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp" 

class  ScavTrap : public ClapTrap
{
private:
	ScavTrap();
public:
	ScavTrap( std::string name );
	ScavTrap( ScavTrap & copy );
	ScavTrap &operator=(const ScavTrap &rhs);
	~ ScavTrap();
	
	void	attack(const std::string &target);
	void	gaurdGate();
};




#endif