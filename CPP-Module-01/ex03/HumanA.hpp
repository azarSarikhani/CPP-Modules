/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:34:42 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/14 14:08:11 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
private:
	std::string	_name;
	Weapon		&_weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack(void);
	void	setWeapon(Weapon weapon);
};


