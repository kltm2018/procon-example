//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
//https://kujira16.hateblo.jp/entry/2016/12/15/000000
#include<bits/stdc++.h>
#pragma warning(disable:4996)
#ifdef _MSC_VER
#  define __builtin_popcount __builtin_popcountll
#  define __builtin_popcountll __popcnt
#endif
#define int long long
using namespace std;
using ll = long long;
using ld = long double;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
inline void my_io() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout << fixed << setprecision(10);
}
const int sqrtN = 512;
class SqrtDecomposition{
private:
	int N, K;
	vector<int> data;
	vector<int> bucketSum;
public:
	SqrtDecomposition(int n){
		N = n;
		K = (N + sqrtN - 1) / sqrtN;
		data.resize(K * sqrtN, 0);
		bucketSum.resize(K, 0);
	}
	void add(int x, int y) {
		int k = x / sqrtN;
		data[x] += y;
		int sum = 0;
		/*
		for (int i = k * sqrtN; i < (k + 1) * sqrtN; ++i) {
			sum += data[i];
		}
		*/
		bucketSum[k] +=y;
	}
	// [x, y)
	int getSum(int x, int y) {
		int sum = 0;
		for (int k = 0; k < K; ++k) {
			int l = k * sqrtN, r = (k + 1) * sqrtN;
			if (r <= x || y <= l)
				continue;
			if (x <= l && r <= y) {
				sum += bucketSum[k];
			}
			else {
				for (int i = max(x, l); i < min(y, r); ++i) {
					sum += data[i];
				}
			}
		}
		return sum;
	}
};
signed main() {
	my_io();
	int N, Q; cin >> N >> Q;
	SqrtDecomposition decomp(N);
	while (Q--) {
		int c, x, y; cin >> c >> x >> y;
		if (c == 0) {
			decomp.add(x, y);
		}
		else {
			cout << decomp.getSum(x, y + 1) << endl;
		}
	}
	return 0;
}

