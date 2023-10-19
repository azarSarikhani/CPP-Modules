/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:14:25 by asarikha          #+#    #+#             */
/*   Updated: 2023/10/16 11:20:48 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <time.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//constructor and destructor
Account::Account ( int initial_deposit ){
	
}

Account::~Account(){
	
}

//getteres
int Account::getNbAccounts() {
    return (_nbAccounts);
}

int Account::getTotalAmount() {
    return (_totalAmount);
}

int Account::getNbDeposits() {
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals() {
    return (_totalNbWithdrawals);
}
