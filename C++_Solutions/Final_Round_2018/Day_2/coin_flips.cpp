#include <iostream>
#include <utility>
#include <vector>
#include <map>

using namespace std;

#define ll long long int

typedef pair<ll,ll> FRAC;

ll gcd(ll a, ll b){
	if(b>a){
		return gcd(b,a);
	}
	if(b == 0){
		return a;
	}
	else{
		return gcd(b,a%b);
	}
}

FRAC reduce(FRAC a){
	ll common = gcd(abs(a.first),abs(a.second));
	if(a.first < 0 && a.second < 0){
		common *= -1;
	}
	return {a.first/common,a.second/common};
}

FRAC add(FRAC a, FRAC b){
	return reduce({a.first*b.second+b.first*a.second,a.second*b.second});
}

FRAC sub(FRAC a, FRAC b){
	return reduce({a.first*b.second-b.first*a.second,a.second*b.second});
}

FRAC mul(FRAC a, FRAC b){
	return reduce({a.first*b.first,a.second*b.second});
}

FRAC div(FRAC a, FRAC b){
	return reduce({a.first*b.second,a.second*b.first});
}


FRAC F1 = {1,1};
FRAC Fn1 = {-1,1};
FRAC F0 = {0,1};

FRAC pow(FRAC a, ll n){
	if(n==0){
		return F1;
	}
	if(n == 1){
		return a;
	}
	else{
		return mul(pow(a,n-1),a);
	}
}

void prllFRAC(FRAC a,bool newLine = true){
	cout<<a.first<<'/'<<a.second;
	if(newLine){
		cout<<endl;
	}
}

FRAC P;

FRAC ProbHappen(ll n){
	return mul(pow(sub(F1,P),n-1),P);
}

map<vector<ll>,FRAC> SCORE;

FRAC score(vector<ll>& order, ll N);

FRAC getScore(vector<ll>& order, ll N){
	if(N==2){
		return F0;
	}
	if(SCORE.find(order) == SCORE.end()){
		SCORE[order] = score(order,N);
	}
	return SCORE[order];
}

void prllSeq(vector<ll>& order, bool newLine = true){
	for(auto value : order){
		cout<<value<<' ';
	}
	if(newLine){
		cout<<endl;
	}
}

FRAC score(vector<ll>& order, ll N){
	FRAC out = F0;
	for(ll i = 0; i < N; i++){
		vector<ll> next = order;
		next.erase(next.begin()+i);
		FRAC ne = {0,1};
		if(i>0 && i<N-1){
			ne = {order[i-1]*order[i+1],1};
		}
		out = add(out,mul(ProbHappen(i+1),add(ne,getScore(next,N-1))));
	}
	return mul(out,div(P,sub(P,ProbHappen(N+1))));
}

int main(){
	ll N,s,t,p;
	cin>>N>>s>>t>>p;
	P = {s,t};
	vector<ll> layout(N);
	for(ll i = 0; i < N; i++){
		cin>>layout[i];
	}
	FRAC best = score(layout,N);
	for(ll i = 0; i < p; i++){
		if((i*best.second)%p == best.first){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}