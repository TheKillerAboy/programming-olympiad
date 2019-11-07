#include <iostream>
#include <vector>

using namespace std;

long long int factorial(const int& value){
  if(value == 0)return 1;
  return value*factorial(value-1);
}

int max_factorial(const int& value){
  int val = 0;
  while(factorial(++val)<value);
  return --val;
}

int main(int argc, char const *argv[]) {
  int N = 2100100100;
  int max = max_factorial(N);
  vector<int> values(max);
  for (size_t i = 0; i < max; i++) values[i] = 0;
  int current = max;
  while(N > 0){
    int c_fact = factorial(current);
    if(N-c_fact>=0){
      N-=c_fact;
      values[max-current]+=1;
    }
    else current--;
  }
  for(auto value:values){
    cout<<value<<' ';
  }
  return 0;
}
