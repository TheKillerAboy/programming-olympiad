#include <iostream>

using namespace std;

int main(){
  int P = 10000;
  float r = 6.75;
  float t = 5.5;

  cout<<P*(1+r*t/100)<<endl;

  return 0;
}
