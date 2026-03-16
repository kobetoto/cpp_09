/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:43:04 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/20 09:35:09 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"

int	main( int ac, char **av ){

	try
	{
		// check arg
		if(ac != 2 || *av[1] == '\0'){
			error("Enter one valid file");
			return (1);
		}
		
		// check input file
		const char *cstr = av[1];
		std::ifstream input_stream(cstr);
		if (!input_stream)
			error("Can't open file");

		//store data.csv in map
		std::map<std::string, double> map;
		store_data(map);

		// check and print line
		std::string line;
		getline(input_stream, line);
		if(line != "date | value"){
			std::cerr << "Error:: invalid file format" << '\n';
			return (1);
		}

		while (getline(input_stream, line))
		{
			switch(check_line(line)) {
				case ALL_GOOD:
				{
					std::string date = get_date(line);
					std::string amount = get_amount(line);
					std::cout << date << " => " << amount
					<< " = "
					<< print_rslt(date, amount, map) <<'\n'; 
				}
					break;
				case FORM_ERR:
					std::cout << "Error:: invalid format" << '\n';
					break;
				case DATE_ERR:
					std::cout << "Error:: invalid date" << '\n';
					break;
				case AMOUNT_ERR:
					std::cout << "Error:: invalid amount" << '\n';
					break;
			}
		}
	}
	catch (std::runtime_error& e){
		std::cout << "Error: " << e.what() << '\n';
		return (1);
	}
	return (0);
}
