#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
//#define int long long
vector<long long> sieve(long long n) {
	vector<long long> prime;
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (long long i = 2; i <= n; ++i) {
		if (is_prime[i]) {
			prime.push_back(i);
			for (long long j = 2 * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
	return prime;
}
map<ll, int> prime_factrorize(ll n, vector<int> const & primes) {
	map<ll, int> result;
	for (int p : primes) {
		if (n < p*(ll)p) break;
		while (n % p == 0) {
			result[p] += 1;
			n /= p;
		}
	}
	if (n != 1) result[n] += 1;
	return result;
}
signed main() {
}