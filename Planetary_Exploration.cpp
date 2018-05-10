//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560
//“ñŸŒ³—İÏ˜a
#include<vector>
#include<iostream>
#include<string>
using namespace std;
int J[1001][1001];
int O[1001][1001];
char str[1001][1001];
//I‚Ì”‚Í‘S‘Ì‚©‚çJ,O‚ğˆø‚¢‚Ä‹‚ß‚é•ûj
int main()
{
	int M, N, K;//M‚Íc‚Ì’·‚³@N‚Í‰¡‚Ì’·‚³@K‚ÍƒNƒGƒŠ‚Ì”
	cin >> M >> N >> K;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> str[i][j];
		}
	}//str[M][N]‚Å˜f¯‚Ìî•ñ‚ğ‚Á‚½
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (str[i][j] == 'J')
			{
				J[i + 1][j + 1]++;
			}
			if (str[i][j] == 'O')
			{
				O[i + 1][j + 1]++;
			}
		}
	}
	//“ñŸŒ³—İÏ˜a‚Ì‰¡‚Ì•”•ª
	for (int i = 0; i <= M; i++)
	{
		int p = 0;
		int q = 0;
		for (int j = 0; j <= N; j++)
		{
			p = p + J[i][j];
			J[i][j] = p;
			q = q + O[i][j];
			O[i][j] = q;
		}
	}
	//“ñŸŒ³—İÏ˜a‚Ìc‚Ì•”•ª
	for (int j = 0; j <= N; j++)
	{
		int p = 0;
		int q = 0;
		for (int i = 0; i <= M; i++)
		{
			p = p + J[i][j];
			J[i][j] = p;
			q = q + O[i][j];
			O[i][j] = q;
		}
	}
	for (int i = 0; i < K; i++)
	{
		int a, b, c, d;//’²‚×‚é—Ìˆæ‚ğw’è‚·‚éÀ•W
		cin >> a >> b >> c >> d;
		int j = J[c][d] - J[a - 1][d] - J[c][b - 1] + J[a - 1][b - 1];
		int o = O[c][d] - O[a - 1][d] - O[c][b - 1] + O[a - 1][b - 1];
		cout << j <<" "<< o <<" " << (c - a + 1)*(d - b + 1) - j - o << endl;
	}
	return 0;
}