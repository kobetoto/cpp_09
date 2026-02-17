/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:18:04 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/17 14:25:22 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
/*
int main ()
{
  std::string str ("Please, replace the vowels in this sentence by asterisks.");
  std::size_t found = str.find_first_of("aeiou");
  while (found!=std::string::npos)
  {
    str[found]='*';
    found=str.find_first_of("aeiou",found+1);
  }

  std::cout << str << '\n';

  return 0;
}
  */

unsigned int    check_operators(std::string &arg)
{
        std::string to_find = "+-/*";
        std::size_t found = 0;
        unsigned int operators = 0;

        found = arg.find_first_of(to_find);
        if (found == 0)
                error("Error:: no operators at the begging of the expression");
        if (found == std::string::npos)
                error("Error:: no operators in the expression");
}



void    check_expression(std::string &arg)
{
        if (arg.size() <= 2)
                error("Error:: not enough operators/operands");
        std::cout << check_operators(arg) << '\n';
}

int main(int ac, char **av)
{
        try
        {
                // check arg
                if (ac != 2 || *av[1] == '\0')
                {
                        error("Error:: Enter valid expression");
                        return (1);
                }
                std::string arg = av[1];
                check_expression(arg);
        }
        catch (std::runtime_error &e)
        {
                std::cout << "Error: " << e.what() << '\n';
                return (1);
        }
        return (0);
}
