//座標圧縮
//蟻本150ページ
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX_N 100
using namespace std;
//幅優先探索用
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

//w*hの格子状　n本の直線
int W, H, N;
int X1[MAX_N], X2[MAX_N], Y1[MAX_N], Y2[MAX_N];
//塗りつぶし用
bool fld[MAX_N * 6][MAX_N * 6];

int compress(int* x1, int* x2, int w)
{
	vector<int>xs;

	for (int i = 0; i < N; i++)
	{
		for (int d = -1; d <= 1; d++)
		{
			int tx1 = x1[i] + d;
			int tx2 = x2[i] + d;
			if (1 <= tx1 && tx1 <= W)
			{
				xs.push_back(tx1);
			}
			if (1 <= tx2 && tx2 <= W)
			{
				xs.push_back(tx2);
			}
		}
	}
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());

	for (int i = 0; i < N; i++)
	{
		x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
		x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
	}
	return xs.size();
}
int solve()
{

	//座標圧縮
	W = compress(X1, X2, W);
	H = compress(Y1, Y2, H);
	//線のある部分を塗りつぶす
	memset(fld, 0, sizeof(fld));
	for (int i = 0; i < N; i++)
	{
		for (int y = Y1[i]; y <= Y2[i]; y++)
		{
			for (int x = X1[i]; x <= X2[i]; x++)
			{
				fld[y][x] = true;
			}
		}
	}
	//領域を数える
	int ans = 0;
	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			if (fld[y][x])
			{
				continue;
			}
			ans++;
			//幅優先探索
			queue<pair<int, int>>que;
			que.push(make_pair(x, y));
			while (!que.empty())
			{
				//queueの先頭を取り出す
				int sx = que.front().first;
				int sy = que.front().second;
				que.pop();

				for (int i = 0; i < 4; i++)
				{
					int tx = sx + dx[i];
					int ty = sy + dy[i];
					if (tx < 0 || W <= tx || ty < 0 || H <= ty)
					{
						continue;
					}
					if (fld[ty][tx])
					{
						continue;
					}
					que.push(make_pair(tx, ty));
					fld[ty][tx] = true;
				}
			}
		}
	}
	return ans;
}

int main()
{
	cin >> W >> H >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X1[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> X2[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> Y1[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> Y2[i];
	}
	cout << solve() << endl;
	
}



/*
unique
重複した要素を除ける。

この関数は、隣り合った重複要素を除いた要素を、範囲の先頭に集める。
この関数によってコンテナから直接要素が削除され、コンテナの要素数が減るようなことはない。
コンテナから実際に要素を削除する場合は、この関数の戻り値として、
先頭に集められた重複なし範囲の末尾の次を指すイテレータが返るため、
そのイテレータを介してコンテナのerase()メンバ関数などを呼び出し、削除を行うこと。
この関数の戻り値として返されるイテレータ以降の値は未規定。
{1,1,2,2,3}->{1,2,3,2,3}
*/