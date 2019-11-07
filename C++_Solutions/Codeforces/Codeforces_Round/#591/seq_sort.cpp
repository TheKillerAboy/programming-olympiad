#include <bits/stdc++.h>

using namespace std;

vector<int> seq;
int n;

int binary_search(vector<int>& seqSorted, int l, int r, int v){
	if(seqSorted[l] == v){
		return l;
	}
	if(seqSorted[r] == v){
		return r;
	}
	if(seqSorted[(l+r)>>1] < v){
		return binary_search(seqSorted,(l+r)>>1,r,v);
	}
	return binary_search(seqSorted,l,(l+r)>>1,v);
}

int query(){
	set<int> seqSet;
	int l = seq[0],r = seq[0];
	for(int i = 0; i < n; i++){
		seqSet.insert(seq[i]);
		if(seq[i] > r){
			r = seq[i];
		}
		if(seq[i] >= l && seq[i] < r){
			l = r;
		}
	}
	vector<int> seqSorted(seqSet.begin(),seqSet.end());
	int leftIndex = binary_search(seqSorted,0,seqSorted.size()-1,l);
	int rightIndex = binary_search(seqSorted,0,seqSorted.size()-1,r);
	return leftIndex+seqSorted.size()-(rightIndex+1);
}

int main(){
	int q;
	cin>>q;
	for(int i = 0; i < q; ++i){
		cin>>n;
		seq.resize(n);
		for(int j = 0; j < n; ++j){
			cin>>seq[j];
		}
		cout<<query()<<'\n';
	}
	return 0; 
}