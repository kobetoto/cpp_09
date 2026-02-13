#include <iostream>
#include <string>
#include <map>
#include <stack>


// int main( void ){

//   std::map<std::string, double> m;
//   m["1"] = 0.42;
//   m["2"] = 1290.3928;
//   m["3"] = 42;

//   for( std::map<std::string, double>::const_iterator it = m.begin(); it != m.end(); ++it)
//   {
//     std::cout << it->first  << '=';
//     std::cout << it->second << '\n';

//   }

//   return (0);
// }


int main(){

  std::stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  std::cout << s.top() << '\n';
  return (0);
}
