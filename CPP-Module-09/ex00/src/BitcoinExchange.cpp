/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:50:50 by asarikha          #+#    #+#             */
/*   Updated: 2023/10/23 11:01:21 by asarikha         ###   ########.fr       */
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

float BitcoinExchange::ft_stof(const std::string& str)
{
    float num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

bool	BitcoinExchange::isDateInCorrectFormatAndValid(const std::string &date){
	if (date.empty())
		return false;

 	size_t first_hyphen = date.find('-');
	size_t second_hyphen = date.find('-', first_hyphen + 1); //finds charachter at the specified position
	if (first_hyphen != 4 || second_hyphen != 7 || date.length() != 10 )
		return false;
	
	int hyphons = 0;
	for ( std::string::const_iterator it = date.begin(); it != date.end(); it++){
		if (*it == '-'){
			hyphons++;
			continue;
		}
		if ( !std::isdigit(*it) || hyphons > 2)
			return false;
	}
	
	int year = ft_stof(date.substr(0, 4));
	int month = ft_stof(date.substr(5, 2));
	int day = ft_stof(date.substr(8, 2));
	
	
	if ( year < 0 || month < 1 || month > 12 || day > 31 || day < 1 )
		return false;
	if ( (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
			||  (day > 29 && month == 2 && year % 4 == 0) || (day > 28 && month == 2))
		return false;
	return true;
}


bool	BitcoinExchange::isRateInCorrectFormat(const std::string& rate){
	if ( rate.find( '.' ) == 0 || rate.find( '.' ) == rate.length() - 1 )
		return false;
	int points_found = 0;
	int j = 0;
	
	if (rate.at(j) == '-' || rate.at(j) == '+')
		j++;
	for ( int i (j); i < (int) rate.length(); i++){
		if (rate.at(i) == '.'){
			points_found++;
			i++;
		}
		if ( points_found > 1 || !std::isdigit(rate[i]) )
			return false;
	}
	return true;
}


void BitcoinExchange::parseData(void) {  //data[key] = value;
	std::ifstream	infile;
	std::string		line;

	infile.open(BitcoinExchange::data_file);
	if(infile.fail() == true)
		throw (std::runtime_error("could not open data file."));	
	// skip the first line
	std::getline(infile, line);
	while (getline(infile, line)) {
        std::stringstream    entry(line);
        std::string key;
        std::string value;
        if ((std::getline(entry, key, ',') && (entry >> value))) {
			if ( !isDateInCorrectFormatAndValid(key) )
				throw (std::runtime_error("Date is in incorrect order &/ is invalid"));
			if (!isRateInCorrectFormat(value))
				throw (std::runtime_error("Rate is in incorrect order &/ is invalid"));	
            this->data_[key] = value;
        } else {
            throw (std::runtime_error("Data is invalid"));
        }
    }
}

float BitcoinExchange::getRateFromDataBase(const std::string& date)
{
    if (this->data_.count(date) > 0){
        //return ft_stof(this->data_.at(date));
		return ft_stof(this->data_[date]);
	}
	if (this->data_.lower_bound(date) == this->data_.begin()){
		return -1;
	}
	
    return ft_stof((--this->data_.lower_bound(date))->second);
}

void	BitcoinExchange::parseInput(const std::string &inputFile){
	std::ifstream	infile;
	std::string		line;
	infile.open(inputFile);
	if(infile.fail() == true)
		throw (std::runtime_error("could not open input file."));
	// skip the first line
	std::getline(infile, line);
	while (getline(infile, line)) {
        size_t delim = line.find('|');
        if (delim == std::string::npos ||	line.length() < delim + 2){
			std::cerr << "Error: bad input" << std::endl;
			continue ;
		}
		std::string date = line.substr(0, delim - 1);
		if ( !isDateInCorrectFormatAndValid(date) ){
			std::cerr << "Error: bad date" << std::endl;
			continue ;
		}
		std::string rate = line.substr(delim + 2);
		if (!isRateInCorrectFormat(rate)){
			std::cerr << "Error: bad rate" << std::endl;
			continue ;
		}
		float num = ft_stof(rate);
		if (num > 1000){
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		if (num < 0){
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		float Rate = getRateFromDataBase(date);
		if (  Rate < 0 ){
			std::cerr << "Error: bad date" << std::endl;
			continue ;
		}
		std::cout << date << " => " << num << " = " << std::fixed << std::setprecision(2) << num * Rate << std::endl;		
    }
}
