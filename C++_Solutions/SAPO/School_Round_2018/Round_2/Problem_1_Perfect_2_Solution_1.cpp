#include <iostream>
#include <array>

using namespace std;

int D(int &n){
  int sum = 0;
  for (size_t i = 1; i < n/2+1; i++) {
    if(n%i == 0){
      sum += i;
    }
  }
  return sum;
}

int main(int argc, char const *argv[]) {
  int from = 1000;
  int to = 10000;

  array<int,3> values = {0,0,0};
  for (int i = from; i <= to; i++) {
    int d = D(i);
    if(d<i) values[0]+=1;
    else if(d==i) values[1]+=1;
    else values[2]+=1;
  }
  for (int value:values) {
    cout<< value <<' ';
  }
  cout<<endl;

  return 0;
}
