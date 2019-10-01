#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> arr;
vector<pair<int,int>> st;//value,index

int getArr(int i){
	if(i>=N || i < 0){
		return 0;
	}
	return arr[i];
}

int detonates = 0;

void fillSegmentTree(int nl, int nr, int ni){
	if(nl<nr){
		int mid = (nl+nr)>>1;
		fillSegmentTree(nl,mid,2*ni+1);
		fillSegmentTree(mid+1,nr,2*ni+2);
		st[ni] = max(st[2*ni+1],st[2*ni+2]);
	}
	else if(nl==nr){
		st[ni] = {arr[nl],nl};
	}
}

pair<int,int> getMax(int ql, int qr, int nl, int nr, int ni){
	if(ql<=nl && nr<=qr){
		return st[ni];
	}
	else if(nr<ql || qr<nl){
		return {0,-1};
	}
	else{
		int mid = (nl+nr)>>1;
		return max(getMax(ql,qr,nl,mid,2*ni+1),getMax(ql,qr,mid+1,nr,2*ni+2));
	}
}

void updateRange(int nl, int nr, int ni, int ql, int qr, int qv){
	if(nl == nr && ql<=nl && nr<= qr){
		st[ni] = {qv,nl};
	}
	else if(!(nr<ql || qr<nl)){
		int mid = (nl+nr)>>1;
		updateRange(nl,mid,2*ni+1,ql,qr,qv);
		updateRange(mid+1,nr,2*ni+2,ql,qr,qv);
		st[ni] = max(st[2*ni+1],st[2*ni+2]);
	}
}

int getOther(int l, int r){
	
}

void detonate(int i){
	if(getArr(i+1) < getArr(i) && getArr(i-1) < getArr(i)){
		detonates += arr[i] - max(getArr(i+1),getArr(i-1));
		arr[i] = max(getArr(i+1),getArr(i-1));
		updateRange(0,N-1,0,i,i,arr[i]);
	}
	else{
		int l = i,r = i;
		for(int j = i-1; j>=0;j--){
			if(arr[j] != arr[i]){
				break;
			}
			else{
				arr[j]--;
				l = j;
			}
		}
		for(int j = i+1; j<N;j++){
			if(arr[j] != arr[i]){
				break;
			}
			else{
				arr[j]--;
				r = j;
			}
		}
		arr[i]--;
		detonates++;
		updateRange(0,N-1,0,l,r,arr[i]);
	}
}

int main(){
	cin>>N;
	arr.resize(N);
	for(int i = 0; i < N; i++){
		cin>>arr[i];
	}
	st.resize((1<<((int)ceil(log2(N))+1))-1);
	fillSegmentTree(0,N-1,0);
	pair<int,int> MAX = getMax(0,N-1,0,N-1,0);
	while(MAX.first > 0){
		detonate(MAX.second);
		MAX = getMax(0,N-1,0,N-1,0);
	}
	cout<<detonates<<endl;
	return 0;
}