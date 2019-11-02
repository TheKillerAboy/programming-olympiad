#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)

#define _ cerr<<' ';
#define _T cerr<<'\t';
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
#define INF INT_MAX/1000

vector<vector<vector<int>>> DP;
vector<vector<bool>> isForest;
int W,H;

int dp(int x, int y, bool forward){
  if(x >= W || x < 0 || y>=H || y < 0) return INF;
  else if(isForest[x][y]){DP[x][y][forward]=INF; return DP[x][y][forward];}
  else if(DP[x][y][forward] != -1) return DP[x][y][forward];
  DP[x][y][forward] = min(dp(x+(forward?1:-1),y,forward),dp(x,y+(forward?1:-1),forward))+1;
  return DP[x][y][forward];
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>H>>W;
  isForest.resize(W,vector<bool>(H));
  string line;
  FOR(y,H){
    cin>>line;
    FOR(x,W){
      isForest[x][y] = line[x] == '#';
    }
  }
  DP.resize(W,vector<vector<int>>(H,vector<int>(2,-1)));
  DP[W-1][H-1][1] = 1;
  DP[0][0][0] = 1;
  dp(0,0,1);
  dp(W-1,H-1,0);
  if(DP[W-1][H-1][0] == -1 || DP[W-1][H-1][0] >= INF){
    cout<<0<<'\n';
    return 0;
  }
  map<int,int> count;
  FOR(y,H){
    FOR(x,W){
        if(!((x==0&&y==0)||(x==W-1&&y==H-1))){
          if(DP[x][y][0] != -1 && DP[x][y][0] < INF){
            ++count[DP[x][y][0]];
          }
        }
    }
  }
  FORA(ele,count){
    if(ele.second == 1) {cout<<1<<'\n';return 0;}
  }
  cout<<2<<'\n';

  return 0;
}
