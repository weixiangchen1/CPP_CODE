#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int arr[30];
int vis[30];
int n, k;
int sum;
int flag = 0;
void dfs(int i)
{
	if (flag == 1)
		return;
	if (sum >= k || i == n)
	{
		int val = 0;
		if (sum == k)
		{
			printf("YES\n");
			flag = 1;
			for (int j = 0; j < n; j++)
			{
				if (vis[j] == 1)
				{
					if (val == 1)
						printf(" ");
					val = 1;
					printf("%d", arr[j]);
				}
			}
			printf("\n");
		}
	}
	else
	{
		for (int j = i; j < n; j++)
		{
			if (!vis[j])
			{
				sum += arr[j];
				vis[j] = 1;
				dfs(i + 1);
				sum -= arr[j];
				vis[j] = 0;
			}
		}
	}
}

int main()
{
	while (~scanf("%d%d", &n, &k))
	{
		flag = 0;
		memset(vis, 0, n);
		memset(arr, 0, n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		dfs(0);
		if (!flag)
			printf("NO\n");
	}


	return 0;
}