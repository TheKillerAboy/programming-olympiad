 #include <vector>
#include <set>
#include <climits>

using namespace std;

#define ll long long int

#define INF LLONG_MAX

void posiziona(int D, int T);
void budget(int B);

struct Plant{
	ll left;
	ll depth;
	ll UpLine(ll a){
		return a - left + depth;
	}
	ll DownLine(ll a){
		return -a + left + depth;
	}
};

struct Spray{
	set<ll> plants;
	ll depth;
	ll loc;

	Spray(ll d, ll l){
		depth = d;
		loc = l;
	}
};

ll N;
set<ll> plantsAll;
vector<Plant*> plants;
vector<Spray*> sprays;

bool hasUnion(set<ll>& l, set<ll> r){
	for(auto value: r){
		if(l.find(value) != l.end()){
			return true;
		}
	}
	return false;
}

pair<ll,vector<ll>> bestCombo(vector<ll> spraysS, set<ll> have, ll value){
	pair<ll,vector<ll>> out = {INF,vector<ll>()};
	if(have.size() == N){
		out.first = value;
		return out;
	}
	for(ll i = 0; i < sprays.size(); i++){
		if(!hasUnion(have,sprays[i]->plants)){
			set<ll> next = have;
			copy(sprays[i]->plants.begin(),sprays[i]->plants.end(),inserter(next,next.begin()));
			vector<ll> nextS = spraysS;
			nextS.push_back(i);
			pair<ll,vector<ll>> cur = bestCombo(nextS,next,value+sprays[i]->depth);
			out = min(out,cur);
		}
	}
	return out;
}

void irriga(int C, int n, vector<int>& X, vector<int>& P){
	N = n;
	set<pair<ll,ll>> spraysQ;
	plants.resize(N);
	for(ll i =0; i < N; i++){
		plants[i]->left = X[i];
		plants[i]->depth = X[i];
	}
	for(ll i = 0; i < N; i++){
		if(spraysQ.find({plants[i]->left,plants[i]->depth}) == spraysQ.end()){
			spraysQ.insert({plants[i]->left,plants[i]->depth});
			sprays.push_back(new Spray(plants[i]->left,plants[i]->depth));
			for(ll k = 0; k < N; k++){
				if(plants[k]->UpLine(plants[i]->left) == plants[i]->depth || plants[k]->DownLine(plants[i]->left) == plants[i]->depth){
					sprays.back()->plants.insert(k);
				}
			}
		}	
		for(ll j = i +1 ; j<N;j++){
			ll x1 = (plants[j]->depth - plants[i]->depth + plants[i]->left + plants[j]->left)/2;
			ll y1 = plants[i]->UpLine(x1);
			ll x2 = (plants[i]->depth - plants[j]->depth + plants[i]->left + plants[j]->left)/2;
			ll y2 = plants[j]->UpLine(x1);
			if(spraysQ.find({x1,y1}) == spraysQ.end()){
				spraysQ.insert({x1,y1});
				sprays.push_back(new Spray(x1,y1));
				for(ll k = 0; k < N; k++){
					if(plants[k]->UpLine(x1) == y1 || plants[k]->DownLine(x1) == y1){
						sprays.back()->plants.insert(k);
					}
				}
			}
			if(spraysQ.find({x2,y2}) == spraysQ.end()){
				spraysQ.insert({x2,y2});
				sprays.push_back(new Spray(x2,y2));
				for(ll k = 0; k < N; k++){
					if(plants[k]->UpLine(x2) == y2 || plants[k]->DownLine(x2) == y2){
						sprays.back()->plants.insert(k);
					}
				}
			}
		}
	}
	pair<ll,vector<ll>> best = bestCombo(vector<ll>(),set<ll>(),0);
	for(ll spray : best.second){
		posiziona(sprays[spray]->loc, sprays[spray]->depth);
	}
	budget(best.first+best.second.size()*C);
}