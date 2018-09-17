#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
//#define int long long
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}
long long LCM(long long a, long long b) {
	long long g = GCD(a, b);
	return a / g * b;
}
long long multi_LCM(vector<long long>&v) {
	long long res = v[0];
	for (int i = 0; i < v.size() - 1; i++) {
		res = LCM(res, v[i + 1]);
	}
	return res;
}
signed main() {
	int N;
	cin >> N;
	vector<ll>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	cout << multi_LCM(v) << endl;
}