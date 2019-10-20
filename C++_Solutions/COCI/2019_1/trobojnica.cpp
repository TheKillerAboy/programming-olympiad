#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define ll long long int
#define ull unsigned long long int
 
string diff(char a, char b){
    set<char> all = {'1','2','3'};
    all.erase(all.find(a));
    all.erase(all.find(b));
    return string(1,*all.begin());
}
 
bool dp(string pg){
    if(pg.size()==3){
        if(pg[0] != pg[1] && pg[1] != pg[2] && pg[0] != pg[2]){
            return true;
        }
        return false;
    }
    bool out = false;
    FOR(i,pg.size()-1){
        if(pg[i] != pg[i+1]){
            out = out | dp(pg.substr(0,i)+diff(pg[i],pg[i+1])+pg.substr(i+2));
        }
        if(out){
            break;
        }
    }
    return out;
}
 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    string line;
    cin>>line;
    bool out = dp(line);
    cout<<(out?"DA":"NE")<<'\n';
 
    return 0;
}