/*
ID: annekin1
TASK: transform
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define ll long long int
#define ull unsigned long long int

int N;
vector<vector<bool>> ori;
vector<vector<bool>> need;

vector<vector<bool>> rotate90(vector<vector<bool>> a){
	vector<vector<bool>> out(N,vector<bool>(N));
	FORR(j,N){
		FOR(i,N){
			out[i][N-1-j] = a[j][i];
		}
	}
	return out;
}

vector<vector<bool>> reflect(vector<vector<bool>> a){
	vector<vector<bool>> out(N,vector<bool>(N));
	FOR(i,N){
		FOR(j,N){
			out[i][N-1-j] = a[i][j];
		}
	}
	return out;
}

void print(vector<vector<bool>> a){
	FOR(i,N){
		FOR(j,N){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
}

int main(){
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	fin>>N;
	ori.resize(N,vector<bool>(N));
	need.resize(N,vector<bool>(N));
	string line;
	FOR(i,N){
		fin>>line;
		FOR(j,N){
			ori[i][j] = line[j] == '@';
		}
	}
	FOR(i,N){
		fin>>line;
		FOR(j,N){
			need[i][j] = line[j] == '@';
		}
	}
	vector<vector<bool>> alter = rotate90(ori);
	if(alter == need){
		fout<<1<<'\n';
	return 0;
	}
	alter = rotate90(alter);
	if(alter == need){
		fout<<2<<'\n';
	return 0;
	}
	alter = rotate90(alter);
	if(alter == need){
		fout<<3<<'\n';
	return 0;
	}
	alter = reflect(ori);
	if(alter == need){
		fout<<4<<'\n';
	return 0;
	}
	alter = rotate90(alter);
	if(alter == need){
		fout<<5<<'\n';
	return 0;
	}
	alter = rotate90(alter);
	if(alter == need){
		fout<<5<<'\n';
	return 0;
	}
	alter = rotate90(alter);
	if(alter == need){
		fout<<5<<'\n';
	return 0;
	}
	if(ori == need){
		fout<<6<<'\n';
	return 0;
	}
	fout<<7<<'\n';

	return 0;
}