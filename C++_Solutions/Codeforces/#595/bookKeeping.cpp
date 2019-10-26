#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)

vector<int> parent;
vector<int> sizeN;
int Q;
int N;

int uFind(int a){
	int b = a;
	while(parent[b] != -1){
		b = parent[b];
	}
	if(a!=b){
		parent[a] = b;
	}
	return b;
}

void uMerge(int a, int b){
	int aP = uFind(a),bP = uFind(b);
	if(aP!=bP){
		if(sizeN[aP] >= sizeN[bP]){
			parent[bP] = aP;
			sizeN[aP]+=sizeN[bP];
		}
		else{
			parent[aP] = bP;
			sizeN[bP]+=sizeN[aP];
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>Q;
	int cur;
	FOR(i,Q){
		cin>>N;
		parent = vector<int>(N,-1);
		sizeN = vector<int>(N,1);
		FOR(j,N){
			cin>>cur;
			uMerge(j,cur-1);
		}
		FOR(j,N){
			cout<<sizeN[uFind(j)]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}