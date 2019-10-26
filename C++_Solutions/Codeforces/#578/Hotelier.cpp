#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define ll long long int
#define ull unsigned long long int

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int A;
  string events;
  cin>>A>>events;
  vector<bool> rooms(10,false);
  FORA(e,events){
    if(e == 'L'){
      FOR(i,10){
        if(!rooms[i]){rooms[i]=true;break;}
      }
    }
    else if(e == 'R'){
      FORR(i,10){
        if(!rooms[i]){rooms[i]=true;break;}
      }
    }
    else{
      rooms[e-'0'] = false;
    }
  }
  FORA(e,rooms){
    cout<<e;
  }


  return 0;
}