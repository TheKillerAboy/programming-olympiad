#include <bits/stdc++.h>

using namespace std;

int main(){
	int q,n;
	cin>>q;
	for(int i = 0; i < q; ++i){
		cin>>n;
		if(n<4){
			cout<<4-n<<'\n';
		}
		else if(n%2 == 0){
			cout<<0<<'\n';
		}
		else{
			cout<<1<<'\n';
		}
	}

	return 0;
}