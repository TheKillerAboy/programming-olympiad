#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(e_,c_) for(auto e_:c_)
#define ll long long int
#define NINF LLONG_MIN;

ll Q,N,M,NE,ME,NO,MO;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll a;
  cin>>Q;
  FOR(i,Q){
    cin>>N;
    NO=0;NE=0;
    FOR(j,N){
      cin>>a;
      if(a%2==1){++NO;}
      else{++NE;}
    }
    cin>>M;
    MO=0;ME=0;
    FOR(j,M){
      cin>>a;
      if(a%2==1){++MO;}
      else{++ME;}
    }
    cout<<MO*NO+ME*NE<<'\n';
  }
  return 0;
}