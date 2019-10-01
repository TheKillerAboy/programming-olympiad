vector<int> shoes;

map<int,int> indexsS;
vector<int> indexs(shoes.size());
vector<int,int> 

int cur = 0;

for(int i = 0; i < shoes.size(); i++){
	if(indexsS.find(abs(shoes[i])) == indexsS.end()){
		indexsS[abs(shoes[i])] = cur;
		indexs[i] = cur++;
	}
	else{
		indexs[i] = indexsS[abs(shoes[i])];
		indexsS.erase(abs(shoes[i]));
	}
}

swap(vector<int>& arr, int a, int b){
	arr[a] = arr[a]^arr[b];
	arr[b] = arr[a]^arr[b];
	arr[a] = arr[a]^arr[b];
}

int cur = 0;
int swaps = 0;
for(cur < shoes.size() - 1){
	if(indexs[cur] > indexs[cur+1]){
		swaps++;
		swap(indexs,cur,cur+1);
		swap(shoes,cur,cur+1);
		cur--;
	}
}

for(int i = 0; i < shoes.size()/2; i++){
	if(shoes[i]>shoes[i+1]){
		swaps++;
	}
}