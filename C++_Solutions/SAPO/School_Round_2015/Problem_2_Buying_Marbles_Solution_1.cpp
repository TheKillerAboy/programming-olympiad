#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n_marbles = 5;
  vector<int> marbles = {1,2,7,3,4};
  int max = *max_element(marbles.begin(),marbles.end());
  int count = 0;
  for(auto value: marbles){
    count += max - value;
  }
  cout<<count<<endl;
  return 0;
}
