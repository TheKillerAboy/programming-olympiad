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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q,N;
	int R,P,S,cR,cP,cS,uR,uP,uS;
	string seq;
	cin>>Q;
	FOR(i,Q){
		cin>>N;
		cin>>R>>P>>S;
		cin>>seq;
		cR = 0;cP = 0; cS = 0;
		FOR(i,N){
			if(seq[i]=='R') ++cR;
			else if(seq[i]=='P') ++cP;
			else ++cS;
		}
		uR = min(R,cS);
		uP = min(P,cR);
		uS = min(S,cP);
		if(uR+uP+uS >= N/2+N%2){
			cout<<"YES\n";
			vector<char> events(N,0);
			FOR(i,N){
				if(seq[i] == 'R' && P>0){--P;events[i]='P';}
				else if(seq[i] == 'S' && R>0){--R;events[i]='R';}
				else if(seq[i] == 'P' && S>0){--S;events[i]='S';}
			}
			FOR(i,N){
				if(events[i] == 0){
					if(P>0){--P;events[i]='P';}
					else if(R>0){--R;events[i]='R';}
					else{--S;events[i]='S';}
				}
			}
			FOR(i,N){
				cout<<events[i];
			}
			cout<<'\n';
		}
		else cout<<"NO\n";
	}


	return 0;
}