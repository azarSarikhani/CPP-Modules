/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:16:38 by asarikha          #+#    #+#             */
/*   Updated: 2023/10/19 12:41:37 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <string>
# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <limits>

class  BitcoinExchange
{
private:
	static const std::string data_file;

	std::map<std::string, std::string> data_;
	
public:
	BitcoinExchange();
	BitcoinExchange( const BitcoinExchange &src );
	BitcoinExchange& operator=( const BitcoinExchange &rhs );
	~ BitcoinExchange();

	void	parseData(void);
	void	parseInput(const std::string &inputFile);
	bool	isDateInCorrectFormatAndValid(const std::string &date);
    bool	isRateInCorrectFormat(const std::string& rate);
	float	getRateFromDataBase(const std::string& date);
	float	ft_stof(const std::string& str);
};




#endif