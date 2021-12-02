#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;
int cur[30];
int ans[20];
int w[30][30];
int c[30][30];
int n, m, d;
int Min = 20000000;
void dfs(int i, int W, int C)
{
	if (i == n)
	{
		Min = W;
		for (int j = 0; j < n; j++)
		{
			ans[j] = cur[j];
		}
		
	}
	else
	{

		for (int j = 0; j < n; j++)
		{
			if (W + w[i][j] < Min && C + c[i][j] <= d)
			{
				cur[i] = j + 1;
				W += w[i][j];
				C += c[i][j];
				dfs(i + 1, W, C);
				W -= w[i][j];
				C -= c[i][j];
			}
		}
	}
}

void solve()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> w[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c[i][j];
		}
	}
	dfs(0, 0, 0);
	int j = 0;
	for (j = 0; j < n - 1; j++)
	{
		cout << ans[j] << " ";
	}
	cout << ans[j] << endl;
	cout << Min << endl;
}

int main()
{
	cin >> n >> m >> d;
	solve();
	return 0;
}