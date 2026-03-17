/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:33:16 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/20 10:25:51 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


/**
 *UTILS 
 */
void error(const std::string &s){ throw(std::runtime_error(s)); }
std::string get_date(std::string s) { return (s.substr(0, 10)); }
std::string get_amount(std::string s) { return (s.substr(13, s.size())); }


/**
 * PARSING INPUT
 */
Error_line check_line(std::string &line)
{
  if (line.size() < 14)
    return FORM_ERR;

  if (line.compare(10, 3, " | ") != 0)
    return FORM_ERR;

  if (!check_date(line.substr(0, 10)))
    return DATE_ERR;

	double amount_value = 0.0;
	Error_line e = check_amount(line.substr(13), amount_value);
	if(e != ALL_GOOD)
    return e;

  return ALL_GOOD;
}

static bool is_leap_year(int y)
{
  if (y % 400 == 0) //biss
		return (true);
  if (y % 100 == 0)  //no biss
		return (false);
  return (y % 4 == 0);
}

bool check_date(std::string s)
{
  if (s.size() != 10)
    return false;
  if (s[4] != '-' || s[7] != '-')
    return false;

  for (int i = 0; i < 10; ++i)
  {
    if (i == 4 || i == 7)
			continue;
    if (!std::isdigit(static_cast<unsigned char>(s[i])))
      return false;
  }

	std::string const y = s.substr(0, 4);
	std::string const m = s.substr(5, 2);
	std::string const d = s.substr(8, 2);

	int year = std::atoi(y.c_str());
	int month = std::atoi(m.c_str());
	int day = std::atoi(d.c_str());

  if (month < 1 || month > 12)
    return (false);

  int max = 31;
  if (month == 4 || month == 6 || month == 9 || month == 11)
    max = 30;
  else if (month == 2)
	{
	if (is_leap_year(year))
	  max = 29;
	else
	  max = 28;
}
  if (day < 1 || day > max)
    return (false);

	return (true);
}

Error_line check_amount(const std::string &s, double &amount_value)
{
	const char *str = s.c_str();
	char *end = 0; 

	while (*str == ' ' || *str == '\t')
		str++;

	amount_value = std::strtod(str, &end);

	if (end == str)
    return AMOUNT_ERR;

  while (*end == ' ' || *end == '\t')
    end++;

	if (*end != '\0')
		return AMOUNT_ERR;

	if (amount_value < 0.0)
		return NOT_POSITIVE;

	if (amount_value > 1000.0)
		return TOO_LARGE;

  return ALL_GOOD;
}

void	store_data(std::map<std::string, double> &map){

	std::ifstream input_stream("data.csv");
	if (!input_stream)
		error("Can't open data.csv");

	std::string line;
	while (getline(input_stream, line))
	{
		if(line.empty())
			continue;

		if (line.size() >= 4 && line.substr(0, 4) == "date")
			continue;

		std::size_t pos = line.find(',');
		if (pos == std::string::npos)
			continue;

		std::string date  = line.substr(0, pos);
		std::string price = line.substr(pos + 1);

		double d = std::atof(price.c_str());
		map.insert(std::make_pair(date, d));
	}
}

std::map<std::string, double>::const_iterator closest_date(std::string &date, const std::map<std::string, double> &map){

	if (map.empty())
		error("Error: bad database.");

	std::map<std::string, double>::const_iterator it = map.lower_bound(date);
	if (it == map.end()){ 
		--it; 
		return it;
	}

	if (it->first == date) 
		return it;

	if (it == map.begin())
		return map.end();

	--it;
	return it;
}

bool	print_rslt(std::string &date,
								std::string &amount_str,
								const std::map<std::string, double> &map,
								double &rslt){

	double amount = 0.0;
  if (check_amount(amount_str, amount) != ALL_GOOD)
    return (false);

	std::map<std::string, double>::const_iterator it;
	it = closest_date(date, map);
	if (it == map.end())
    return (false);

	rslt = it->second * amount;

	return (true);
}
