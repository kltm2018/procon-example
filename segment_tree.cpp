//https://www.slideshare.net/iwiwi/ss-3578491

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N = 131072;

int n;
int dat[MAX_N * 2 - 1];
//初期化
void init()
{
	//全ての値をINT_MAX
	for (int i = 0; i < 2 * n - 1; i++)
	{
		dat[i] = INT_MAX;
	}
}

//i番目の値をxに変更
void update(int i, int x)
{
	//葉のノードの番号
	i += n - 1;
	dat[i] = x;
	//上りながら更新
	while (i > 0)
	{
		i = (i - 1) / 2;
		dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
	}

}


//[a,b)の最小値を求める
//k番目のノード　範囲は[l,r)

int query(int a, int b, int k, int l, int r)
{
	if (r <= a || b <= l)
	{
		return INT_MAX;
	}
	if (a <= l && r <= b)
	{
		return dat[k];
	}
	else
	{
		int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(vl, vr);
	}

}




int main()
{

}
