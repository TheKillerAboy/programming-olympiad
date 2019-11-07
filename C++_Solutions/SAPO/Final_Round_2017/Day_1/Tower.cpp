#include <set>
#include <iostream>

using namespace std;

typedef long long ll;
#define INF (ll)1e+20;

ll n,m;
set<ll> cities;
set<ll> towers;

ll getMIN(ll city){
  auto closestRight = towers.lower_bound(city);
  ll right = INF;ll left = INF;
  if(closestRight != towers.end()){
    right = *closestRight;
  }
  if(closestRight != towers.begin()){
    left = *prev(closestRight,1);
  }
  return min(abs(right-city),abs(city-left));
}

int main(){
  cin>>n>>m;
  ll cur;
  ll i;
  for(i = 0; i < n; i ++){
    cin>>cur;
    cities.insert(cur);
  }
  for(i = 0; i < m; i ++){
    cin>>cur;
    towers.insert(cur);
  }
  ll MAX = 0;
  for(auto city : cities){
    MAX = max(MAX,getMIN(city));
  }
  cout<<MAX<<endl;
}
