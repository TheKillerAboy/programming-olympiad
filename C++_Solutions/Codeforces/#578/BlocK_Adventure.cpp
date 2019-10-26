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

int N,M,K;
vector<int> columns;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int Q;
  cin>>Q;
  FOR(i,Q){
    cin>>N>>M>>K;
    columns.resize(N);
    FOR(j,N){
      cin>>columns[j];
    }
    bool isPos = true;
    FOR(i,N-1){
      if(columns[i]<columns[i+1]-K){
        M-=columns[i+1]-columns[i]-K;
        if(M<0){
          isPos = false;
          break;
        }
      }
      else{
        M+=min(columns[i],columns[i]-columns[i+1]+K);
      }
    }
    cout<<(isPos?"YES":"NO")<<'\n';
  }


  return 0;
}