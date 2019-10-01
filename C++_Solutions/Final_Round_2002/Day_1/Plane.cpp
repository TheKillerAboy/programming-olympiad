#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <array>
#include <tuple>
#include <cmath>

using namespace std;

#define ll long long int

ll gcd(ll a, ll b){
	if(b == 0){
		return a;
	}
	if(b>a){
		return gcd(b,a);
	}
	return gcd(b,a%b);

}

ll lcm(ll a, ll b){
	return a*b/gcd(a,b);
}

struct Airport;

vector<Airport*> airports;

struct Airport{
	vector<pair<int,int>> times;
	int code;
	int created;

	Airport(int code_){
		code = code_;
		created = 0;
	}

	void elapse(int a){
		vector<int> send;
		for(size_t i = 0; i < times.size(); i++){
			if(times[i].first > a){
				times[i].first -= a;
			}
			else if(times[i].first != 0){
				times[i].first = 0;
				send.push_back(i);
			}
		}
		for(size_t i = 0; i < send.size(); i++){
			airports[times[send[i]-i].second-1]->times.push_back({0,code});
			times.erase(times.begin()+send[i]-i);
		}
	}
	void send_plane(int T, int B){
		auto it = times.begin();
		for(; it != times.end(); it++){
			if((*it).first == 0){
				break;
			}
		}
		if(it == times.end()){
			times.push_back({T,B});
			created++;
		}	
		else{
			*it = {T,B};
		}
	}
};

int main(){
	int N,F;
	int time = 0;
	cin>>N>>F;
	airports.resize(N);
	for(int i = 0; i < N; i++){
		airports[i] = new Airport(i+1);
	}
	set<tuple<int,int,int,int>> queries;
	int A,B,S,T;
	ll LCM = 1;
	for(int i = 0; i < F; i++){
		cin>>A>>B>>S>>T;
		queries.insert({S,A,B,T});
		LCM = lcm(LCM,T);
		if(S!=0){
			cout<<LCM<<' '<<S<<endl;
			LCM = lcm(LCM,S);
			cout<<LCM<<endl;
		}
	}
	for(int i = 0; i < ceil((float)LCM/86400);i++){
		for(auto querie : queries){
			tie(S,A,B,T) = querie;
			for(int i = 0; i < N; i++){
				airports[i]->elapse(S-time);
			}
			airports[A-1]->send_plane(T,B);
			time = S;
		}
		for(int i = 0; i < N; i++){
			airports[i]->elapse(86400-time);
		}
		time = 0;
	}
	for(int i = 0; i<N;i++){
		cout<<airports[i]->created<<endl;
	}
}