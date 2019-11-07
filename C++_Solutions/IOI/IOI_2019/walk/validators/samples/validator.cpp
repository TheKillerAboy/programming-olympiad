#include "testlib.h"

#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

const int MAXN = 100000;
const int MAXY = 1000000000;

typedef pair<int, int> pii;

int h[MAXN], x[MAXN];
vector<pii> walkList;
unordered_map<int, vector<pii>> walkMap;
set<int> heights;

int main()
{
	registerValidation();
	string secret = inf.readLine();
	ensuref(secret == (string)"447adec2-e0e7-4579-a2da-fed58fa3393e", "Secret not found!");
	int n = inf.readInt(1, MAXN, "n");
	inf.readSpace();
	int m = inf.readInt(1, MAXN, "m");
	inf.readEoln();
	
	for (int i = 0; i < n; i++)
	{
		x[i] = inf.readInt(i == 0 ? 0 : x[i-1] + 1, MAXY, "X_i");
		inf.readSpace();
		h[i] = inf.readInt(1, MAXY, "H_i");
		inf.readEoln();
	}

	for (int i = 0; i < m; i++)
	{
		int l = inf.readInt(0, n - 2, "L_i");
		inf.readSpace();
		int r = inf.readInt(l+1, n - 1, "R_i");
		inf.readSpace();
		int y = inf.readInt(1, min(h[l], h[r]), "Y_i");
		inf.readEoln();

		walkList.emplace_back(pii(l, r));
		walkMap[y].emplace_back(pii(l, r));
		heights.insert(y);
	}

	int s = inf.readInt(0, n - 1, "S");
	inf.readSpace();
	int g = inf.readInt(0, n - 1, "G");
	inf.readEoln();
	ensuref(s != g, "start and destination are the same");

	inf.readEof();

	// check if there exists a path from S to G

	int l = -1, r = -1;
	if (s > g) 
		swap(s, g);

	sort(walkList.begin(), walkList.end());
	for (auto &w: walkList)
	{
		if (w.first <= s && w.second >= s) 
		{
			l = w.first;
			r = w.second;
		}
		else if (l >= -1) 
		{
			if (w.first <= r) 
				r = max(r, w.second);
		}
	}

	cerr << l << " " << r << endl;
//	ensuref(l <= s && g <= r, "There is no path from %d to %d", s, g);

	// check if skywalks collide

	for (int h: heights) 
	{
		auto &walks = walkMap[h];
		sort(walks.begin(), walks.end());
		for (int i = 1; i < (int) walks.size(); i++) 
		{
			ensuref(walks[i - 1].second <= walks[i].first, "Skywalks %d:%d and %d:%d collide at height %d", 
					walks[i - 1].first, walks[i - 1].second, walks[i].first, walks[i].second, h);
		}
	}

	return 0;
}
