#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)

#define _ cerr<<' ';
#define _N cerr<<'\n';
#define TRACEV(v_) cerr<<v_;
#define TRACEP(p_) cerr<<"("<<p_.first<<", "<<p_.second<<") ";
#define TRACECE(c_,tt_) for(auto e_:c_){tt_(e_);_;}_N;
#define TRACEC(c_) TRACECE(c_,TRACEV)
#define TRACEE(v_,tt_) tt_(v_);_N;
#define TRACE(v_) TRACEE(v_,TRACEV);
#define TRACEEP(v_) TRACEE(v_,TRACEP);

#define ll long long int
#define ull unsigned long long int

#define MOD 998244353;

inline ll mulM(ll a, ll b){return (a*b)%MOD;}
inline ll addM(ll a, ll b){return (a+b)%MOD;}
inline ll subM(ll a, ll b){ll out = a-b;while(out<0) out += MOD;return out;}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<ll> factorial(300001);
  factorial[0] = 1;
  FOR1(i,300001) factorial[i] = mulM(factorial[i-1],i);
  ll N;
  cin>>N;
  vector<pair<ll,ll>> seqA(N);
  vector<pair<ll,ll>> seqB(N);
  ll a,b;
  FOR(i,N){
    cin>>a>>b;
    seqA[i] = {a,b};
    seqB[i] = {b,a};
  }
  sort(seqB.begin(),seqB.end());
  sort(seqA.begin(),seqA.end());
  ll count = 1;
  ll firstOff = 1;
  ll thirdOff = 1;
  ll maxFound = seqA[0].second;
  FOR1(i,N){
    if(seqA[i].first == seqA[i-1].first) ++count;
    else{
      firstOff =mulM(factorial[count],firstOff);
      count = 1;
    } 
    if(seqA[i].second < maxFound) thirdOff = 0;
    else maxFound = seqA[i].second;
  }
      firstOff =mulM(factorial[count],firstOff);
  count = 1;
  ll secondOff = 1;
  FOR1(i,N){
    if(seqB[i].first == seqB[i-1].first) ++count;
    else{
      secondOff =mulM(factorial[count],secondOff);
      count = 1;
    } 
  }
      secondOff =mulM(factorial[count],secondOff);
  if(thirdOff != 0){
    count = 1;
    FOR1(i,N){
      if(seqA[i] == seqA[i-1]) ++count;
      else{
        thirdOff =mulM(factorial[count],thirdOff);
        count = 1;
      } 
    }
      thirdOff =mulM(factorial[count],thirdOff);
  }
  cout<<addM(subM(subM(factorial[N],firstOff),secondOff),thirdOff)<<'\n';


  return 0;
}