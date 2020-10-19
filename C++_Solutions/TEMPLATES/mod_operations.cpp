#define MOD ((int)1e9+7)

int add(int a_, int b_){
	long long int a=(long long int)a_,b=(long long int)b_;
	return (a+b)%MOD;
}
int neg(int a_, int b_){
	long long int a=(long long int)a_,b=(long long int)b_;
	return (a-b)%MOD;
}
int mul(int a_, int b_){
	long long int a=(long long int)a_,b=(long long int)b_;
	return (a*b)%MOD;
}
int power(int a, int n){
	if(n==0)return 1;
	if(n==1)return a;
	int temp = power(a,n/2);
	return mul(temp,mul(temp,n%2==1?a:1));
}
int divide(int a, int b){
	int b_inv = power(b,MOD-2);
	return mul(a,b_inv);
}