#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
//#define int long long
vector<long long>divisor(long long n) {
	vector<long long >res;
	for (long long i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			res.push_back(i);
			if (i != n / i) {
				res.push_back(n / i);
			}
		}
	}
	return res;
}
signed main() {

}