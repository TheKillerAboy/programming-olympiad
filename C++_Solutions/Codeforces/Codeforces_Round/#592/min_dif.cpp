#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(ll i_=0;i_<a_;++i_)
#define FORI(i_,a_) for(ll i_=1;i_<=a_;++i_)
#define FORA(e_,c_) for(auto e_:c_)
#define ll long long int
#define INF LLONG_MAX/10000
#define NINF LLONG_MIN/10000
ll N,K;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  map<ll,ll> counter;
  set<pair<ll,ll>> queue;
  cin>>N>>K;
  ll a;
  FOR(i,N){
    cin>>a;
    if(counter.find(a) != counter.end()){
      queue.erase({a,counter[a]});
      ++counter[a];
      queue.insert({a,counter[a]});
    }
    else{
      queue.insert({a,1});
      counter[a] = 1;
    }
  }
  while(K>0){
    if((*queue.begin()).second < (*queue.rbegin()).second){
      //leftmost;
      ll val,valto,cnt,cnt2;
      tie(val,cnt) = *queue.begin();
      if(next(queue.begin()) != queue.end()){
      tie(valto,cnt2) = *next(queue.begin());
      }
      else{
        valto = INF;
        cnt2 = 0;
      }
      if((valto-val)*cnt <= K){
        K-=(valto-val)*cnt;
        queue.erase(queue.begin());
        if(queue.begin() != queue.end()){
        queue.erase(queue.begin());
        }
        queue.insert({valto,cnt+cnt2});
      }
      else{
        ll low = K/cnt;
        K=0;
        queue.erase(queue.begin());
        queue.insert({val+low,0});
        if(K%cnt != 0){
        queue.insert({val+low+1,0});
        }
      }
    }
    else{
      //rightmost;
      ll val,valto,cnt,cnt2;
      tie(val,cnt) = *queue.rbegin();
      if(next(queue.rbegin()) != queue.rend()){
        tie(valto,cnt2) = *next(queue.rbegin());
      }
      else{
        valto = NINF;
        cnt2 = 0;
      }
      if((val-valto)*cnt <= K){
        K-=(val-valto)*cnt;
        queue.erase(prev(queue.end(),1));
        if(queue.size() != 0){
          queue.erase(prev(queue.end(),1));
        }
        queue.insert({valto,cnt+cnt2});
      }
      else{
        ll low = K/cnt;
        K=0;
        queue.erase(prev(queue.end(),1));
        queue.insert({val-low,0});
        if(K%cnt!=0){
          queue.insert({val-low-1,0});
        }
      }
    }
  }
  cout<<(*queue.rbegin()).first-(*queue.begin()).first<<'\n';

  return 0;
}