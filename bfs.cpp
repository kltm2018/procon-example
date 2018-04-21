//幅優先探索
//https://abc007.contest.atcoder.jp/tasks/abc007_3
#include<vector>
#include<iostream>
#include<string>
#include<queue>

#define MAX_N 100
#define MAX_M 100
using namespace std;
const int INF = 100000000;
string maze[MAX_N];
int N, M;
int sx, sy;//start
int gx, gy;//goal
int d[MAX_N][MAX_M];//各点までの最短距離の配列
					//移動4方向のベクトル
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

//(sx,sy)から(gx,gy)の最短距離
//たどりつけないとINF
int bfs()
{
	queue<pair<int, int>>que;
	//全ての点をINFで初期化
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			d[i][j] = INF;
		}
	}
	//スタート地点をキューに入れ、その点の距離を0にする
	que.push(make_pair(sx, sy));
	d[sy][sx] = 0;

	//キューが空になるまでループ
	while (que.size())
	{
		//キューの先頭を取り出す
		pair<int, int> p = que.front();
		que.pop();
		//取り出してきた状態がゴールなら探索をやめる
		if (p.first == gx && p.second == gy)
		{
			break;
		}
		//移動4方向をループ
		for (int i = 0; i < 4; i++)
		{
			//移動した後の点を(nx,ny)とする
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			//移動が可能かの判定とすでに訪れたことがあるかの判定(d[nx][ny]!=INFなら訪れたことがある)
			if ((0 <= ny && ny < N) && (0 <= nx && nx < M) && (maze[ny][nx] != '#') && (d[ny][nx] == INF))
			{
				//移動できるならキューに入れ、その点の距離をpからの距離+1で確定する
				que.push(make_pair(nx, ny));
				d[ny][nx] = d[p.second][p.first] + 1;
			}
		}
	}
	return d[gy][gx];
}
int main()
{

	cin >> N >> M;

	cin >> sy >> sx; sx--; sy--;

	cin >> gy >> gx; gx--; gy--;
	for (int i = 0; i < N; i++)
	{
		cin >> maze[i];
	}
	int res = bfs();
	cout << res << endl;
	return 0;

}