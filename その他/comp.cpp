#include<bits/stdc++.h>
#pragma warning(disable:4996)
#ifdef _MSC_VER
#  define __builtin_popcount __popcnt
#endif
#define int long long
using namespace std;
using ll = long long;
using ld = long double;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const long double PI = acos(-1.0);
inline void my_io() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cout << fixed << setprecision(15);
}
bool my_comp(const vector<int>& firstElof, vector<int>& secondElof){
	return secondElof[2]<firstElof[2];
}
signed main() {
	my_io();
}
