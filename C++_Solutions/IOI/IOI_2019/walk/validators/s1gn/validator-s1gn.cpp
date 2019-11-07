#include "testlib.h"

int main()
{
	registerValidation();
	inf.readLine();
	int n = inf.readInt();
	inf.readSpace();
	int m = inf.readInt();
	inf.readEoln();
	inf.readLines(n + m);

	inf.readInt(0, 0, "S");
	inf.readSpace();
	inf.readInt(n - 1, n - 1, "G");
	inf.readEoln();
	inf.readEof();
	
	return 0;
}
