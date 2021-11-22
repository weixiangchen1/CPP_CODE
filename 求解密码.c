#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
char str[15] = { 0 };
char solution[10] = { 0 };
int visited[15] = { 0 };
int cnt = 0;
int ret = 0;
int cmp_char(const void* e1, const void* e2)
{
	return *(char*)e2 - *(char*)e1;
}

void check_print(int i, int count)
{
	int sum = 0;
	int flag = 1;
	while (i--)
	{
		sum += flag*pow((solution[i] - 'A' + 1), i+1);
		flag = -flag;
	}
	if (sum == count)
	{
		ret = 1;
		printf("%s\n", solution);
	}
}

void dfs(int i, int count)
{
	if (ret == 1)
		return;
	if (i == 5)
	{
		check_print(i, count);
		return;
	}
	else
	{
		for (int j = 0; j < strlen(str); j++)
		{
			if (!visited[j])
			{
				visited[j] = 1;
				solution[cnt++] = str[j];
				dfs(i + 1, count);
				cnt--;
				visited[j] = 0;
			}
		}
	}
}

int main()
{
	int count = 0;
	while (scanf("%d", &count) && count != 0 && scanf("%s", str))
	{
		ret = 0;
		memset(visited, 0, 15);
		qsort(str, strlen(str), 1, cmp_char);
		dfs(0, count);
		if (ret == 0)
			printf("no solution\n");
	}

	return 0;
}