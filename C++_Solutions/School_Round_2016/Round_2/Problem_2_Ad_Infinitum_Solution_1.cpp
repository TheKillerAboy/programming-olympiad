#include <iostream>

using namespace std;

int pow_mod(const int& value, const int& power, const int& mod){
  if(power == 1) return value%mod;
  else return (pow_mod(value,power-1,mod)*value)%mod;
}

long long int pow(const long long int& value, const int& power){
  if(power == 1) return value;
  else return (pow(value,power-1)*value);
}

int get_bound(const int& value){
  int bound = 1;
  while (pow_mod(10,bound,value)-1!= 0){
    bound++;
    if(bound > value) return -1;
  }
  return bound;
}

long long int get_repeat(const int& value){
  return (pow(10,get_bound(value))-1)/value;
}

int whole_num(const int& top, const int& bottom){
  return top/bottom;
}

int main(int argc, char const *argv[]) {
  int top = 45;
  int bottom = 46;
  int left = whole_num(top,bottom);
  top -= left*bottom;
  if(get_bound(bottom) != -1){
    cout<<left<<'.'<<'('<<top*get_repeat(bottom)<<')';
}
else{
  cout<<to_string((long double)top/bottom);
}

  return 0;
}
