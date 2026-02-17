#include <iostream>
#include <string>
#include <stdlib.h>     /* atoi */
#include <cstring>
#include <string>


bool check_date(std::string s){
  std::string const y = s.substr(0,4);
  std::string const m = s.substr(5,2);
  std::string const d = s.substr(8,2);

  unsigned int year = std::atoi(y.c_str());
  unsigned int mouth = std::atoi(m.c_str());
  unsigned int day =  std::atoi(d.c_str());
  
  if (year < 2009 || year > 2022)
      return (false);
  if (mouth > 12 || mouth < 1)
    return (false);
  if (day < 1 || day > 31)
    return (false);
  return (true);
}

bool check_float(std::string &s){
  float amount = std::stof(s.c_str());
  if (amount < 0.1 || amount > 1000.0)
    return (false);
  else 
    return (true);
}

bool check_int(std::string s){
  int amount = std::stoi(s.c_str());
  if (amount < 1 || amount > 1000)
    return (false);
  else 
    return (true);
}

bool check_amount(std::string s){
  bool is_float = false;
  if (s.find('.') == 1)
    is_float = true;

  if(is_float)
    return (check_float(s));
  else 
    return (check_int(s));
}

Error_line check_line(std::string &line){
  if (line[11] != '|' || line[10] != ' ' || line[12] != ' ')
      return (FORM_ERR);
  if (!check_date(line.substr(0,10)))
      return (DATE_ERR);
  else if (!check_amount(line.substr(13,line.size())))
      return (AMOUNT_ERR);
   return (ALL_GOOD);
}

int main(void){

  std::string line_toLarge = "2012-01-11 | 2147483648";
  /*
  std::string line_toLarge = "2012-01-11 | 2147483648";
  std::string line_negInt = "2012-01-11 | -1";
  std::string line_badInput = "2012-42-42    ";
  std::string line_dateErr = "2012-00-11 | 2147483648";
  std::string line_ok = "2012-06-13 | 42";
  */

  std::cout << check_line(line_toLarge)  << '\n';


  return (0);
}

