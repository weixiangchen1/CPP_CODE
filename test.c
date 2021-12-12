#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//struct movie
//{
//	char name[35];
//	double p1;
//	double p2;
//	double p3;
//	double total;
//	int num;
//	int pos;
//};
//
//int cmp(const void* e1, const void* e2)
//{
//	return ((struct movie*)e2)->total > ((struct movie*)e1)->total ? 1 : -1;
//}
//int cmp_pos(const void* e1, const void* e2)
//{
//	return ((struct movie*)e1)->pos > ((struct movie*)e2)->pos ? 1 : -1;
//}
//int main()
//{
//	struct movie movies[1050];
//	int m = 0;
//	scanf("%d", &m);
//	for (int i = 0; i < 3; i++)
//	{
//		scanf("%s%lf%lf%lf", movies[i].name, &movies[i].p1, &movies[i].p2, &movies[i].p3);
//		movies[i].total = movies[i].p1 + movies[i].p2 + movies[i].p3;
//		movies[i].pos = i;
//	}
//
//	qsort(movies, 3, sizeof(movies[0]), cmp);
//
//	movies[0].num = (int)((m * 0.5)+0.5);
//	movies[1].num = (int)((m * 0.3)+0.5);
//	movies[2].num = m - movies[0].num - movies[1].num;
//
//	qsort(movies, 3, sizeof(movies[0]), cmp_pos);
//
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%s %d\n", movies[i].name, movies[i].num);
//	}
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//int main()
//{
//	char str[10] = { 0 };
//	int n;
//	double sum = 0;
//	scanf("%d", &n);
//	getchar();
//	while (n--)
//	{
//		scanf("%s", str);
//		int jinzhi = str[0] - 'A' + 11;
//		int len = strlen(str);
//		double ret = 0;
//		int count = 0;
//		for (int i = len - 1; i >= 1; i--)
//		{
//			if (str[i] >= '0' && str[i] <= '9')
//			{
//				ret += (str[i] - '0') * pow(jinzhi, count);
//				count++;
//			}
//			else if (str[i] >= 'a' && str[i] <= 'a' + jinzhi - 11)
//			{
//				ret += (str[i] - 'A' + 11) * pow(jinzhi, count);
//				count++;
//			}
//			else
//			{
//				printf("-1\n");
//				break;
//			}
//		}
//		sum += ret;
//
//	}
//	printf("%.0lf\n", sum);
//
//
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//
//int x_add[] = { 1,-1,1,1,-1,-1 };
//int y_add[] = { 0,0,-1,1,1,-1 };
//
//char arr[1050][1050];
//int vis[1050][1050];
//int max = 0;
//void dfs(int n, int m)
//{
//
//	vis[n][m] = 2;
//	for (int k = 0; k < 6; k++)
//	{
//		n += x_add[k];
//		m += y_add[k];
//		if (arr[n][m] == 0 && vis[n][m] != 2)
//		{
//			max++;
//			dfs(n, m);
//		}
//		n -= x_add[k];
//		m -= x_add[k];
//	}
//
//
//}
//
//int main()
//{
//	memset(arr, 1, sizeof(arr));
//	memset(vis, 0, sizeof(vis));
//	int n, m, min;
//	scanf("%d%d%d", &n, &m, &min);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//			if (arr[i][j] >= min)
//			{
//				arr[i][j] = 0;
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (arr[i][j] == 0)
//			{
//				dfs(i, j);
//			}
//		}
//	}
//	printf("%d\n", max);
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//int main()
//{
//	char str[10] = { 0 };
//	int n;
//	double sum = 0;
//	scanf("%d", &n);
//	getchar();
//	while (n--)
//	{
//		scanf("%s", str);
//		int jinzhi = str[0] - 'A' + 11;
//		int len = strlen(str);
//		double ret = 0;
//		int count = 0;
//		for (int i = len - 1; i >= 1; i--)
//		{
//			if (str[i] >= '0' && str[i] <= '9')
//			{
//				ret += (str[i] - '0') * pow(jinzhi, count);
//				count++;
//			}
//			else if (str[i] >= 'a' && str[i] <= 'z')
//			{
//				ret += (str[i] - 'A' + 11) * pow(jinzhi, count);
//				count++;
//			}
//			else
//			{
//				printf("-1\n");
//				return 0;
//			}
//		}
//		sum += ret;
//
//	}
//	printf("%.0lf\n", sum);
//
//
//	return 0;
//}
#include <stdio.h>
int main()
{
	printf("%d\n", sizeof(short));

	return 0;
}