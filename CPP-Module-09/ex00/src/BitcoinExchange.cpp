/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:50:50 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/28 16:25:12 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const std::string BitcoinExchange::data_file = "data.csv";

BitcoinExchange::BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &src ){
	*this = src;
}

BitcoinExchange&  BitcoinExchange::operator=( const BitcoinExchange &rhs ){
	if (this != &rhs){
		this->data_ = rhs.data_;
	}
	return *this;
}

BitcoinExchange::~ BitcoinExchange(){
}

void BitcoinExchange::parseData(void) {
	std::ifstream	infile;
	std::string		line;

	infile.open(BitcoinExchange::data_file);
	if(infile.fail() == true)
		throw (std::runtime_error("could not open file.")); //descriptive message
	// while (getline(infile, line)){
		
	// }
	getline(infile, line);
	while (getline(infile, line)) {
        std::stringstream    entry(line);
        std::string key;
        double value;
        if ((getline(entry, key, ',') && (entry >> std::fixed >> std::setprecision(2) >> value))) {
			std::cout << key << " " << value <<std::endl;
            //validate and add to map
        } else {
            //invalid entry...
        }

    }
}


// void BitcoinExchange::parseInput(std::string inputFile) {
// }
