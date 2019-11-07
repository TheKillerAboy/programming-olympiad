#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int D,E,W;
  cin>>D>>E>>W;
  if(D>100){
    D-=100;
  }
  else{
    D=0;
  }
  cout<<D*80+E*70+W*50<<'c';
  return 0;
}
