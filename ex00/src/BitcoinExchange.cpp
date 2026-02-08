/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:33:16 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/06 07:33:17 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void error(const std::string& s)
{
	throw (std::runtime_error(s));
}

void	check_arg(const std::string &arg, const std::string &format, size_t ext_size){

	//check arguments size
	if(arg.size() < 3)
		error("Invalid input");
	if(format.size() < ext_size)
		error("Invalid format");

	//compare extention to the format
	std::string cmp = "";
	int i = 0;
	for(std::string::const_reverse_iterator rit = arg.rbegin(); i < 4; i++){
		if (*rit != format[ext_size--])
			error("Invalid input");
		++rit;
	}
	return;
}

void	parsing_db2(const std::string& file_name, Data_b2 *db2){
	
	(void) db2;
	//checkfile
	const char *cstr = file_name.c_str();
	std::ifstream input_stream(cstr);
	if (!input_stream) 
		error("Can't open input file");

	//
	std::map<std::string, int> m;
	/*
	m["have to fil db2->_map with key value frome input file"]=42;
	std::map<std::string, int>::const_iterator it = m.begin();
	std::cout << it->first << '\n';
	std::cout << it->second<< '\n';
	*/

	std::string line;

	// extract all the text from the input file
	while (getline(input_stream, line))
		std::cout << "To store: " << line << '\n';
}
