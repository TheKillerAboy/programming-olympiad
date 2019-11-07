#include "testlib.h"
using namespace std;

static string input_secret = "8d9a74d5-4c4b-4437-9c49-114beaeb8f1a";

const int maxn = 2500;

int main() {
	registerValidation();
	string secret = inf.readLine();
	ensuref(secret == input_secret, "Secret not found!");

	int n = inf.readInt(1, maxn, "n");
	inf.readSpace();
	int m = inf.readInt(1, maxn, "m");
	inf.readEoln();

	for (int i = 0; i < n; i++) {
		inf.readInts(m, 0, 1, "h[" + to_string(i) + "][]");
		inf.readEoln();
	}
	inf.readEof();

	return 0;
}
