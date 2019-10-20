#include <bits/stdc++.h>

using namespace std;

struct DictNode{
	map<char,DictNode*> children;
	int total, total_lower, lower_value;

	DictNode(){
		total = 0;
		total_lower = 0;
		lower_value = 0;
	}

	void addWord(const char* word){
		++total;
		++total_lower;
		if(word[0] == '\0'){
			return;
		}
		if(children.find(word[0]) == children.end()){
			children[word[0]] = new DictNode();
		}
		children[word[0]]->addWord(word+1);
	}

	void nextWord(string& word){
		for(auto child : children){
			if(child.second->lower_value == lower_value){
				word+=child.first;
				child.second->nextWord(word);
				break;
			}
		}
		--total_lower;
		if(total_lower == 0){
			++lower_value;
			total_lower = total;
		}
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int D,Q;
	DictNode* root = new DictNode();
	cin>>D>>Q;
	string line;
	for(int i = 0; i < D; ++i){
		cin>>line;
		root->addWord(line.c_str());
	}
	char let;
	for(int i = 0; i < Q; ++i){
		cin>>let;
		line.clear();
		line+=let;
		root->children[let]->nextWord(line);
		cout<<line<<endl;
	}

	return 0;
}