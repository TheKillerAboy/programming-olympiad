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
#define INF INT_MAX/1000

vector<pair<int,int>> them;
int N;

int query(){
	sort(them.begin(),them.end());
	vector<int> amount;
	map<int,int> total;
	map<int,set<int>> bestPrice;
	FORA(ele,them) {
		++total[ele.first];
		if(bestPrice.find(ele.first) == bestPrice.end()) {
			amount.push_back(ele.first);
		}
		bestPrice[ele.first].insert(ele.second);
	}
	sort(amount.begin(),amount.end());
	int totalCost = 0;
	int totalPeople = 0;
	while(!amount.empty()){
		// TRACEC(amount)
		tuple<int,int,int> best = {INF,1,-1};
		FORA(ele,amount){
			int currentExtra = 1;
			--total[ele];
			set<int> notUsed(amount.begin(),amount.end());
			while(!notUsed.empty() && *notUsed.begin() <= totalPeople + currentExtra){
				currentExtra += total[*notUsed.begin()];
				notUsed.erase(notUsed.begin());
			}
			++total[ele];
			if(get<0>(best)*currentExtra > (*bestPrice[ele].begin())*get<1>(best)) best = {(*bestPrice[ele].begin()),currentExtra,ele};
		}
		TRACET(best,3) _N
		totalCost += get<0>(best);
		totalPeople += get<1>(best);
		--total[get<2>(best)];
		bestPrice[get<2>(best)].erase(bestPrice[get<2>(best)].begin());

		vector<int> amount_;
		FORA(ele,amount) if(ele > totalPeople){
			amount_.push_back(ele);
		}
		amount = amount_;
	}
	return totalCost;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q;
	int a,b;
	cin>>Q;
	FOR(i,Q){
		cin>>N;
		them.resize(N);
		FOR(j,N){
			cin>>a>>b;
			if(a == 0) them[j] = {0,0};
			else them[j] = {a,b};
		}
		cout<<query()<<'\n';
	}


	return 0;
}