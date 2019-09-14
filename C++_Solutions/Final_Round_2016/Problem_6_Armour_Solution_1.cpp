#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void fillSegmentTree(long long int* st, long long int* arr, int nl, int nr, int ni){
  if(nl<nr){
    int mid = (nl+nr)>>1;
    fillSegmentTree(st,arr,nl,mid,2*ni+1);
    fillSegmentTree(st,arr,mid+1,nr,2*ni+2);

    st[ni] = st[2*ni+1]+st[2*ni+2];
  }else if(nl==nr){
    st[ni] = arr[nl];
  }
}

long long int* constructSegmentTree(long long int* arr, int n){
  long long int* st = new long long int[(int)pow(2,ceil(log2(n))+1)-1];

  fillSegmentTree(st,arr,0,n-1,0);

  return st;
}

long long int sumInRange(long long int* st, int ql, int qr, int nl, int nr, int ni){
  if(ql<=nl && nr<= qr){
    return st[ni];
  }
  else if(nl>qr || nr<ql){
    return 0;
  }
  else{
    int mid = (nl+nr)>>1;
    return sumInRange(st,ql,qr,nl,mid,2*ni+1)+sumInRange(st,ql,qr,mid+1,nr,2*ni+2);
  }
}

pair<long long int,int> maxSumWithRange(long long int* st, int n, int size){
  pair<long long int,int> maxV = {0,0};
  for(int i = 0; i < n - size + 1; i++){
    long long int range = sumInRange(st,i,i+size-1,0,n-1,0);
    if(maxV.first < range){
      maxV.first = range;
      maxV.second = i;
    }
  }
  return maxV;
}

int main(){
  int n,t,i,curSize;
  cin>>n>>t;
  long long int arr[n];
  for(i = 0; i < n; i++){
    cin>>arr[i];
  }
  long long int* st = constructSegmentTree(arr,n);
  vector<pair<long long int,int>> out(t);
  for(i = 0; i < t; i++){
    cin>>curSize;
    out[i] = maxSumWithRange(st,n,curSize);
  }
  for(i = 0; i < t; i++){
    printf("%i %i\n", out[i].second+1,out[i].first);
  }
}
