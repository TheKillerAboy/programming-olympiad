#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define FORIT(it_,c_) for(auto it_ = c_.begin(); it_!=c_.end();++it_)

#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>
#define INF INT_MAX

vector<vector<int>> piecesOrdered(4);
vector<int> OUTPUT;
map<pair<vector<int>,bool>,bool> DP;
bool last;
	int N;

bool dp(vector<int> left, bool out){
	int LEFT = 0;
	FOR(i,left.size()) LEFT += left[i];
	if(DP.find(pair<vector<int>,bool>{left,out}) != DP.end()){
		return DP[pair<vector<int>,bool>{left,out}];
	}
	if(LEFT == 0) return out ^ last;
	pair<bool,int> OUT = {false,INF};
	if(out){
		if(left[2] > 0){
			auto left_d = left;
			--left_d[2];
			if(dp(left_d,true)){
				OUT = {true,min(OUT.second,piecesOrdered[2][left_d[2]])};
			}
		}
		if(left[3] > 0){
			auto left_d = left;
			--left_d[3];
			if(dp(left_d,false)){
				OUT = {true,min(OUT.second,piecesOrdered[3][left_d[3]])};
			}
		}
	}
	else{
		if(left[0] > 0){
			auto left_d = left;
			--left_d[0];
			if(dp(left_d,true)){
				OUT = {true,min(OUT.second,piecesOrdered[0][left_d[0]])};
			}
		}
		if(left[1] > 0){
			auto left_d = left;
			--left_d[1];
			if(dp(left_d,false)){
				OUT = {true,min(OUT.second,piecesOrdered[1][left_d[1]])};
			}
		}
	}
	if(OUT.first){
		OUTPUT[N-1-LEFT] = OUT.second;
	}
	DP[pair<vector<int>,bool>{left,out}] = OUT.first;
	return OUT.first;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>N;
	OUTPUT.resize(N);
	vector<int> input(4);
	bool first;
	int a,b;
	FOR(i,N){
		cin>>a>>b;
		if(a==5) {first = true;OUTPUT[0] = b;}
		else if(a==6) {first = false;OUTPUT[0] = b;}
		else if(a==7) {last = true;OUTPUT[N-1] = b;}
		else if(a==8) {last = false;OUTPUT[N-1] = b;}
		else{
			++input[a-1];
			piecesOrdered[a-1].push_back(b);
		}
	}
	FOR(i,4){
		sort(piecesOrdered[i].begin(),piecesOrdered[i].end(),greater<int>());
	}
	dp(input,first);
	FOR(i,N) if(OUTPUT[i] == 0){
		cout<<-1<<'\n';
		return 0;
	}
	FOR(i,N) cout<<OUTPUT[i]<<' ';
	cout<<'\n';
	return 0;
}