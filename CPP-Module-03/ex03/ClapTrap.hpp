/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:43:25 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/30 12:46:13 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
private:
	ClapTrap();
	
protected:
	std::string name_;
	int hitPoint_;
	int energyPoint_;
	int attackDamage_;
	
public:
	ClapTrap( std::string name );
	ClapTrap( ClapTrap & copy );
	ClapTrap &operator=(const ClapTrap &rhs);
	~ClapTrap();
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif