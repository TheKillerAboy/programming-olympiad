#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(e_,c_) for(auto e_:c_)
#define ll long long int
#define NINF LLONG_MIN;

ll Q,N,X,bestDamage,bestReduce;

int main(){
  // cin.tie(0);
  // ios::sync_with_stdio((X-bestDamage)/bestReducefalse);
  cin>>Q;
  FOR(i,Q){
    cin>>N>>X;
    ll a,b;
    bestReduce = 0;
    bestDamage = NINF;
    FOR(j,N){
      cin>>a>>b;
      bestDamage = max(bestDamage,a);
      bestReduce = max(bestReduce,a-b);
    }
    if(bestReduce <= 0){
      if(X > bestDamage){
        cout<<-1<<'\n';
        continue;
      }
      else{
        cout<<1<<'\n';
        continue;
      }
    }
    if(bestDamage >= X){
      cout<<1<<'\n';
      continue;
    }
    ll out = max((X-bestDamage)/bestReduce + ((X-bestDamage)%bestReduce?1:0),(ll)0);
    X-=out*bestReduce;
    if(X>0){
      ++out;
    }
    cout<<out<<'\n';
  }
  return 0;
}