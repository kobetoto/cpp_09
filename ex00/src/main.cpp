/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:43:04 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/13 11:21:02 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"

int	main( int ac, char **av ){

	try
	{
		// checkfile (check arg)
		if(ac != 2 || *av[1] == '\0'){
			error("Enter one valid file");
			return (1);
		}
		const char *cstr = av[1];
		std::ifstream input_stream(cstr);
		if (!input_stream)
			error("Can't open file");

		//store data.csv in map
		std::map<std::string, double> map;
		store_data(map);

		// check and print line
		std::string line;
		while (getline(input_stream, line))
		{
			Error_line e = check_line(line);
			if (e == ALL_GOOD){
				std::cout << get_date(line) << " => "
				<< get_value(line)
				<< " = "
				<< print_rslt(line) <<'\n'; 
			}
			else if (e == FORM_ERR)
				std::cout << "Error:: invalid format" << '\n'; 
			else if (e == DATE_ERR)
				std::cout << "Error:: invalid date" << '\n'; 
			else if (e == AMOUNT_ERR)
				std::cout << "Error:: invalid amount" << '\n'; 
		}
	}
	catch (std::runtime_error& e){
		std::cout << "Error: " << e.what() << '\n';
		return (1);
	}
	/*
	   Bitcoin btc(42);
	   std::map<std::string, int> m;
	   m["2009-10-01"] = 0;

	//std::map<std::string, int>::const_iterator it;
	std::map<std::string, int>::const_iterator it = m.begin();
	std::cout << it->first << '\n';
	std::cout << it->second<< '\n';
	std::cout << btc.getSeed() <<'\n';
	*/
	return (0);
}
