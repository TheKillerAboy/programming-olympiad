#include <iostream>

using namespace std;

int main(){
  int n;
  cin>>n;
  int odd = 0;
  int total = 0;
  int num;
  for(int i = 0; i < n; i++){
    cin>>num;
    if(num % 2 == 1){
      odd++;
    }
  }
  if(odd < n - odd){
    cout<<odd;
  }
  else{
    cout<<n-odd;
  }
}
