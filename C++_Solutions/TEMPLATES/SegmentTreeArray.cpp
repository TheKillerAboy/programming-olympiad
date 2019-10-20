#include <bits/stdc++.h>

using namespace std;
#define ll long long int

//TEMPLATE START

template<typename T, typename CMP>
struct SegTree{
	vector<T> ST;
	CMP cmp;
	int size__;
	T DEFAULT;
	int size(){
		return size__;
	}
	void fill(vector<T>& arr, int nl, int nr, int ni){
		if(nl<nr){
			int mid = (nl+nr)>>1;
			fill(arr,nl,mid,2*ni+1);
			fill(arr,mid+1,nr,2*ni+2);
			ST[ni] = cmp(ST[2*ni+1],ST[2*ni+2]);
		}	
		else if(nl==nr){
			ST[ni] = arr[nl];
		}
	}
	SegTree(vector<T> arr, CMP cmp_, T default_ = 0){
		ST.resize((1<<(ceil(log2(arr.size()))+1))-1);
		cmp = cmp_;
		size__ = arr.size();
		DEFAULT = default_;
		fill(arr,0,size()-1,0);
	}
	T query__(int ql, int qr, int nl, int nr, int ni){
		if(ql<=nl && nr<= qr){
			return ST[ni];
		}
		else if(nr<ql || nl>qr){
			return DEFAULT;
		}
		else{
			int mid = (nl+nr)>>1;
			return cmp(query__(ql,qr,nl,mid,2*ni+1),query__(ql,qr,mid+1,nr,2*ni+2));
		}
	}
	T query(int l, int r){
		return query__(l,r,0,size()-1,0);
	}
	void updateRange__(int ql, int qr, int nl, int nr, int ni, T value){
		if(!(nr<ql || nl>qr)){
			if(nl==nr){
				ST[ni] = value;
			}
			else{
				int mid = (nl+nr)>>1;
				updateRange__(ql,qr,nl,mid,2*ni+1);
				updateRange__(ql,qr,mid+1,nr,2*ni+2);
				ST[ni] = cmp(ST[2*ni+1],ST[2*ni+2]);
			}
		}
	}
	void updateRange(int l, int r, T value){
		updateRange__(l,r,0,size()-1,0,value);
	}
	void updateSingle(int i, T value){
		updateRange(i,i,value);
	}
};

//TEMPLATE END

//test
int main(){
	vector<ll> arr = {3,2,1,4,5,2,3};
	auto __max = [](ll& a, ll& b)->ll{return (a>b?a:b);};
	SegTree<ll,decltype(__max&)> ST(arr,__max,0);
}