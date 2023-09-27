/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:34:51 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/14 11:33:51 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

# define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string	_clubType;
public:
	Weapon(std::string weaponType);
	~Weapon();
	const	std::string& getType(void) const;
	void		setType(std::string);
};

#endif