#include <iostream>
#include <array>
#include <string>

using namespace std;

template<int amount>
auto parse(string line){
  array<string,amount> out;
  int pos = 0;
  while(true){
    if(auto space = line.find(' ');space!= string::npos){
      out[pos++] = line.substr(0,space-1);
      line = line.substr(space+1,string::npos);
      continue;
    }
    break;
  }
  return out;
}

int main(int argc, char const *argv[]) {
  auto [M,N,P] = parse<3>("3 3 3");
  
  return 0;
}
