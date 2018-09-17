#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}
long long multi_GCD(vector<long long>&v) {
	long long m = v[0];
	for (int i = 0; i < v.size() - 1; i++) {
		m = GCD(m, v[i + 1]);
	}
	return m;
}
signed main() {

}