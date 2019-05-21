#include <iostream>
#include <valarray>

using namespace std;

int main(int argc, char const *argv[]) {
  valarray<int> tri = {15,16,17};
  int N = 33;
  int sum;

  for(int i = 0; i < N-tri.size();i++){
    sum = tri.sum();
    tri = tri.shift(1);
    tri[tri.size()-1]=sum;
  }

  cout<<tri[tri.size()-1];
  return 0;
}
