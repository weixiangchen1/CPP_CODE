//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//
//int is_prime(long long x)
//{
//	if (x < 2)
//		return 0;
//	if (x == 2)
//		return 1;
//	for (int j = 2; j <= sqrt(x); j++)
//	{
//		if (x % j == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	char num[2000];
//	char ans[1000];
//	int len = 0;
//	int k = 0;
//	int flag = 0;
//	long long val = 0;
//	scanf("%d%d", &len, &k);
//	getchar();
//	gets_s(num);
//	for (int i = 0; i <= len - k; i++)
//	{
//		strncpy(ans, num + i, k); 
//		* (ans + k) = '\0';
//		val = atoi(ans);
//		printf("%s\n", ans);
//		if (is_prime(val))
//		{
//			puts(ans);
//
//			flag = 1;
//			break;
//		}
//	}
//
//	if (!flag)
//		printf("404\n");
//
//	return 0;
//}