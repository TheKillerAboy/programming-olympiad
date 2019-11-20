#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define TRACEC(c_) for(auto e_:c_){cout<<e_<<' ';}cout<<'\n';

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string txt,pat;
  cin>>txt>>pat;
  cout<<txt<<'\n'<<pat<<'\n';
  vector<int> prefix(txt.size()),suffix(txt.size());
  vector<int> suffixFirst(pat.size()+1,-1);
  int prevIndex = 0;
  FOR(i,txt.size()){
    if(prevIndex == pat.size()){
      prevIndex = 0;
    }
    if(txt[i] == pat[prevIndex]){
      ++prevIndex;
    }
    else{
      prevIndex = 0;
    }
    prefix[i] = prevIndex;
  }
  prevIndex = 0;
  FORR(i,txt.size()){
    if(prevIndex == pat.size()){
      prevIndex = 0;
    }
    if(txt[i] == pat[pat.size()-1-prevIndex]){
      ++prevIndex;
    }
    else{
      prevIndex = 0;
    }
    suffix[i] = prevIndex;
    if(suffixFirst[prevIndex] == -1){
      suffixFirst[prevIndex] = i;
    }
  }
  TRACEC(suffix);
  TRACEC(suffixFirst);
  int MAX = 0;
  FOR(i,txt.size()){
    if(prefix[i] == pat.size()){
      MAX = max(MAX,(int)txt.size()-i-1);
    }
    else if(prefix[i] > 0 && suffixFirst[pat.size()-prefix[i]] != -1){
      MAX = max(MAX,suffixFirst[pat.size()-prefix[i]] - i + -1);
    }
    else{
      if(suffixFirst[pat.size()] != -1){
        MAX = max(MAX,suffixFirst[pat.size()] - i);
      }
    }
  }
  cout<<MAX<<'\n';
  return 0;
}
