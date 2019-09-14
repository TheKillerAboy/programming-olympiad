#include <vector>
#include <cmath>
#include <iostream>

using namespace std;


void fillSegmentTree2D(vector<int>&st, vector<vector<int>>& input, int nrl, int ncl, int nrr, int ncr,int ni){
  if(nrl<=nrr && ncl <= ncr){
    if(nrl == nrr && ncl == ncr){
      st[ni] = input[nrl][ncl];
    }
    else{
      int midr = (nrl+nrr)>>1;
      int midc = (ncl+ncr)>>1;

      fillSegmentTree2D(st,input,nrl,ncl,midr,midc,4*ni+1);
      fillSegmentTree2D(st,input,nrl,midc+1,midr,ncr,4*ni+2);
      fillSegmentTree2D(st,input,midr+1,ncl,nrr,midc,4*ni+3);
      fillSegmentTree2D(st,input,midr+1,midc+1,nrr,ncr,4*ni+4);

      st[ni] = st[4*ni+1]+st[4*ni+2]+st[4*ni+3]+st[4*ni+4];
    }
  }
}

int getSum(vector<int>& st, int qrl, int qcl, int qrr, int qcr, int nrl, int ncl, int nrr, int ncr, int ni){
  if(qrl<=nrl && nrr <= qrr && qcl<=ncl && ncr <= qcr){
    return st[ni];
  }
  else if(qrl>nrr || nrl>qrr || qcl>ncr || ncl>qcr || ncr < ncl || nrr < nrl){
    return 0;
  }
  else{
    int midr = (nrl+nrr)>>1;
    int midc = (ncl+ncr)>>1;

    /*
    3 3
    1 1 -4
    4 -1 3
    -1 3 0
    */

    int out =  getSum(st,qrl,qcl,qrr,qcr,nrl,ncl,midr,midc,4*ni+1)+
    getSum(st,qrl,qcl,qrr,qcr,nrl,midc+1,midr,ncr,4*ni+2)+
    getSum(st,qrl,qcl,qrr,qcr,midr+1,ncl,nrr,midc,4*ni+3)+
    getSum(st,qrl,qcl,qrr,qcr,midr+1,midc+1,nrr,ncr,4*ni+4);
    return out;
  }
}

vector<int> constructST2D(int n, int m, vector<vector<int>>& input){
  vector<int> st(((int)pow(4,ceil(log2(n*m)/2)+1)-1)/3);
  fillSegmentTree2D(st,input,0,0,n-1,m-1,0);

  return st;
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> input(n);
  for(int i = 0; i < n;i++){
    input[i] = vector<int>(m);
    for(int j = 0; j < m; j++){
      cin>>input[i][j];
    }
  }
  vector<int> st = constructST2D(n,m,input);
  int MAX = 0;
  for(int sizer = 1; sizer <= n; sizer++){
    for(int sizec = 1; sizec <= m; sizec++){
      for(int r = 0; r <= n - sizer; r++){
        for(int c = 0; c <= m - sizec; c++){
          MAX = max(MAX,getSum(st,r,c,r+sizer-1,c+sizec-1,0,0,n-1,m-1,0));
        }
      }
    }
  }
  cout<<MAX<<endl;
  return 0;
}
