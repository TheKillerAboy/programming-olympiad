#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define ll long long int

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin>>N;
	vector<int> right(N),left(N),up(N),down(N);
	bool isPos = true;
	FOR(i,N){
		cin>>right[i];
		if(right[i]==-1){
			right[i]=N;
		}
		else{
			up[N-1-right[i]] = i;
			down[N-1-right[i]] = N-1-i;
		}
	}
	FOR(i,N){
		cin>>left[i];
		if(left[i]==-1){
			left[i]=N;
		}
		else if(left[i] > N-1-right[i]){
			isPos = false;
			cout<<0<<'\n';
		}
		if(left[i]!=N){
			if(i > up[left[i]] || N-1-i > down[left[i]]){
				isPos = false;
			cout<<1<<'\n';
			}
			up[left[i]] = i;
			down[left[i]] = N-1-i;
		}
	}
	int temp;
	FOR(i,N){
		cin>>temp;
		if(temp > up[i]){
			isPos = false;
			cout<<2<<'\n';
		}
		up[i] = temp;
		if(up[i]==-1){
			up[i]=N;
		}
	}
	FOR(i,N){
		cin>>temp;
		if(temp > down[i]){
			isPos = false;
			cout<<3<<'\n';
		}
		down[i] = temp;
		if(down[i]==-1){
			down[i]=N;
		}
		if(down[i] > N-1-up[i]){
			isPos = false;
			cout<<4<<'\n';
		}
	}
	cout<<(isPos?"DA":"NE")<<'\n';

	return 0;
}