/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:55:30 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/13 11:05:19 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string line  = "2021-04-27,54056.64";
	std::string date  = line.substr (0,10);
	std::size_t pos = line.find(",");
	std::string price = line.substr (pos + 1);

	std::cout << '=' << date <<"=\n";
	std::cout << '=' << price <<"=\n";
	return (0);
}
