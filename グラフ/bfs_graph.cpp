//https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_C
//https://onlinejudge.u-aizu.ac.jp/beta/review.html#kmc_n05/2874082
//dfs
#include<iostream>
#include<vector>
#include<queue>
#define INF 10000000
using namespace std;
int main()
{
	int n;//頂点の数
	cin >> n;
	vector<vector<int>>v(n);
	for (int i = 0; i < n; i++)
	{
		int u;
		cin >> u;
		v[i].push_back(u);
		int k;
		cin >> k;
		v[i].push_back(k);
		for (int j = 0; j < k; j++)
		{
			int number;
			cin >> number;
			v[i].push_back(number);
		}
	}
	vector<int>dist(n+1,INF);
	dist[0] = -1;
	dist[1] = 0;
	vector<bool>visited(n+1,false);
	visited[0] = true;
	visited[1] = true;
	
	queue<int> que;
	
	que.push(1);//スタート地点をqueに追加
	while (!que.empty())
	{
		int u;
		u = que.front();
		que.pop();
		for (int i = 0; i < n; i++)
		{
			if (u == v[i][0])
			{
				for (int j = 0; j < v[i][1]; j++)
				{
					if (!visited[v[i][2 + j]]&&dist[v[i][2 + j]]>dist[u]+1)
					{
						visited[v[i][2 + j]] = true;
						que.push(v[i][2 + j]);
						dist[v[i][2 + j]] = dist[u] + 1;
					}
				}
			}
		}
	}
	for (int i = 1; i < n + 1; i++)
	{
		if (dist[i] != INF)
		{
			cout <<i <<" " <<dist[i] << endl;
	    }
		else
		{
			cout << i<<" "<<-1 << endl;
		}
	}
	return 0;
}
