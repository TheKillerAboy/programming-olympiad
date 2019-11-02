#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(ll i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(ll i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(ll i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(ll i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(ll i_=1;i_<a_;++i_)

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

vector<ll> rooms;
vector<ll> roomsSize;
ll N,M;
ll R;

ll BS(ll l, ll r){
	ll mid = (l+r)>>1;
	if(mid == l) return r;
	if(rooms[mid] >= R){
		return BS(l,mid);
	}
	return BS(mid,r);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>N>>M;
	rooms.resize(N);
	roomsSize.resize(N);
	cin>>roomsSize[0];
	rooms[0] = roomsSize[0];
	FOR1(i,N){
		cin>>roomsSize[i];
		rooms[i] = rooms[i-1] + roomsSize[i];;
	}
	FOR(i,M){
		cin>>R;
		ll index = BS(-1,N-1);
		cout<<index+1<<' '<<R - rooms[index] + roomsSize[index]<<'\n';
	}



	return 0;
}