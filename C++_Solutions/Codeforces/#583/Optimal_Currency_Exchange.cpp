#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
  int dollarBills[] = {1,2,5,10,20,50,100};
  int euroBills[] = {5,10,20,50,100,200};
  int n,d,e;
  cin>>n>>d>>e;
  for(int i = 0; i < 7; i++){
    dollarBills[i] = d*dollarBills[i];
  }
  for(int i = 0; i < 6; i++){
    euroBills[i] = e*euroBills[i];
  }
  set<int> allbills;
  copy(dollarBills,dollarBills+7,inserter(allbills,allbills.begin()));
  copy(euroBills,euroBills+6,inserter(allbills,allbills.begin()));
  set<int> other;
  for(auto it = allbills.rbegin(); it!=allbills.rend();it++){
    for(auto it2 = it; it2!=allbills.rend();it2++){
      other.insert(abs(*it2-*it));
    }
  }
  copy(other.begin(),other.end(),inserter(allbills,allbills.begin()));
  for(auto it = allbills.rbegin(); it!=allbills.rend();it++){
    cerr<<n<<' '<<*it<<endl;
    if(*it != 0){
      n -= (*it)*(n/(*it));
    }
  }
  cout<<n<<endl;
}
