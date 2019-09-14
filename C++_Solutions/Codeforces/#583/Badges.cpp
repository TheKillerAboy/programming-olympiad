#include <iostream>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
  int b,g,n;
  cin>>b>>g>>n;
  int minb = b < n ? b : n;
  int mina = g < n ? g : n;

  int max_ = max(minb,mina);
  int min_ = min(minb,mina);

  int out = 0;

  for(int i = max_; i >= 0; i--){
    if(n-i <= min_){
      out++;
    }
  }
cout<<out<<endl;
}
