#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int

//TEMPLATE START

struct MINT
{
	size_t value;
	template<typename T> MINT(T v){value = v;if(v >= MOD) value = v % MOD;if(v < 0){while(v < 0) v+=MOD;value = v;}}
	MINT(): value(0){}
	MINT(const MINT& o):MINT(o.value){}
	template<typename T> MINT operator + (T o){return MINT(MINT(o).value + value);}
	template<typename T> MINT operator - (T o){return MINT(MINT(o).value - value);}
	template<typename T> MINT operator * (T o){return MINT(MINT(o).value * value);}
	template<typename T> bool operator ==(T o){return MINT(o).value == value;}
	template<typename T1, typename T2> static MINT pow(T1 a, T2 b){MINT A(a),B(b);if(B == 0) return MINT(1);
		if(B == 1) return A;MINT temp = pow(A,B.value/2);return temp * temp * (B.value%2?A:MINT(1));}
	template<typename T> MINT operator ^ (T o){return pow(value,MINT(o%(MOD-1)));}
	template<typename T> void operator += (T o){value = (MINT(o) + value).value;}
	template<typename T> void operator -= (T o){value = (MINT(value) - o).value;}
	template<typename T> void operator *= (T o){value = (MINT(value)*o).value;}
	template<typename T> void operator ^= (T o){value = (MINT(value)^o).value;}
	template<typename T> MINT operator / (T o){return (MINT(o)^(MOD-2))*value;}
	template<typename T> void operator /= (T o){value = (MINT(value)/o).value;}
	template<typename T> void operator = (T o){value = MINT(o).value;}
};
ostream& operator<<(ostream &os, const MINT &v){os << v.value;return os;}

// TEMPLATE END

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	MINT o = MINT(2)^(MOD);
	cout<<o;

	return 0;
}