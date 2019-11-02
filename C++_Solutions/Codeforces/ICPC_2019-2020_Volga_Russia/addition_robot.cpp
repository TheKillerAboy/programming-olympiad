#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(ll i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(ll i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(ll i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(ll i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(ll i_=1;i_<a_;++i_)

#define _ cerr<<' ';
#define _N cerr<<'\n';
#define _T cerr<<'\t';
#define TRACEV(v_) cerr<<v_;
#define TRACEP(p_) cerr<<"("<<p_.first<<", "<<p_.second<<") ";
#define TRACECE(c_,tt_) for(auto e_:c_){tt_(e_);_;}_N;
#define TRACEC(c_) TRACECE(c_,TRACEV)
#define TRACEE(v_,tt_) tt_(v_);_N;
#define TRACE(v_) TRACEE(v_,TRACEV);
#define TRACEEP(v_) TRACEE(v_,TRACEP);
#define TRACEM(m_) cerr<<"| "<<m_[0]<<' '<<m_[1]<<" |\n| "<<m_[2]<<' '<<m_[3]<<" |\n";

#define ll long long int
#define ull unsigned long long int

typedef array<ll,4> Matrix;

#define MATRIX_A Matrix{1,0,1,1}
#define MATRIX_B Matrix{1,1,0,1}
#define MATRIX_I Matrix{1,0,0,1}
#define MOD 1000000007

inline ll mul(ll a, ll b){
	return (a*b) % MOD;
}
inline ll add(ll a, ll b){
	return (a+b)%MOD;
}

inline Matrix matrixMul(Matrix A, Matrix B){
	return {add(mul(A[0],B[0]), mul(A[1],B[2])),add(mul(A[0],B[1]), mul(A[1],B[3])),add(mul(A[2],B[0]), mul(A[3],B[2])),add(mul(A[2],B[1]), mul(A[3],B[3]))};
}

inline Matrix matrixT(Matrix A){
	return {A[0],A[2],A[1],A[3]};
}

vector<Matrix> ST;
vector<Matrix> arr;
ll N;

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
	SegTree(vector<T>& arr, CMP cmp_, T default_ = 0){
		ST.resize((1<<((int)ceil(log2(arr.size()))+1))-1);
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
	template <typename K>
	void updateRange__(int ql, int qr, int nl, int nr, int ni, K value){
		if(!(nr<ql || nl>qr)){
			if(nl==nr){
				ST[ni] = value(ST[ni]);
			}
			else{
				int mid = (nl+nr)>>1;
				updateRange__(ql,qr,nl,mid,2*ni+1,value);
				updateRange__(ql,qr,mid+1,nr,2*ni+2,value);
				ST[ni] = cmp(ST[2*ni+1],ST[2*ni+2]);
			}
		}
	}
	template <typename K>
	void updateRange(int l, int r, K value){
		updateRange__(l,r,0,size()-1,0,value);
	}
	void updateSingle(int i, T value){
		updateRange(i,i,value);
	}
};

//TEMPLATE END

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll Q;
	cin>>N>>Q;
	arr.resize(N);
	string line;
	cin>>line;
	FOR(i,N){
		if(line[i] == 'A') arr[i] = MATRIX_A;
		else arr[i] = MATRIX_B;
	}
	SegTree<Matrix,decltype(&matrixMul)> ST(arr,matrixMul,MATRIX_I);
	ll t,l,r,a,b;
	FOR(i,Q){
		cin>>t;
		if(t==1){
			cin>>l>>r;
			ST.updateRange(l-1,r-1,matrixT);
		}
		else{
			cin>>l>>r>>a>>b;
			Matrix AB = Matrix{a,b,0,0};
			Matrix segment = ST.query(l-1,r-1);
			Matrix ABNew = matrixMul(AB,segment);
			cout<<ABNew[0]<<' '<<ABNew[1]<<'\n';
		}
	}


	return 0;
}