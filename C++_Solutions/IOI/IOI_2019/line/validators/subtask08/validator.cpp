#include "testlib.h"
#include <set>
using namespace std;

const int MAXN = 100*1000;
const int MAXA = 1000*1000*1000;

int main()
{
	registerValidation();
	int n = inf.readInt(1, MAXN, "n");
	inf.readEoln();
	set <int> Xs, Ys;
	for (int i = 0; i < n; i++)
	{
		int x = inf.readInt(1, MAXA, "x_i");
		inf.readSpace();
		int y = inf.readInt(1, MAXA, "y_i");
		ensuref(Xs.find(x) == Xs.end(), "x coordinates should be unique");
		ensuref(Ys.find(y) == Ys.end(), "y coordinates should be unique");
		Xs.insert(x);
		Ys.insert(y);
		inf.readEoln();
	}
	inf.readEof();
	return 0;
}
