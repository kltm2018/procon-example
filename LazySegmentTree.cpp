//http://tsutaj.hatenablog.com/entry/2017/03/30/224339
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=jp
#include<bits/stdc++.h>
#pragma warning(disable:4996)
#ifdef _MSC_VER
#  define __builtin_popcount __builtin_popcountll
#  define __builtin_popcountll __popcnt
#endif
#define int long long
using namespace std;
using ll = long long;
using ld = long double;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
inline void my_io() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout << fixed << setprecision(10);
}
class LazySegmentTree{
private:
	int n;
	vector<ll>node, lazy;
public:
	LazySegmentTree(vector<ll>v) {
		int sz = (int)v.size();
		n = 1; while (n < sz)n *= 2;
		node.resize(2 * n - 1);
		lazy.resize(2 * n - 1, 0);

		for (int i = 0; i<sz; i++)node[i + n - 1] = v[i];
		for (int i = n - 2; i >= 0; i--)node[i] = node[i * 2 + 1] + node[i * 2 + 2];
	}
	//k”Ô–Ú‚Ìƒm[ƒh‚É‚Â‚¢‚Ä’x‰„•]‰¿‚ğs‚¤
	void eval(int k, int l, int r) {
		//’x‰„”z—ñ‚ª‹ó‚Å‚È‚¢ê‡A©ƒm[ƒh‹y‚Ñqƒm[ƒh‚Ö‚Ì’l‚Ì“`”d‚ª‚¨‚±‚é
		if (lazy[k] != 0) {
			node[k] += lazy[k];
			//Å‰º’i‚©‚Ç‚¤‚©‚Ìƒ`ƒFƒbƒN‚ğ‚·‚é
			//qƒm[ƒh‚Íeƒm[ƒh‚Ì1/2‚Ì”ÍˆÍ‚Å‚ ‚é‚½‚ß“`”d‚³‚¹‚é‚Æ‚«‚Í”¼•ª‚É‚·‚é
			if (r - l > 1) {
				lazy[2 * k + 1] += lazy[k] / 2;
				lazy[2 * k + 2] += lazy[k] / 2;
			}

			// “`”d‚ªI‚í‚Á‚½‚Ì‚ÅA©ƒm[ƒh‚Ì’x‰„”z—ñ‚ğ‹ó‚É‚·‚é
			lazy[k] = 0;
		}
	}
	void add(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		

		
		//”ÍˆÍŠO‚È‚ç‰½‚à‚µ‚È‚¢
		if (b <= l || r <= a) {
			eval(k, l, r);
			return;
		}
		//Š®‘S‚É”í•¢‚µ‚Ä‚¢‚é‚È‚ç‚ÎA’x‰„•]‰¿‚É’l‚ğ“ü‚ê‚½Œã‚É•]‰¿
		if (a <= l && r <= b) {
			lazy[k] += (r - l)*x;
			eval(k,l,r);//‚¨‚ë‚³‚È‚¢‚ÆŸ‚Ìelse•¶node[k] = node[2 * k + 1] + node[2 * k + 2];‚Å–â‘è‚ª‹N‚«‚é node[k]‚ğ³‚µ‚¢’l‚É‚·‚é
		}
		//‚»‚¤‚Å‚È‚¢‚È‚çqƒm[ƒh‚Ì’l‚ğÄ‹A“I‚ÉŒvZ‚µ‚ÄŒvZÏ‚İ‚Ì’l‚ğ‚à‚ç‚Á‚Ä‚­‚é
		else {
			// k ”Ô–Ú‚Ìƒm[ƒh‚É‘Î‚µ‚Ä’x‰„•]‰¿‚ğs‚¤
			eval(k, l, r);
			//k”Ô–Ú‚Ìƒm[ƒh‚É‘Î‚µ‚Ä’x‰„•]‰¿‚ğs‚¤
			add(a, b, x, 2 * k + 1, l, (l + r) / 2);
			add(a, b, x, 2 * k + 2, (l + r) / 2, r);
			node[k] = node[2 * k + 1] + node[2 * k + 2];
		}
	}
	ll getsum(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = n;
		if (b <= l || r <= a) return 0;

		// ŠÖ”‚ªŒÄ‚Ño‚³‚ê‚½‚ç•]‰¿I
		eval(k, l, r);
		if (a <= l && r <= b) return node[k];
		ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
		ll vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
		return vl + vr;
	}
};
signed main() {
	my_io();
	int n, q;
	cin >> n >> q;
	vector<int>a(n, 0);
	LazySegmentTree Lsegtree(a);
	for (int i = 0; i < q; i++) {
		int b;
		cin >> b;
		if (b == 0) {
			int s, t, x;
			cin >> s >> t >> x;
			s--;
			Lsegtree.add(s, t, x);
		}
		else if(b == 1){
			int s, t;
			cin >> s >> t;
			s--;
			cout << Lsegtree.getsum(s, t) << endl;
		}
	}
	return 0;
}

