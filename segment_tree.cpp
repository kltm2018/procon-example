//http://tsutaj.hatenablog.com/entry/2017/03/29/204841
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
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
class segment_tree {
private:
	int n;
	vector<int>node;
	const int INF = numeric_limits<signed>::max();
public:
	segment_tree(vector<int>v) {
		//元の配列vをセグメント木で表現する
		// 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
		// セグメント木全体で必要なノード数は 2n-1 個である
		int sz = v.size();//要素数
		n = 1;
		while (n < sz) {
			n *= 2;
		}
		node.resize(2 * n - 1, INF);
		//最下段に値を入れた後に、下の段から順番に値を入れる
		for (int i = 0; i < sz; i++) {
			node[i + n - 1] = v[i];
		}
		//値を入れるには、自分の子の二値を入れればいい
		for (int i = n - 2; i >= 0; i--) {
			node[i] = min(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	void update(int x, int val) {//x番目の要素をvalに更新する
								 //最下段のノードにアクセスする
		x += (n - 1);
		//最下段のノードを更新したら、あとは親にのぼって更新していく
		node[x] = val;
		while (x > 0) {
			x = (x - 1) / 2;
			node[x] = min(node[2 * x + 1], node[2 * x + 2]);
		}
	}
	/*
	「区間 [a,b) にある要素の最小値を答える」ことを考えます。
	説明のため、クエリで与えられた区間 (実際に計算したい区間) を「要求区間」、
	各ノードがカバーしている区間を「対象区間」と定義します (造語)。
	これを扱うには、以下の 3 つの情報が必要になります。

	要求区間はどのような区間か？
	いま自分がいるノードは何番目か？
	自分がいるノードはどのような区間か？ (対象区間はどのようになっているか？)

	要求区間と対象区間の関係によって場合分けをします。
	*/
	// 要求区間 [a, b) 中の要素の最小値を答える
	// k := 自分がいるノードのインデックス
	// 対象区間は [l, r) にあたる
	int getmin(int a, int b, int k = 0, int l = 0, int r = -1) {
		//最初に呼び出された時の対象区間は[0,n)
		if (r < 0) {
			r = n;
		}
		// 要求区間と対象区間が交わらない -> 適当に返す
		if (r <= a || b <= l) {
			return INF;
		}
		// 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
		if (a <= l && r <= b) return node[k];
		// 要求区間が対象区間の一部を被覆 -> 子について探索を行う
		// 左側の子を vl ・ 右側の子を vr としている
		// 新しい対象区間は、現在の対象区間を半分に割ったもの
		int vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
		int vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
		return min(vl, vr);


	}
};
signed main() {
	my_io();
	int n, q;
	cin >> n >> q;
	segment_tree segtree(vector<int>(n, numeric_limits<signed>::max()));
	for (int i = 0; i < q; i++) {
		int com;
		cin >> com;
		if (com == 0) {
			int x, val;
			cin >> x >> val;
			segtree.update(x, val);
		}
		else if (com == 1) {
			int a, b;
			cin >> a >> b;
			cout << segtree.getmin(a, b + 1) << endl;
		}
	}
	return 0;
}