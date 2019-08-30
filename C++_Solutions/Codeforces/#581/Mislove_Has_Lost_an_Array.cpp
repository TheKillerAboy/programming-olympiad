#include <iostream>

using namespace std;

int main(){
  int n,l,r;
  cin>>n>>l>>r;
  int multi = 1;
  int max = 0;
  for(int i = 0; i < r - 1; i++){
    max+=multi;
    multi*=2;
  }
  max+=multi*(n-r+1);

  int min = n-l+1;
  multi = 2;
  for(int i = 0; i < l - 1; i++){
    min += multi;
    multi *= 2;
  }
  cout<<min<<' '<<max;
}
