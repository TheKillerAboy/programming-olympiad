#include <bits/stdc++.h>

using namespace std;
#define ll long long int

//TEMPLATE START

template<typename T>
struct BIT{
	vector<T> BITree;
	void update(int i, T value){
		++i;
		while(i<BITree.size()){
			BITree[i] += value;
			i+=(i&(-i));
		}
	}
	BIT(vector<T>& arr){
		BITree = vector<T>(arr.size()+1,0);
		for(int i = 0; i < arr.size(); ++i){
			update(i,arr[i]);
		}
	}
	T getSum(int i){
		++i;
		T out = 0;
		while(i>0){
			out+=BITree[i];
			i-=(i&(-i));
		}
		return out;
	}
	T getSumRange(int l, int r){
		if(l == 0){
			return getSum(r);
		}
		return getSum(r) - getSum(l-1);
	}
};

//TEMPLATE END

//test
int main(){
	vector<ll> arr = {3,2,1,4,5,2,3};
	BIT<ll> myBIT(arr);
	cout<<myBIT.getSumRange(0,3);
}