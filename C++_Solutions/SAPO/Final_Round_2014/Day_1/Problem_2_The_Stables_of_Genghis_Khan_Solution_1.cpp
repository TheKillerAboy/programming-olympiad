#include <iostream>
#include <vector>

using namespace std;

class Binary{
public:
  vector<int> tree;
  Binary(){
    tree = vector<int>(0);
  }
  void add(const int& val){
    if(tree.size()==0){
      tree.push_back(val);
      return;
    }
    for(auto it = tree.begin();it!=tree.end();it++){
      if(val<*it){
        tree.insert(it,val);
        return;
      }
    }
    tree.push_back(val);
  }
  int _search(const int& val,const int& from, const int& to){
    int between = (from+to)/2;
    if(tree[between] == val){
      return 1;
    }
    if(from == to){
      return 1;
    }
    if(from>to){
      return 0;
    }
    if(val<tree[between]){
      return 1+_search(val,from,between-1);
    }
    else if(val>tree[between]){
      return 1+_search(val,between+1,to);
    }
  }
  int search(const int& val){
    return _search(val,0,tree.size()-1);
  }
  void print(){
    for(auto val:tree){
      cout<<val<<' ';
    }
    cout<<endl;
  }
};

int main(int argc, char const *argv[]) {
  Binary bin = Binary();
  int N,M;
  cin>>N;
  cin>>M;
  int t;
  for(int i = 0; i< M;i++){
    cin>>t;
    bin.add(t);
  }
  int total = 0;
  for(int i = 1; i<=N;i++){
    total += bin.search(i);
  }
  cout<<total<<endl;
  return 0;
}
/*
10
4
9
3
7
4
*/

/*
I was tempted to use a datastructure to simulate a tree structure, but
after some thinking I realized that would over complicate the problem
, instread I do a basic binary search with a sorted sequance which
yields the same results.

This is my first problem I completly solved with C++
All the problems added before this, I've used the algorithms I used in the
Python solutions.
*/
