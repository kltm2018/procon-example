#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
//#define int long long
long long mod_pow(long long x, long long n, long long mod) {//x‚Ìnæ
	long long res = 1;
	while (n > 0) {
		if (n & 1) {
			res = res * x%mod;
		}
		x = x * x%mod;
		n >>= 1;
	}
	return res;
}
signed main() {
}