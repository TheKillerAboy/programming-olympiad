#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<tuple<int,int,int>> offers;

int main(){
	int N,K;
	cin>>N>>K;
	offers.resize(N-1);
	int a,b,c;
	for(int i = 0; i < N-1;i++){
		cin>>a>>b>>c;
		offers[i] = tuple<int,int,int>{c,a,b};
	}
	sort(offers.rbegin(),offers.rend());
	int l = 0, r = 0;
	vector<int> left(N,K);
	int sum = 0;
	int maxSum = 0;

	while(r < N-1){
		if((left[get<1>(offers[r])] == 0 || left[get<2>(offers[r])] == 0) && l < r){
			left[get<1>(offers[l])]++;
			left[get<2>(offers[l])]++;
			sum -= get<0>(offers[l]);
			l++;
		}
		else{
			left[get<1>(offers[r])]--;
			left[get<2>(offers[r])]--;
			sum += get<0>(offers[r]);
			r++;
		}
		maxSum = max(sum,maxSum);

	}
	cout<<maxSum<<endl;
	return 0;
}