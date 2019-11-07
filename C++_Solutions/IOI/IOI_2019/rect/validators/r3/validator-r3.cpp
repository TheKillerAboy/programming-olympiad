#include "testlib.h"
using namespace std;

static string input_secret = "8d9a74d5-4c4b-4437-9c49-114beaeb8f1a";

int main() {
	registerValidation();
	string secret = inf.readLine();
	ensuref(secret == input_secret, "Secret not found!");

	inf.readInt(1, 3, "n");
	skip_ok();

	return 0;
}
