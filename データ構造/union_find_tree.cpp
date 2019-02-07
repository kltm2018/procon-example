#include<bits/stdc++.h>
using namespace std;
class union_find_tree {
private:
	vector<int>par, rank_;
public:
	union_find_tree(int n) :par(n), rank_(n) {
		for (int i = 0; i < n; i++) {
			par[i] = i;
			rank_[i] = 0;
		}
	}

	void unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return;
		}
		if (rank_[x] < rank_[y]) {
			par[x] = y;
		}
		else if (rank_[x] == rank_[y]) {
			par[y] = x;
			rank_[x]++;

		}
		else if (rank_[y] < rank_[x]) {
			par[y] = x;
		}
	}
	int root(int x) {
		if (par[x] == x) {
			return x;
		}
		return par[x] = root(par[x]);
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
};