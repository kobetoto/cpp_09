#include <iostream>   // std::cout
#include <string>     // std::string, std::stod


std::string new_date(const std::string &date){

	std::string newDate = date;

	return (newDate);
}



int main ()
{
  std::string date = "2011-01-04";
  std::cout << new_date(date) << '\n';
  return 0;
}
