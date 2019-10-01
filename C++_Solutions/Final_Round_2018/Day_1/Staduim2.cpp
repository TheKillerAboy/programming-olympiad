vector<ll> leftSquare;
vector<ll> rowPSum;
vector<ll> columnPSum;

map<ll,set<ll>> rows;
map<ll,set<ll>> columns;

ll N,W;

int main(){
	cin>>N>>W;
	ll a,b;
	for(int i = 0; i < N; i++){
		cin>>a>>b;
		rows[b].insert(a);
		columns[a].insert(b);
	}
	auto itr = rows.begin();
	for(ll r = 0; r < W; r++){
		auto itc = itr->second.begin();
		ll sum = 0;
		for(ll c = 0; c < W; c++){
			if(itc->first == c){
				sum += itc->second;
				rowPSum[r][c] = sum;
				advance(itc,1);
			}
		}
		if(itr->first == r){
			advance(itr,1);
		}
	}	
}