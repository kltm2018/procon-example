#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
bool used[1000];
int perm[1000];
void permutation1(int pos, int n) {
	if (pos == n) {
		for (int i = 0; i < n; i++) {
			cout << perm[i];
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			perm[pos] = i;
			used[i] = true;
			permutation1(pos + 1, n);
			used[i] = false;
		}
	}
	return;
}
int main() {
	permutation1(0, 3);
	
}
