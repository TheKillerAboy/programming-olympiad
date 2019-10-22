/*
ID: annekin1
TASK: namenum
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

#define DICTLEN 4617

int main(){
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");
	ifstream fdict("dict.txt");
	unordered_set<string> dict;
	string line,nickname;
	fin>>nickname;
	dict.insert("");
	FOR(i,DICTLEN){
		fdict>>line;
		if(line.size()==nickname.size()){
			FORI(l,line.size()){
				dict.insert(line.substr(0,l));
			}
		}
	}
	list<string> words = {""};
	map<char,string> lookup = {
		{'2',"ABC"},
		{'3',"DEF"},
		{'4',"GHI"},
		{'5',"JKL"},
		{'6',"MNO"},
		{'7',"PRS"},
		{'8',"TUV"},
		{'9',"WXY"}
	};
	string word;
	int oriSize;
	FOR(i,nickname.size()){
		oriSize = words.size();
		FOR(j,oriSize){
			word = words.front();
			words.pop_front();
			if(dict.find(word) != dict.end()){
				FORA(let,lookup[nickname[i]]){
					words.push_back(word+string(1,let));
				}
			}
		}
	}
	bool found = false;
	FORA(word,words){
		if(dict.find(word) != dict.end()){
			found = true;
			fout<<word<<'\n';
		}
	}
	if(!found){
		fout<<"NONE"<<'\n';
	}

	return 0;
}