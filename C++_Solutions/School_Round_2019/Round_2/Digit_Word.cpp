#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> digits = {"ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

bool has_digit(string digit, string word){
	if(digit.length() == 0){
		return true;
	}
	if(word.find(digit[0]) != string::npos){
		return has_digit(digit.substr(1),word.substr(word.find(digit[0])+1));
	}
	return false;
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