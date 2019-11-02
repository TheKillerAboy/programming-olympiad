/*
ID: annekin1
TASK: wormhole
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
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

#define ull unsigned long long int

vector<pair<ll,ll>> wormholes;
map<ll,ll> connectionsDirection;

ll N;
ll C;

struct Node{
	Node* parent;
	ll a,b;
	Node(Node* p, ll a_, ll b_) : parent(p),a(a_),b(b_){}
	bool canUse(ll c){
		if(c==a || c==b) return false;
		else if(parent == NULL) return true;
		return parent->canUse(c);
	}
};

void allP(ll left,Node* parent){
	if(left == 0){
		map<ll,ll> connections;
		Node* current = parent;
		while(current != NULL){
			// TRACEP((pair<ll,ll>{current->a,current->b})) _
			connections[current->a] = current->b;
			connections[current->b] = current->a;
			current = current->parent;
		}
		FOR(i,N){
			set<ll> visited;
			ll cNode = i;
			bool pos = true;
			FOR(j,N){
				if(connectionsDirection[cNode] == -1){
					pos = false;
					break;
				}
				cNode = connections[connectionsDirection[cNode]];
				if(cNode == i){
					break;
				}
			}
			if(pos){
				++C;
				// TRACE(" Y");
				return;
			}
		}
		// TRACE((" N"));	
		return;
	}
	ll a;
	FOR(i,N){
		if(parent == NULL || parent->canUse(i)){
			a = i;
			break;
		}
	}
	FOR(i,N){
		if((parent == NULL || parent->canUse(i)) && i != a){
			allP(left-1,new Node(parent,a,i));
		}
	}
}

int main(){
	C = 0;
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");
	ll a,b;
	fin>>N;
	wormholes.resize(N);
	FOR(i,N){
		fin>>a>>b;
		wormholes[i] = {b,a};
	}
	sort(wormholes.begin(),wormholes.end());
	FOR(i,N-1){
		if(wormholes[i].first == wormholes[i+1].first){
			connectionsDirection[i] = i+1;
		}
		else{
			connectionsDirection[i] = -1;
		}
	}
	connectionsDirection[N-1] = -1;
	allP(N/2,NULL);
	fout<<C<<'\n';

	return 0;
}