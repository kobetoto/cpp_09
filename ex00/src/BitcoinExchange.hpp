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

#include <exception>
#include <cstring>
#include <cstdlib>
#include <cctype>  
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <utility>

enum Error_line{
  FORM_ERR,
  DATE_ERR,
  AMOUNT_ERR,
  NOT_POSITIVE,
  TOO_LARGE,
  BAD_INPUT,
  ALL_GOOD
};

void				error(const std::string& s);
void				store_data(std::map<std::string, double> &map);
bool 				check_date(std::string s);
std::string get_date(std::string s) ;
std::string get_amount(std::string s);
Error_line  check_amount(const std::string &s, double &amount_value);
Error_line  check_line(std::string &line);
bool	print_rslt(std::string &date,
								std::string &amount_str,
								const std::map<std::string, double> &map,
								double &rslt);

#endif	//BITCOINEXCHANGE_HPP
