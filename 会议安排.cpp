#include <iostream>
#include <algorithm>
using namespace std;

int tmp = 0;
int maxtime = 0;
//int visited[12] = { 0 };
struct time
{
	int begin;
	int end;
	int ContinueTime;
}times[12];

bool cmp(struct time s1, struct time s2)
{
	return s1.begin < s2.begin;
}

void dfs(int n, int i)
{
	if (maxtime < tmp)
		maxtime = tmp;

	for (int j = i; j < n; j++)
	{
		if (times[i].end > times[j].begin)
		{
			continue;
		}
		tmp += times[j].ContinueTime;
		dfs(n, j);
		tmp -= times[j].ContinueTime;
	}

}

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> times[i].begin >> times[i].end;
		times[i].ContinueTime = times[i].end - times[i].begin;
	}

	sort(times, times + n, cmp);
	for (int i = 0; i < n; i++)
	{
		//visited[i] = 1;
		tmp += times[i].ContinueTime;
		dfs(n, i);
		tmp -= times[i].ContinueTime;
		//visited[i] = 0;

	}

	cout << maxtime << endl;

	return 0;
}

