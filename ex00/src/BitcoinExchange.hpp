/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:33:23 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/16 13:45:51 by thodavid         ###   ########.fr       */
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
#include <stdlib.h> /* atoi */
#include <cstring>

enum Error_line{
  FORM_ERR,
  DATE_ERR,
  AMOUNT_ERR,
  ALL_GOOD
};

void				error(const std::string& s);
void				store_data(std::map<std::string, double> &map);

bool 				check_amount(std::string s);
bool 				check_date(std::string s);

float			print_rslt(std::string &date,
						std::string &amount,
						const std::map<std::string, double> &map);

std::string get_date(std::string s) ;
std::string get_amount(std::string s);

Error_line 	check_line(std::string &line);

#endif	//BITCOINEXCHANGE_HPP
