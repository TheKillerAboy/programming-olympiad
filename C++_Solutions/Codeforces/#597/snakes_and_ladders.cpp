#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define FORIT(it_,c_) for(auto it_ = c_.begin(); it_!=c_.end();++it_)

#define _ cerr<<' ';
#define _N cerr<<'\n';
#define _T cerr<<'\t';
#define TRACEV(v_) cerr<<v_;
#define TRACEP(p_) cerr<<"("<<p_.first<<", "<<p_.second<<") ";
#define TRACECE(c_,tt_) for(auto e_:c_){tt_(e_);_;}_N;
#define TRACEC(c_) TRACECE(c_,TRACEV)
#define TRACEE(v_,tt_) tt_(v_);_N;
#define TRACE(v_) TRACEE(v_,TRACEV);
#define TRACEEP(v_) TRACEE(v_,TRACEP);

#define ll long long int
#define ull unsigned long long int

typedef pair<ull,ull> BRAKE;

#define B_ZERO BRAKE{0,1}
#define B_ONE BRAKE{1,1}

inline ull gcd(ull a, ull b){
	return b>a?gcd(b,a):(b==0?a:gcd(b,a%b));
}

inline BRAKE reduce(BRAKE a){
	ull GCD = gcd(a.first,a.second);
	return {a.first/GCD,a.second/GCD};
}

inline BRAKE mul(BRAKE a, BRAKE b){
	return reduce({a.first*b.first,a.second*b.second});
}

inline BRAKE div(BRAKE a, BRAKE b){
	return reduce({a.first*b.second,a.second*b.first});
}

inline BRAKE add(BRAKE a, BRAKE b){
	return reduce({a.first*b.second + a.second*b.first ,a.second*b.second});
}

inline BRAKE min(BRAKE a, BRAKE b){
	return reduce({a.first*b.second - a.second*b.first ,a.second*b.second});
}

vector<vector<bool>> startLadder;
vector<vector<pair<int,int>>> endLadder;

BRAKE dp(int x, int y, bool cameByLadder){
	if(x >= 10) return dp(x-10,y+1,cameByLadder);
	if(y >= 10) return B_ZERO;
	if(x == 9 && y == 9) return B_ONE;
	BRAKE out = B_ZERO;
	BRAKE chooses = {1,6};
	if(startLadder[x][y]){
		++chooses.second;
		if(!cameByLadder){
			out = add(out,mul(add(dp(endLadder[x][y].first,endLadder[x][y].second,true),B_ONE),chooses));
		}
	}
	FORI(i,6){
		out = add(out,mul(add(dp(x+i,y,false),B_ONE),chooses));
	}
	return out;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int X = 9, Y = 9;
	FOR(i,100){
		
	}


	return 0;
}