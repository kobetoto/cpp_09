/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:33:23 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/13 11:17:44 by thodavid         ###   ########.fr       */
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
bool 		check_amount(std::string s);
bool 		check_date(std::string s);
Error_line 	check_line(std::string &line);
std::string	print_rslt(std::string &line);

void	store_data(std::map<std::string, double> &map);

std::string get_date(std::string s) ;
std::string get_value(std::string s);

#endif	//BITCOINEXCHANGE_HPP
