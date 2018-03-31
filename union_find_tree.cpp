#include<iostream>
#include<vector>
#define MAX_N 100000
using namespace std;
int par[MAX_N], r[MAX_N];//rank
int N;

void init(int N)
{
	int i;
	for ( i= 0; i < N; i++)
	{
		r[i] = 0;
		par[i] = i;
	}
}

int root(int x)
{
	if (par[x] == x)
	{
		return x;
	}
	else
	{
		return par[x] = root(par[x]);
	}
}

bool same(int x, int y)
{
	return  root(x) == root(y);
	
}

void unite(int x, int y)
{
	x = root(x);
	y = root(y);
	if (x == y)
	{
		return;
	}
	if (r[x] < r[y])
	{
		par[x] = y;
	}
	else if(r[x]>r[y])
	{
		par[y] = x;
	}
	else if (r[x] == r[y])
	{
		par[x] = y;
		r[y]++;
	}

}


int main()
{
	
	
	cin >> N;
	init(N);
	int Q;
	cin >> Q;
	vector<vector<int>>v(Q, vector<int>(3));
	for (int i = 0; i < Q; i++)
	{
		
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}

	for (int i = 0; i < Q; i++)
	{
		if (v[i][0] == 0)
		{
			unite(v[i][1], v[i][2]);
		}
		else if (v[i][0] == 1)
		{
			if (same((v[i][1]),( v[i][2])))
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << par[i]<<" "<<root(i) << endl;
	}
}