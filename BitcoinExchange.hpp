/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:33:23 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/06 12:00:35 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <map>
#include <stdexcept>
#include <string>
#include <fstream>

void	error(const std::string& s);
void	check_arg(const std::string& arg, const std::string& format, size_t ext_size);

class	Data_b2{
	public:
		Data_b2( ){};
		~Data_b2( ){};
	
	private:
		std::map<std::string, int> _map;

};

void	parsing_db2(const std::string& file_name, Data_b2 *db2);
#endif	//BITCOINEXCHANGE_HPP
