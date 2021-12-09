#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <limits.h>
int n;
int pow[10050];
int dp[10050];

int min(int x, int y)
{
	return x > y ? y : x;
}

void Search()
{
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (pow[j] == 0)
				continue;
			if (j + pow[j] >= i)
			{
				dp[i] = min(dp[i], dp[j] + 1);
			}
		}
		/*for (int k = 0; k <= n; k++)
			printf("%d ", dp[k]);
		putchar('\n');*/

	}

}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &pow[i]);
		dp[i] = 10000;
	}
	dp[n] = 10000;
	Search();
	if (dp[n] == 10000)
		printf("-1\n");
	else
		printf("%d\n", dp[n]);

	return 0;
}