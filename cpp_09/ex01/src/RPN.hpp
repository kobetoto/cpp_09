/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:21:48 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/17 14:30:52 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP


#include <iostream>
#include <stack>
#include <string>         // std::string
#include <cstddef>        // std::size_t

void error(const std::string &s) { throw(std::runtime_error(s)); };


#endif  //RPN_HPP
