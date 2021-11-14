#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int num = 0;
int arr[50] = { 0 };
int visited[50] = { 0 };
int val[50] = { 0 };

void print(int n, int m)
{
	printf("{");
	for (int i = 0; i < m-1; i++)
	{
		printf("%d,", val[i]);
	}
	printf("%d", val[m-1]);
	printf("}\n");
}
void dfs(int n, int m, int i)
{
   	if (i >= m)
	{
		//num = 0;
		print(n, m);
		return;
	}
	else
	{
		
		for (int j = 0; j < n; j++)
		{
			if (visited[j] == 1)
			{
				continue;
			}
			visited[j] = 1;
			val[num++] = arr[j];
			dfs(n, m, i + 1);
			val[--num] = 0;
			visited[j] = 0;
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
	dfs(n, m, 0);
	return 0;
}
