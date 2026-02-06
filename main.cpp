/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:43:04 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/04 15:43:54 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"

int	main( int ac, char **av ){

	try{	
		if(ac != 2 || *av[1] == '\0'){
			error("Enter one valid input file");
			return (1);
		}
		check_arg(av[1], ".txt", 3);

		Data_b2 *db2 = new Data_b2();
		parsing_db2(av[1], db2);
		
	}
	catch (std::runtime_error e){
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
