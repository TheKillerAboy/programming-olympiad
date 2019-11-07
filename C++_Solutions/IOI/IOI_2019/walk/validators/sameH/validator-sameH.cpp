#include "testlib.h"

using namespace std;

const int MAXN = 100000;
const int MAXY = 1000000000;

int h;

int main()
{
	registerValidation();
	inf.readLine();
	int n = inf.readInt(1, MAXN, "n");
	inf.readSpace();
	int m = inf.readInt(1, MAXN, "m");
	inf.readEoln();
	
	for (int i = 0; i < n; i++)
	{
		inf.readInt();
		inf.readSpace();

		if (i == 0) 
			h = inf.readInt(1, MAXY, "H_i");
		else
			inf.readInt(h, h, "H_i");
		
		inf.readEoln();
	}

	inf.readLines(m);

	inf.readInt(0, 0, "S");
	inf.readSpace();
	inf.readInt(n - 1, n - 1, "G");
	inf.readEoln();
	inf.readEof();

	return 0;
}
