//https://qiita.com/nomikura/items/1518bc8a6e04d2580b0d
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
	cout << fixed << setprecision(10);
}
char Board[H][W]; // ゲームの状態を持つ

				  // 盤面を評価する関数。自分の得点を求める。
int value() {
	// 中身を書く
}

int MIN_MAX(int turn) {
	// 終局したら盤面の値を返す
	if (turn == END) return value();

	if (/*自分の局面*/) {
		int Max = -INF;
		for () {
			// 今の盤面で自分が打てるすべての状態を列挙
			Max = max(Max, MIN_MAX(turn + 1));
		}
		return Max;
	}
	else { // 相手の局面
		int Min = INF;
		for () {
			// 今の盤面で相手が打てるすべての状態を列挙
			Min = min(Min, MIN_MAX(turn + 1));
		}
		return Min;
	}
}
signed main() {
	my_io();
	int myPoint = MIN_MAX(0);

}
