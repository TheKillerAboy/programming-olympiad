#include <iostream>

using namespace std;

int main(){
	string num;
	int n,k;
	cin>>n>>k;
	cin>>num;
	if(n == 1 && k > 0){
		k--;
		num[0] = '0';
	}
	else if(num[0] -'1' > 0 && k>0){
		k--;
		num[0] = '1';
	}
	int i = 1;
	while(k>0 && i < n){
		if(num[i] != '0'){
			k--;
			num[i] = '0';
		}
		i++;
	}
	cout<<num;
	return 0;
}