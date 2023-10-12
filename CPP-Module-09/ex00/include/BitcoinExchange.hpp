/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:16:38 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/28 15:58:29 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <limits>

class  BitcoinExchange
{
private:
	static const std::string data_file;

	std::map<std::string, float> data_;
	
public:
	BitcoinExchange();
	BitcoinExchange( const BitcoinExchange &src );
	BitcoinExchange& operator=( const BitcoinExchange &rhs );
	~ BitcoinExchange();

	void	parseData(void);
	//void	parseInput(std::string inputFile);
};




#endif