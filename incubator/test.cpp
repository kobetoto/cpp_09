#include <iostream>   // std::cout
#include <string>     // std::string, std::stod


bool    is_operator(char c){
        
        std::string op = "+-/*";
        std::size_t found= op.find(c);
        if (found!=std::string::npos)
                return (true);
        else
                return (false);
}


int main (int ac, char **av)
{
  (void) ac;
  std::cout << is_operator(av[1][0]) << '\n';
  return 0;
}
