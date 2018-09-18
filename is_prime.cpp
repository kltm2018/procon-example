#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
//#define int long long
bool is_prime(long long n) {
	for (long long i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return n != 1;
}
signed main() {
	ll n;
	cin >> n;
	if (is_prime(n)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}