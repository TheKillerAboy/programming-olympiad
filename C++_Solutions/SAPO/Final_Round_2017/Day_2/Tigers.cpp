#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long int

ll MOD = (ll)(10e+9) + 7;
ll add(ll a, ll b){
  return (a+b)%MOD;
}
ll N,L;
set<pair<ll,ll>> cliffS;
vector<pair<ll,ll>> cliff;
vector<ll> permus;

void getPermus(ll index, ll direction){
  permus[index] = 1;
  for(ll i = index; 0<i && i<N+1; i += direction){
    for(ll j = i + direction; 0<=j && j<=N+1;j+=direction){
      if(abs(cliff[j].first - cliff[i].first) <= L){
        if(cliff[j].second < cliff[i].second){
          permus[j] = add(permus[j],permus[i]);
        }
      }
    }
  }
}

int main(){
  cin>>N>>L;
  permus.resize(N+2,0);
  ll pos;
  ll height;
  for(ll i = 0; i < N; i++){
    cin>>pos>>height;
    cliffS.insert({pos,height});
  }
  cliffS.insert({(*cliffS.begin()).first-1,-1});
  cliffS.insert({(*cliffS.rbegin()).first+1,-1});
  cliff.resize(cliffS.size());
  pair<ll,ll> heightest = {-1,0};
  ll i = 0;
  for(auto ele : cliffS){
    cliff[i] = ele;
    heightest = max(pair<ll,ll>{ele.second,i},heightest);
    i++;
  }
  getPermus(heightest.second,1);
  getPermus(heightest.second,-1);
  std::cout << add(permus[0],permus[N+1]) << '\n';
  return 0;
}
