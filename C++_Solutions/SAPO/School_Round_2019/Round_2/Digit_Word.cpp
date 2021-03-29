#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> digits = {"ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

bool has_digit(string digit, string word){
	auto start = 0;
	bool pos = true;
	for(auto let : digit){
		// cout<<start<<'\n';
		if(start==-1||start==word.size()) pos = false;
		start = word.find(let,start);
		if(start!=-1)start++;
	}
	if(start==-1) pos = false;
	return pos;
}

int main(){
	string word;
	cin>>word;
	for(auto digit : digits){
		if(has_digit(digit,word)){
			cout<<digit<<endl;
			return 0;
		}
	}
	cout<<"NONE"<<endl;
	return 0;
}