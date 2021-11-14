//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
// 
//void swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//void dispasolution(int a[], int n)
//{
//	printf("{");
//	for (int i = 0; i < n - 1; i++)
//		printf("%d,", a[i]);
//	printf("%d}\n", a[n - 1]);
//}
//
//void dfs(int a[], int n, int m, int i)
//{
//	if (i >= m)
//		dispasolution(a, m);
//	else
//	{
//		for (int j = i; j < n; j++)
//		{
//			swap(a[i], a[j]);
//			dfs(a, n, m, i + 1);
//			swap(a[i], a[j]);
//		}
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d%d", &n, &m);
//	int a[25] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = i + 1;
//	}
//	dfs(a, n, m, 0);
//	printf("\n");
//
//	return 0;
//}