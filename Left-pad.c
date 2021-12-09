//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//
//void reverse(char* str, int left, int right)
//{
//	while (left < right)
//	{
//		char tmp = *(str + left);
//		*(str + left) = *(str + right);
//		*(str + right) = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char ans[2000] = { 0 };
//	char str[2000];
//	char ch[2];
//	int num = 0;
//	scanf("%d", &num);
//	getchar();
//	gets(ch);
//	gets(str);
//	int len = strlen(str);
//	if (len < num)
//	{
//		for (int i = 0; i < num - len; i++)
//		{
//			strcat(ans, ch);
//		}
//		strcat(ans, str);
//		printf("%s\n", ans);
//	}
//	else
//	{
//		reverse(str, 0, len - 1);
//		reverse(str, 0, num - 1);
//		strncat(ans, str, num);
//		printf("%s\n", ans);
//	}
//
//	return 0;
//}