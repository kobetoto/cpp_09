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

#include "BitcoinExchange.hpp"

int	main( int ac, char **av ){

	try
	{
		// check arg
		if(ac != 2 || *av[1] == '\0'){
			error("could not open file.");
		}

		// check input file
		std::ifstream input_stream(av[1]);
		if (!input_stream)
			error("could not open file.");

		//store data.csv in map
		std::map<std::string, double> map;
		store_data(map);

		// check and print line
		std::string line;
		if (!std::getline(input_stream, line))
			error("could not open file.");
		if (line != "date | value")
		{
			std::cout << "Error: bad input => " << line << "\n";
			return (1);
		}

		while (std::getline(input_stream, line))
		{
			if (line.empty())
				continue;
			switch(check_line(line)) {
				case ALL_GOOD:
					{
				    std::string date = get_date(line);
				    std::string amount = get_amount(line);

				    double rslt = 0.0;
				    if (!print_rslt(date, amount, map, rslt))
				    {
				      std::cout << "Error: bad input => " << line << "\n";
				      break;
				    }

				    std::cout << date << " => " << amount << " = " << rslt << "\n";
				    break;
					}
				case NOT_POSITIVE:
					{
						std::cout << "Error: not a positive number.\n";
						break;
					}
				case TOO_LARGE:
					{
						std::cout << "Error: too large a number.\n";
						break;
					}
				default:
					{
						std::cout << "Error: bad input => " << line << "\n";
						break;
					}
			}
		}
	}
	catch (std::runtime_error& e){
		std::cout << "Error: " << e.what() << '\n';
		return (1);
	}
	return (0);
}
