#include <bits/stdc++.h>

using namespace std;


struct DictNode{
	map<char,DictNode*> children;
	set<int> origin;

	void addWord(const char* word, int index){
		if(word[0] == '\0'){
			origin.insert(index);
			return;
		}
		if(children.find(word[0]) == children.end()){
			children[word[0]] = new DictNode();
		}
		children[word[0]]->addWord(word+1,index);
	}

	void fillWords(const char* word, set<int>& fill){
		for(int value: origin){
			fill.insert(value);
		}
		if(word[0] == '\0'){
			return;
		}
		if(children.find(word[0]) != children.end()){
			children[word[0]]->fillWords(word+1,fill);
		}
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	DictNode* root = new DictNode();
	int N;
	cin>>N;
	vector<string> words(N);
	for(int i = 0; i < N; ++i){
		cin>>words[i];
		const char* line_C = words[i].c_str();
		root->addWord(line_C,i);
	}
	int out = 0;
	for(string line : words){
		set<int> fill;
		const char* line_C = line.c_str();
		for(int i = 0; i < line.length(); ++i){
			root->fillWords(line_C+i,fill);
		}
		out += fill.size()-1;
	}
	cout<<out;
	return 0;
}