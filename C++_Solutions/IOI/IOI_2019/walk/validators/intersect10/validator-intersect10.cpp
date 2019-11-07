#include "testlib.h"
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

const int MAXN = 100000;
const int MAXY = 1000000000;
vector<int> seg[4 * MAXN];
vector<int> h;

void build_segment(int v, int f, int e, vector<int> &h)
{
	if (e - f == 1)
	{
		seg[v].push_back(h[f]);
		return;
	}

	int mid = (f + e) / 2;
	build_segment(2 * v, f, mid, h);
	build_segment(2 * v + 1, mid, e, h);

	for (int i = 0; i < (int) seg[2 * v].size(); i++)
		seg[v].push_back(seg[2 * v][i]);

	for (int i = 0; i < (int) seg[2 * v + 1].size(); i++)
		seg[v].push_back(seg[2 * v + 1][i]);

	sort(seg[v].begin(), seg[v].end());
}

int count_more(int v, int f, int e, int l, int r, int x)
{
	if (l <= f && e <= r)
		return seg[v].end() - lower_bound(seg[v].begin(), seg[v].end(), x);
	if (f >= r || e <= l)
		return 0;

	int mid = (f + e) / 2;
	return count_more(2 * v, f, mid, l, r, x) + count_more(2 * v + 1, mid, e, l, r, x);
}

int main()
{
	registerValidation();
	inf.readLine();

	int n = inf.readInt(1, MAXN, "n");
	inf.readSpace();
	int m = inf.readInt(1, MAXN, "m");
	inf.readEoln();

	h.resize(n);

	for (int i = 0; i < n; i++)
	{
		inf.readInt(0, MAXY, "X_i");
		inf.readSpace();
		h[i] = inf.readInt(1, MAXY, "H_i");
		inf.readEoln();
	}

	build_segment(1, 0, n, h);

	for (int i = 0; i < m; i++)
	{
		int l = inf.readInt(0, n - 1, "L_i");
		inf.readSpace();
		int r = inf.readInt(0, n - 1, "R_i");
		inf.readSpace();
		int y = inf.readInt(1, min(h[l], h[r]), "Y_i");
		inf.readEoln();

		int z = count_more(1, 0, n, l, r + 1, y);
		ensuref(z <= 10, "%d to %d at height %d intersections: %d", l, r, y, z);
	}

	skip_ok();
}
