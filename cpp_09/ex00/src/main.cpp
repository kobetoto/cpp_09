/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:43:04 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/16 13:46:48 by thodavid         ###   ########.fr       */
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
		
		// check file
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
			switch(Error_line e = check_line(line)) {
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

			// for (std::map<std::string, double>::iterator it = map.begin(); it != map.end();)
			// {
			// 	std::cout << it->first << ',' << it->second << '\n';
			// 	++it;
			// }
		}
	}
	catch (std::runtime_error& e){
		std::cout << "Error: " << e.what() << '\n';
		return (1);
	}
	return (0);
}
