#include <iostream>
#include <tuple>
#include <string>
#include <map>

using namespace std;

enum Operators{
	AND,OR,NOT,VALUE
};

struct Expression{
	char value;
	Expression* left;
	Expression* right;
	Operators Operator;

	Expression(){;
	}

	void setAsValue(char valueRef){
		value = valueRef;
		Operator = VALUE;
	}

	void setAsExpression(Expression* left_, Expression* right_,Operators op){
		left = left_;
		right = right_;
		Operator = op;
	}

	bool eval(map<char,bool>& refrence){
		switch(Operator){
			case AND:
				return left->eval(refrence) && right->eval(refrence);
			case OR:
				return left->eval(refrence) || right->eval(refrence);
			case NOT:
				return !right->eval(refrence);
			case VALUE:
				return refrence[value];
		}
	}
};

string deroll(string exp){
	if(exp[0] == '('){
		int counter = 1;
		bool isExp = true;
		for(size_t i = 1; i < exp.length()-1;i++){
			if(exp[i] == '('){
				counter++;
			}
			else if(exp[i] == ')'){
				counter --;
			}
			if(counter <= 0){
				isExp = false;
				break;
			}
		}
		if(isExp){
			return exp.substr(1,exp.length()-2);
		}
	}
	return exp;
}

tuple<string,string,Operators> splitExp(string exp){
	exp = deroll(exp);
	int counter = 0;
	for(size_t i = 0; i < exp.length(); i++){
		if(exp[i] == '('){
			counter++;
		}
		else if(exp[i] == ')'){
			counter --;
		}
		else if(counter == 0){
			switch(exp[i]){
				case '!':
					return {exp.substr(0,i),exp.substr(i+1),NOT};
				case '.':
					return {exp.substr(0,i),exp.substr(i+1),AND};
				case '+':
					return {exp.substr(0,i),exp.substr(i+1),OR};
			}
		}
	}
	return {exp,"",VALUE};		
}

void createExpression(Expression* root, string exp){
	if(exp.length() == 0){
		return;
	}
	string leftSide, rightSide;
	Operators Operator;
	tie(leftSide,rightSide, Operator) = splitExp(exp);
	if(Operator == VALUE){
		root -> setAsValue(leftSide[0]);
	}
	else{
		root->setAsExpression(new Expression(),new Expression(),Operator);
		createExpression(root->left,leftSide);
		createExpression(root->right,rightSide);
	}
}

int main(){
	int var;
	map<char,bool> mappedBool;
	cin>>var;
	string cur;
	for(int i = 0; i < var; i++){
		cin>>cur;
		mappedBool[cur[0]] = false;
	}
	string expression;
	cin>>expression;
	Expression* root = new Expression();
	createExpression(root,expression);
	unsigned int evals = 0;
	while(!root->eval(mappedBool)){
		evals++;
		unsigned int evalChange = evals;
		for(auto it = mappedBool.begin(); it!=mappedBool.end();it++){
			(*it).second = evalChange - ((evalChange>>1)<<1);
			evalChange = evalChange>>1;
		}
	}
	for(auto keyValue : mappedBool){
		cout<<keyValue.first<<' '<<(keyValue.second ? "true" : "false")<<endl;
	}

	return 0;
}