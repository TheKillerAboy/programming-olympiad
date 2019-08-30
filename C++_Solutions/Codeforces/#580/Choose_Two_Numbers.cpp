#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
  int sizeA, sizeB;
  int maxA = 0,maxB = 0;
  int val;

  cin >> sizeA;
  for(int i = 0; i < sizeA; i++){
    cin >> val;
    if(val > maxA){
      maxA = val;
    }
  }

  cin >> sizeB;
  for(int i = 0; i < sizeB; i++){
    cin >> val;
    if(val > maxB){
      maxB = val;
    }
  }

  cout<<maxA<<' '<<maxB;
  return 0;
}
