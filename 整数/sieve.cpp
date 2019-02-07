#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
//#define int long long
vector<int> sieve(int n) {
	vector<int> prime;
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; ++i) {
		if (is_prime[i]) {
			prime.push_back(i);
			for (int j = 2 * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
	return prime;
}
signed main() {

}