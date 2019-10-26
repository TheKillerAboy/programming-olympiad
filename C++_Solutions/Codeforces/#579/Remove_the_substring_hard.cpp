#include <bits/stdc++.h>

using namespace std;

// #define ll long long int
#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define TRACEC(c_) for(auto e_:c_){cout<<e_<<' ';}cout<<'\n';
#define CS 26
typedef array<int,CS> Alpha;

Alpha EMPTY;
Alpha INFS;

inline Alpha add(Alpha a, Alpha b){
  Alpha out;
  FOR(i,CS){
    out[i] = a[i] + b[i];
  }
  return out;
}

inline Alpha min(Alpha a, Alpha b){
  Alpha out;
  FOR(i,CS){
    out[i] = a[i] - b[i];
  }
  return out;
}

inline bool isPos(Alpha a){
  FOR(i,CS){
    if(a[i] < 0){
      return false;
    }
  }
  return true;
}

vector<Alpha> prefixAlpha;
int N,M;
string txt, pat;
Alpha patNeed;

inline Alpha retrieve(int i){
  return i>=N?INFS:(i<0?EMPTY:prefixAlpha[i]);
}

inline bool canRemoveSegment(int anchor, int i){
  // cout<<anchor<<' '<<i<<' '<<isPos(min(min(retrieve(N-1),min(retrieve(i),retrieve(anchor-1))),patNeed))<<'\n';
  return isPos(min(min(retrieve(N-1),min(retrieve(i),retrieve(anchor-1))),patNeed));
}

int BS(int anchor, int l, int r){
  int mid = (l+r)>>1;
  if(mid == l || r < l){
    return l;
  }
  if(canRemoveSegment(anchor,mid)){
    return BS(anchor,mid,r);
  }
  return BS(anchor,l,mid);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  EMPTY.fill(0);
  INFS.fill(INT_MAX);
  cin>>txt>>pat;
  N=txt.size();M=pat.size();
  prefixAlpha.resize(N);

  Alpha track = EMPTY;
  FOR(i,N){
    ++track[txt[i]-'a'];
    prefixAlpha[i] = track;
  }
  patNeed = EMPTY;
  FOR(i,M){
    BS(i,i-1,N);
    ++patNeed[pat[i]-'a'];
  }

  int MAX = 0;
  FOR(i,N){
    MAX = max(MAX,BS(i,i-1,N) - i + 1);
  }
  cout<<MAX<<'\n';


  return 0;
}
