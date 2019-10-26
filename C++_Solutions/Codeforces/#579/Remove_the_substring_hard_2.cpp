#include <bits/stdc++.h>

using namespace std;

// #define ll long long int
#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define TRACEC(c_) for(auto e_:c_){cout<<e_<<' ';}cout<<'\n';

string txt,pat;
int N,M;
vector<int> seen(26,-1);

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>txt>>pat;
  N = txt.size();M = pat.size();
  vector<int> prefix(N,-1);
  vector<int> suffix(M,-1);
  int cursor = 0;
  FOR(i,N){
    if(cursor < N && txt[i] == pat[cursor]){
      prefix[i] = cursor;
      ++cursor;
    }
  }
  cursor = M-1;
  FORR(i,N){
    if(cursor >= 0 && txt[i] == pat[cursor]){
      suffix[cursor] = i;
      --cursor;
    }
  }
  // TRACEC(prefix);
  // TRACEC(suffix);
  int MAX = 0;
  FOR(i,N){
    if(prefix[i] == -1){
      MAX = max(MAX,suffix[0]-i);
    }
    else if(prefix[i] == M-1){
      MAX = max(MAX,N-1-i);
    }
    else{
      MAX = max(MAX,suffix[prefix[i]+1]-i-1);
    }
  }
  cout<<MAX<<'\n';
  return 0;
}
