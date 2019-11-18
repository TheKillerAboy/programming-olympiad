#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define NINF LLONG_MIN

//TEMPLATE START

template<typename T, typename CMP, bool indexed = false>
struct SegTree{
	vector<T> ST;
	vector<T>* ARR;
	CMP cmp;
	size_t size__;
	T DEFAULT;
	size_t size(){
		return size__;
	}
	template<typename I1, typename I2>
	inline T cmpIndexed(I1 l, I2 r){
		if(l==-1)return r;
		if(r==-1)return l;
		if(cmp((*ARR)[l],(*ARR)[r]) == (*ARR)[l]) return l;
		return r;
	}
	template<typename I1, typename I2, typename I3>
	void fill(vector<T>& arr, I1 nl, I2 nr, I3 ni){
		if(nl<nr){
			size_t mid = (nl+nr)>>1;
			fill(arr,nl,mid,2*ni+1);
			fill(arr,mid+1,nr,2*ni+2);
			if(indexed) ST[ni] = cmpIndexed(2*ni+1,2*ni+2);
			else ST[ni] = cmp(ST[2*ni+1],ST[2*ni+2]);
		}	
		else if(nl==nr){
			ST[ni] = arr[nl];
		}
	}
	SegTree(vector<T>& arr, CMP cmp_, T default_ = 0){
		ST.resize((1<<((int)ceil(log2(arr.size()))+1))-1);
		cmp = cmp_;
		size__ = arr.size();
		ARR = &arr;
		DEFAULT = default_;
		fill(arr,0,size()-1,0);
	}
	template<typename I1, typename I2, typename I3, typename I4, typename I5>
	T query__(I1 ql, I2 qr, I3 nl, I4 nr, I5 ni){
		if(ql<=nl && nr<= qr){
			return indexed?nl:ST[ni];
		}
		else if(nr<ql || nl>qr){
			return indexed?-1:DEFAULT;
		}
		else{
			size_t mid = (nl+nr)>>1;
			return indexed?cmpIndexed(query__(ql,qr,nl,mid,2*ni+1),query__(ql,qr,mid+1,nr,2*ni+2)):cmp(query__(ql,qr,nl,mid,2*ni+1),query__(ql,qr,mid+1,nr,2*ni+2));
		}
	}
	template<typename I1, typename I2>
	T query(I1 l, I2 r){
		return query__(l,r,0,size()-1,0);
	}
	template <typename K,typename I1, typename I2, typename I3, typename I4, typename I5>
	void updateRange__(I1 ql, I2 qr, I3 nl, I4 nr, I5 ni, K value){
		if(!(nr<ql || nl>qr)){
			if(nl==nr){
				ST[ni] = value(ST[ni]);
			}
			else{
				size_t mid = (nl+nr)>>1;
				updateRange__(ql,qr,nl,mid,2*ni+1,value);
				updateRange__(ql,qr,mid+1,nr,2*ni+2,value);
				ST[ni] = cmp(ST[2*ni+1],ST[2*ni+2]);
			}
		}
	}
	template <typename K,typename I1, typename I2>
	void updateRange(I1 l, I2 r, K value){
		updateRange__(l,r,0,size()-1,0,value);
	}
	template <typename I1, typename I2>
	void updateRange(I1 l, I2 r, T value){
		updateRange__(l,r,0,size()-1,0,[&](auto A){return value;});
	}
	template <typename I2>
	void updateSingle(I2 i, T value){
		updateRange(i,i,value);
	}
};
//ERROR MODULE EXT
template<typename T, typename CMP, bool indexed>
ostream& operator<<(ostream &os, const SegTree<T,CMP,indexed> &v){
	TRACEV(*v.ARR);
	return os;
}
//ERROR MODULE EXT
//TEMPLATE END
template<typename T>
inline T max__(T a, T b){return max(a,b);}

//test
int main(){
	vector<ll> arr = {3,2,1,4,5,2,3};
	auto ST = SegTree<ll,decltype(&max__<ll>),false>(arr,max__<ll>,NINF);
	ST.updateRange(0,4,(ll)3);
	cout<<ST.query(0,4);
}