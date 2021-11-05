#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int visited[10];

typedef struct Graph
{
	int val;
	struct Graph* next;
}Graph;


void DFS(Graph* G, int s, int n)
{
	visited[s] = 1;
	printf("%d ", s);
	Graph* p = G[s].next;
	while (p != NULL)
	{
		if (visited[p->val] == 0)
			DFS(G, p->val, n);
		p = p->next;
	}
}

void insertNode(Graph* G, int Vx, int Vy)
{
	Graph* GR = (Graph*)malloc(sizeof(Graph));
	if (GR != NULL)
	{
		GR->val = Vx;
		GR->next = G[Vy].next;
		G[Vy].next = GR;
	}
}

int main()
{
	Graph G[10] = { 0 };
	int i, n, m, s;
	int Vx, Vy;
	scanf("%d%d%d", &n, &m, &s);
	int visited[10];
	for (i = 1; i < n; ++i)
	{
		visited[i] = 0;
		G[i].next = NULL;
	}
	visited[i] = 0;
	for (i = 0; i < m; ++i)
	{
		scanf("%d%d", &Vx, &Vy);
		insertNode(G, Vx, Vy);
		insertNode(G, Vy, Vx);
	}
	DFS(G, s, n);

	return 0;
}