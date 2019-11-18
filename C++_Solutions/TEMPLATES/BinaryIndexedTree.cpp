#include <bits/stdc++.h>

using namespace std;
#define ll long long int

//TEMPLATE START

template<typename T>
struct BIT{
	vector<T> BITree;
	template<typename I>
	void update(I i, T value){
		++i;
		while(i<BITree.size()){
			BITree[i] += value;
			i+=(i&(-i));
		}
	}
	BIT(vector<T>& arr){
		BITree = vector<T>(arr.size()+1,0);
		for(size_t i = 0; i < arr.size(); ++i){
			update(i,arr[i]);
		}
	}
	template<typename I>
	T getSum(I i){
		++i;
		T out = 0;
		while(i>0){
			out+=BITree[i];
			i-=(i&(-i));
		}
		return out;
	}
	template<typename I1, typename I2>
	T getSumRange(I1 l, I2 r){
		if(l == 0){
			return getSum(r);
		}
		return getSum(r) - getSum(l-1);
	}
};
//ERROR MODULE EXT
template<typename T>
ostream& operator<<(ostream &os, const BIT<T> &v){
	TRACEV(v.BITree);
	return os;
}
//ERROR MODULE EXT
//TEMPLATE END

//test
int main(){
	vector<ll> arr = {3,2,1,4,5,2,3};
	BIT<ll> myBIT(arr);
	cout<<myBIT.getSumRange(0,3);
}