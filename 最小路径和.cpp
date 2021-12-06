#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>  
#define MAX 1050

double dp[MAX][MAX];
double arr[MAX][MAX];
int n, m;

double min(double x, double y)
{
	return x > y ? y : x;
}

double Search()
{
	int i, j;
	if (n == 1 && m > 1)
	{
		dp[0][0] = arr[0][0];
		for (i = 1; i < m; i++)
		{
			dp[0][i] = dp[0][i - 1] + arr[0][i];
		}
		return dp[0][m - 1];
	}

	if (m == 1 && n > 1)
	{
		dp[0][0] = arr[0][0];
		for (i = 1; i < n; i++)
		{
			dp[i][0] = dp[i - 1][0] + arr[i][0];
		}
		return dp[n - 1][0];
	}
	
	dp[0][0] = arr[0][0];
	//第一行
	for (i = 1; i < n; i++)
	{
		dp[0][i] = dp[0][i - 1] + arr[0][i];
	}
	//第一列
	for (i = 1; i < m; i++)
	{
		dp[i][0] = dp[i - 1][0] + arr[i][0];
	}
	//其他
	for (i = 1; i < n; i++)
	{
		for (j = 1; j < m; j++)
		{
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
		}
	}


	return dp[n - 1][m - 1];

}

int main()
{
	scanf("%d%d", &n, &m);
	memset(dp, 0, sizeof(dp));
	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%lf", &arr[i][j]);
		}
	}
	printf("%.0lf\n", Search());

	return 0;
}