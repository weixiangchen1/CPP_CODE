#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int graph[20][20] = { 0 };
int visited[20] = { 0 };
int path[20] = { 0 };
int count = 0, cnt = 0;
int begin = 0;

void check_print(int i, int v)
{
	if (v == begin)
	{
		cnt++;
		printf("Path %d :", cnt);
		for (int j = 0; j < count; j++)
			printf("%d ", path[j]);
		printf("\n");
	}
}

void dfs(int v, int i, int n)
{
	if (i == n)
	{
		check_print(i, v);
		return;
	}
	else
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[v][j] == 1 && visited[j] != 1)
			{
				visited[j] = 1;
				path[count++] = j;
				dfs(j, i + 1, n);
				count--;
				visited[j] = 0;
			}
		}
	}

}

int main()
{
	int n, e;
	int v1, v2;
	scanf("%d%d", &n, &e);
	while (e--)
	{
		scanf("%d%d", &v1, &v2);
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}
	scanf("%d", &begin);
	path[count++] = begin;
	dfs(begin, 0, n);

	return 0;
}