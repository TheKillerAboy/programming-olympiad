#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  cout<<"N?";
  cin>>N;
  int sum = 0;
  for (int i = 1; i < N; i++) {
    if(N%i==0) sum+=i;
  }
  cout<<sum;

  return 0;
}
