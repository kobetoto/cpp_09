/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:22:02 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/18 14:35:40 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void error(const std::string &s) { throw(std::runtime_error(s)); };

bool is_operator(char c)
{

        std::string op = "+-/*";
        std::size_t found = op.find(c);
        if (found != std::string::npos)
                return (true);
        else
                return (false);
}

void do_the_math(std::stack<int> &r1, std::stack<int> &r2, char c)
{
        if (r1.empty() || r2.empty())
                error("malformed expression(0)");
        else
        {
                int num_r1 = r1.top();
                int num_r2 = r2.top();

                r1.pop(); r2.pop();
                switch (c)
                {
                case ('+'):
                        r1.push(num_r1 + num_r2);
                        break;
                case ('-'):
                        r1.push(num_r2 - num_r1);
                        break;
                case ('/'):
                        r1.push(num_r2 / num_r1);
                        break;
                case ('*'):
                        r1.push(num_r1 * num_r2);
                        break;
                }
        }
        return;
}

void    loading_second_number(int operand, std::stack<int> &r1, std::stack<int> &r2){

        //push top of r1 to r2
        if(!(r1.empty()))
        {
                r2.push(r1.top());
                r1.pop();
                r1.push(operand);
        }
        else
                error("loading second number");
}

void Zuse_4(const char *expr)
{
        std::stack<int> r1;
        std::stack<int> r2;

        unsigned int i = 0;
        while (expr[i])
        {
                if (expr[i] == ' ')
                {
                        i++;
                        continue; 
                }
                //operator => compute
                if (is_operator(expr[i]))
                        do_the_math(r1, r2, expr[i]);
                //operand => store
                else
                {
                        //conversion
                        int operand = expr[i] - '0';
                        if (operand > 9 || operand < 0)
                                error("malformed expression(1)");
                        
                        //store operand
                        if (r1.empty())
                                r1.push(operand); //R1 = operand | R2 = empty
                        else
                                loading_second_number(operand, r1, r2);
                }
                i++;
        }
        if (!r2.empty() || r1.empty()) 
                error("malformed expression(3)");
        std::cout << r1.top() << '\n';
}
