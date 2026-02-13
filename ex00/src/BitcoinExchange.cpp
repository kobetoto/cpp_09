/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:33:16 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/13 11:20:38 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"



//
// Parsing input file
// Try to open it + check and print line
// Print err msg if something wrong
// Else print the rslt
//

/**
 *UTILS 
 */
void error(const std::string &s){ throw(std::runtime_error(s)); }
std::string get_date(std::string s) { return (s.substr(0, 10)); }
std::string get_value(std::string s) { return (s.substr(13, s.size())); }


/**
 * PARSING INPUT
 */
Error_line check_line(std::string &line)
{
	if (line[11] != '|' || line[10] != ' ' || line[12] != ' ')
		return (FORM_ERR);
	if (!check_date(line.substr(0, 10)))
		return (DATE_ERR);
	else if (!check_amount(line.substr(13, line.size())))
		return (AMOUNT_ERR);
	return (ALL_GOOD);
}

bool check_date(std::string s)
{
	std::string const y = s.substr(0, 4);
	std::string const m = s.substr(5, 2);
	std::string const d = s.substr(8, 2);

	unsigned int year = std::atoi(y.c_str());
	unsigned int mouth = std::atoi(m.c_str());
	unsigned int day = std::atoi(d.c_str());

	if (year < 2009 || year > 2022)
		return (false);
	if (mouth > 12 || mouth < 1)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	return (true);
}

bool check_amount(std::string s)
{
	double amount = atof(s.c_str());
	if (amount <= 0.00 || amount > 1000)
		return (false);
	else
		return (true);
}

//
// Print the result:
// 			BTC price * N.btc
// to do that:
//			-open history database (aka db)
//			-store the date / value in map container
//			-associate date line(input_file) <==> date (db)
//			-do the math and print it

void	store_data(std::map<std::string, double> &map){

		(void) map;
		std::ifstream input_stream("data.csv");
		if (!input_stream)
			error("Can't open data.csv");
		std::string line;
		while (getline(input_stream, line))
		{
			std::string date  = line.substr (0,10);
			std::size_t pos = line.find(",");
			std::string price = line.substr (pos + 1);
			map.insert(
				std::pair<std::string, double>(date, atof(price.c_str()))
			);
		}
}


std::string	print_rslt(std::string &line){

	(void) line;
	return ("hello from print_r");
}
