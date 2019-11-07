#include <cmath>
#include <iostream>
#include <utility>
#include <algorithm>

#define ll long long int

using namespace std;

void fillSegmentTree(ll* st, int* arr, int nl, int nr, int ni){
  if(nl < nr){
    int mid = (nl+nr)>>1;
    fillSegmentTree(st,arr,nl,mid,2*ni+1);
    fillSegmentTree(st,arr,mid+1,nr,2*ni+2);

    st[ni] = st[2*ni+1] + st[2*ni+2];
  }
  else if(nl == nr){
    st[ni] = arr[nl];
  }
}

ll* constructSegmentTree(int* arr, int n){
  ll* st = new ll[(int)pow(2,ceil(log2(n))+1)-1];
  fillSegmentTree(st,arr,0,n-1,0);
  return st;
}

ll getSum(ll* st, int ql, int qr, int nl, int nr, int ni){
  if(ql<=nl && nr<=qr){
    return st[ni];
  }
  else if(nl>qr || nr<ql){
    return 0;
  }
  else{
    int mid = (nl+nr)>>1;
    return getSum(st,ql,qr,nl,mid,2*ni+1)+getSum(st,ql,qr,mid+1,nr,2*ni+2);
  }
}

pair<ll,int> getMaxWithRange(ll* st, int rang, int n, int nl, int nr, int ni){
  if(nr-nl+1 > rang){
    int mid = (nl+nr)>>1;
    pair<ll,int> out = max(getMaxWithRange(st,rang,n,nl,mid,2*ni+1),getMaxWithRange(st,rang,n,mid+1,nr,2*ni+2));
    for(int i = mid - rang + 2; i < mid + 1; i++){
      out = max(out,pair<ll,int>{getSum(st,i,i+rang-1,0,n-1,0),n-i});
    }
    return out;
  }
  else if(nr-nl+1 == rang){
    return pair<ll,int>{st[ni],n-nl};
  }
  return {-1,0};
}

int main(){
  int N,T;
  cin>>N>>T;
  int arr[N];
  for(int i = 0; i < N; i++){
    cin>>arr[i];
  }
  ll* st = constructSegmentTree(arr,N);
  int q;
  for(int i = 0; i < T; i++){
    cin>>q;
    pair<ll,int> out = getMaxWithRange(st,q,N,0,N-1,0);
    cout<<N-out.second + 1<<' '<<out.first<<endl;
  }
}