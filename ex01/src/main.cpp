/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:18:04 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/20 13:45:39 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
        try
        {
                if (ac != 2 || *av[1] == '\0')
                        error("Enter a valid expression");
                Zuse_4(av[1]);
        }
        catch (std::runtime_error &)
        {
                std::cerr << "Error\n";
                return (1);
        }
        return (0);
}

/*
        real utilisation:
        -prog calc in emacs
        -tableur unix(dc)
        -langage forth
*/
