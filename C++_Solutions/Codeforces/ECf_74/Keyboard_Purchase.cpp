int n;
string word;

string dp(int layout){
	if(__buildin_popcount(((1<<n)-1) ^ layout) == 1){
		return string('a' + __buildin_ctz(((1<<n)-1) ^ layout));
	}
	int counter = 0;
	while(layout != 0){
		counter += __buildin_ctz(layout);
		layout>>=__buildin_ctz(layout)+1;
		layout<<=1;




		counter++;
	}
}