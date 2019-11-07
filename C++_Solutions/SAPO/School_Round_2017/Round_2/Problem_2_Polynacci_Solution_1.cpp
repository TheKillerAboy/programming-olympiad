#include <iostream>
#include <valarray>

using namespace std;

int main(int argc, char const *argv[]) {
  valarray<int> tri = {2,8,15,4,4,3,8,9,10,3};
  int N = 36;
  int sum;

  for(int i = 0; i < N-tri.size();i++){
    sum = tri.sum();
    tri = tri.shift(1);
    tri[tri.size()-1]=sum;
  }

  cout<<tri[tri.size()-1];
  return 0;
}
