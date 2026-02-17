/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:18:04 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/17 15:10:33 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool    is_operator(char c){
        
        std::string op = "+-/*";
        std::size_t found= op.find(c);
        if (found!=std::string::npos)
                return (true);
        else
                return (false);
}

void    do_the_math(std::stack<int> &r1, std::stack<int> &r2, char c){
        if(r1.empty() || r2.empty())
                error("Err:: malformed expression");
        else{
                switch(c) {
                          case ('+'):
                                std::cout << "+\n";
                                break;
                          case ('-'):
                                std::cout << "+\n";
                                break;
                          case ('/'):
                                std::cout << "/\n";
                                break;
                          case ('*'):
                                std::cout << "*\n";
                                break;
                          default:
                            // code block
                        }
        }
        return;
}


bool    is_operand(char c){
        return (true);
}

void    Zuse_4(char *expr){

        std::stack<int> r1;
        std::stack<int> r2;

        unsigned int i = 0;
        while(expr[i]){
                
                if (is_operator(expr[i]))
                        do_the_math(r1, r2, expr[i]);
                if(is_operand(expr[i]) && r1.empty()){
                        r1.push(expr[i]);
                }
                else
                {
                        r2.push(r1.top());
                        r1.pop();
                        r1.push(expr[i]);
                }
                i++;
        }
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
                Zuse_4(av[1]);
        }
        catch (std::runtime_error &e)
        {
                std::cout << "Error: " << e.what() << '\n';
                return (1);
        }
        return (0);
}
