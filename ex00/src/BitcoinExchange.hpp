/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobe <kobe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:33:23 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/09 14:37:52 by kobe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <map>
#include <stdexcept>
#include <utility>
#include <string>
#include <fstream>
#include <stdlib.h>     /* atoi */
#include <cstring>

enum Error_line{
  FORM_ERR,
  DATE_ERR,
  AMOUNT_ERR,
  ALL_GOOD
};

void		error(const std::string& s);
void		check_arg(const std::string& arg, const std::string& format, size_t ext_size);
Error_line 	check_line(std::string &line);
void	store_line(std::string &line, std::multimap<std::string, double> &m, Error_line e );

class	Data_b2{
	public:
		Data_b2( ){};
		~Data_b2( ){};
		std::multimap<std::string, double> _map;
	
	private:

};

void	parsing_db2(const std::string& file_name, Data_b2 *db2);
#endif	//BITCOINEXCHANGE_HPP
