#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(e_,c_) for(auto e_:c_)
#define ll long long int

ll Q,str,inte,expe;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>Q;
	FOR(i,Q){
		cin>>str>>inte>>expe;
		// cerr<<str<<' '<<inte<<' '<<expe<<' '<<(str+expe-inte)/2 + (str+expe-inte)%2<<'\n';
		cout<<max(expe - max((ll)0, (expe + inte - str + 2) / 2)+1,(ll)0)<<'\n';
	}
	return 0;
}