#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
using ll = long long;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
//#define int long long
// •Ô‚è’l: a ‚Æ b ‚ÌÅ‘åŒö–ñ”
// ax + by = gcd(a, b) ‚ğ–‚½‚· (x, y) ‚ªŠi”[‚³‚ê‚é
long long extGCD(long long a, long long b, long long &x, long long &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long d = extGCD(b, a%b, y, x);
	y -= a / b * x;
	return d;
}
signed main() {	
	long long x, y;
	extGCD(111, 30, x, y);
	cout << x << ", " << y << endl;
}