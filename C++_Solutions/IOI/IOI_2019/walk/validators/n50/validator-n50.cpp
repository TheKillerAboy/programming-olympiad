#include "testlib.h"

const int MAXN = 50;
int main()
{
	registerValidation();
	inf.readLine();
	inf.readInt(1, MAXN, "n");
	inf.readSpace();
	inf.readInt(1, MAXN, "m");
	skip_ok();
}
