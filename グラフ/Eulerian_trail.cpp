//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0225
//ユニオンファインド木
//オイラー閉路
#include<iostream>
#include<vector>
#include<string>
using namespace std;




int par[26];
int r[26];//rank

void init(int n)//頂点の数を引数にして初期化
{
	for (int i = 0; i < n; i++)
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
	return root(x) == root(y);
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
	else if (r[x] > r[y])
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
	int n;//単語の数

	while (cin >> n, n)
	{
		init(26);//グラフの頂点の数=アルファベットの数=26
		vector<string>word(n);
		for (auto& s : word)
		{
			cin >> s;
		}

		vector<int> in(26), out(26);
		for (auto& s : word)
		{
			const auto first = s[0] - 'a', last = s.back() - 'a';//最初と最後の文字を取り出す　-'a'はa-zを0-25に対応させている
			in[first]++;//入次数
			out[last]++;//出次数
			unite(first, last);//頂点(アルファべット)first,lastが同じ集合に属する
		}
		bool ok = true;
		int comp_num = 0;//集合の数
		for (int i = 0; i < 26; i++)
		{
			comp_num += (in[i] && root(i) == i);
			ok &= in[i] == out[i];
		}
		ok &= (comp_num == 1);
		if (ok)
		{
			cout << "OK" << endl;
		}
		else
		{
			cout << "NG" << endl;
		}
	}


	return 0;
}