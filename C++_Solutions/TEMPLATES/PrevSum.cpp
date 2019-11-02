#include <bits/stdc++.h>

using namespace std;
#define ll long long int

//TEMPLATE START

template<typename T>
struct PrevSum{
	vector<T> pref;
	PrevSum(vector<T>& arr){
		pref.resize(arr.size());
		pref[0] = arr[0];
		for(size_t i = 1; i < arr.size(); ++i) pref[i] = pref[i-1] + arr[i];
	}
	inline T query(int l, int r){
		return l>r?(r==0?pref[l]:pref[l]-pref[r-1]):(l==0?pref[r]:pref[r]-pref[l-1]);
	}
};

//TEMPLATE END

//test
int main(){
	vector<ll> arr = {3,2,1,4,5,2,3};
	PrevSum<ll> myBIT(arr);
	cout<<myBIT.query(1,3);
}