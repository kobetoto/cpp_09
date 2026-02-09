/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobe <kobe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:33:16 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/09 15:42:16 by kobe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
  _ __   __ _ _ __ ___ _ _ __   __ _
 | '_ \ / _` | '__/ __| | '_ \ / _` |
 | |_) | (_| | |  \__ \ | | | | (_| |
 | .__/ \__,_|_|  |___/_|_| |_|\__, |
 | |                            __/ |
 |_|                           |___/
*/

/* MAIN */
void parsing_db2(const std::string &file_name, Data_b2 *db2)
{

	(void)db2;
	// checkfile
	const char *cstr = file_name.c_str();
	std::ifstream input_stream(cstr);
	if (!input_stream)
		error("Can't open input file");

	// extract all the text from the input file and store it to db2
	std::string line;
	while (getline(input_stream, line))
	{
		Error_line e = check_line(line);
		if (e == ALL_GOOD)
			std::cout << line << " => ..." << "ICI JE DOIS ADD MA SOLUTION" <<'\n'; 
		else if (e == FORM_ERR)
			std::cout << "Error:: invalid format" << '\n'; 
		else if (e == DATE_ERR)
			std::cout << "Error:: invalid date" << '\n'; 
		else if (e == AMOUNT_ERR)
			std::cout << "Error:: invalid amount" << '\n'; 
		store_line(line, db2->_map, e);
	}
/*
	for (std::multimap<std::string, double>::iterator it = db2->_map.begin(); it != db2->_map.end(); it++)
	{
		std::cout << it->first << " => ";
		std::cout << it->second;
		std::cout << '\n';
	}
*/
}

/* UTILS */

void error(const std::string &s)
{
	throw(std::runtime_error(s));
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

// get date / value
std::string get_date(std::string s) { return (s.substr(0, 10)); }
std::string get_value(std::string s) { return (s.substr(13, s.size())); }

/* parsing f()*/

void check_arg(const std::string &arg, const std::string &format, size_t ext_size)
{

	// check arguments size
	if (arg.size() < 3)
		error("Invalid input");
	if (format.size() < ext_size)
		error("Invalid format");
	// compare extention to the format
	std::string cmp = "";
	int i = 0;
	for (std::string::const_reverse_iterator rit = arg.rbegin(); i < 4; i++)
	{
		if (*rit != format[ext_size--])
			error("Invalid input");
		++rit;
	}
	return;
}

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

void store_line(std::string &line, std::multimap<std::string, double> &m, Error_line e)
{
	if (e == 3)
	{
		std::string date = get_date(line);
		std::string amount = get_value(line);
		m.insert(std::pair<std::string, double>(date, atof(amount.c_str())));
	}
	//  first.insert(std::pair<char,int>('b',15));
	else if (e == 0)
		m.insert(std::pair<std::string, double>("Error:: Format", 0));
	else if (e == 1)
		m.insert(std::pair<std::string, double>("Error:: Date", 0));
	else if (e == 2)
		m.insert(std::pair<std::string,double>("Error:: Amount", 0));
}
