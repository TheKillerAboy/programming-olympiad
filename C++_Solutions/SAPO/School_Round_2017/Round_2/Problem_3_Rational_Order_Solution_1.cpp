#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
  int N = 100;
  vector<long double> values = {0,1};
  for (int bottom = 1; bottom < N+1; bottom++) {
    for (int top = 1; top < bottom; top++) {
      if(find(values.begin(),values.end(),(long double)top/bottom) == values.end())
      values.push_back((long double)top/bottom);
    }
  }
  cout<<values.size();
  return 0;
}
