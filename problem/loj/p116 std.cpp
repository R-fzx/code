#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
#include <queue>

const int MAXN = 202;

struct Node
{
	struct Edge *firstEdge, *currEdge;
	int level, extraIn;
} N[MAXN + 2];

struct Edge
{
	Node *from, *to;
	int cap, flow;
	Edge *next, *revEdge;

	Edge(Node *from, Node *to, int cap) : from(from), to(to), cap(cap), flow(0), next(from->firstEdge) {}
};

struct Dinic
{
	bool makeLevelGraph(Node *s, Node *t, int n)
	{
		for (int i = 0; i < n; i++)
		{
			N[i].level = 0;
			N[i].currEdge = N[i].firstEdge;
		}

		std::queue<Node *> q;
		q.push(s);

		s->level = 1;

		while (!q.empty())
		{
			Node *v = q.front();
			q.pop();

			for (Edge *e = v->firstEdge; e; e = e->next)
			{
				if (e->flow < e->cap && !e->to->level)
				{
					e->to->level = v->level + 1;
					if (e->to == t) return true;
					else q.push(e->to);
				}
			}
		}
    for (int i = 0; i < n; ++i) {
      printf("%d ", N[i].level);
    }
    printf("\n");
		return false;
	}

	int findPath(Node *s, Node *t, int limit = INT_MAX)
	{
		if (s == t) return limit;

		for (Edge *&e = s->currEdge; e; e = e->next)
		{
			if (e->to->level == s->level + 1 && e->flow < e->cap)
			{
				int flow = findPath(e->to, t, std::min(limit, e->cap - e->flow));
				if (flow)
				{
					e->flow += flow;
					e->revEdge->flow -= flow;
					return flow;
				}
			}
		}

		return 0;
	}

	int operator()(int s, int t, int n)
	{
		int res = 0;
		while (makeLevelGraph(&N[s], &N[t], n))
		{
			int flow;
			while ((flow = findPath(&N[s], &N[t])) > 0) res += flow;
		}

		return res;
	}
} dinic;

inline void addEdge(int from, int to, int cap)
{
	N[from].firstEdge = new Edge(&N[from], &N[to], cap);
	N[to].firstEdge = new Edge(&N[to], &N[from], 0);

	N[from].firstEdge->revEdge = N[to].firstEdge;
	N[to].firstEdge->revEdge = N[from].firstEdge;
}

inline void addEdge(int from, int to, int lower, int upper)
{
	int cap = upper - lower;
	addEdge(from, to, cap);

	N[to].extraIn += lower;
	N[from].extraIn -= lower;
}

// 原图的节点编号为 [1, n]
// 超级源点、汇点会占用 0 与 n + 1
//
// 所以总节点要开 MAXN + 2
inline int flow(int s, int t, int n)
{
	addEdge(t, s, INT_MAX);

	int S = 0, T = n + 1;

	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (N[i].extraIn > 0)
		{
			addEdge(S, i, N[i].extraIn);
			sum += N[i].extraIn;
		}
		else if (N[i].extraIn < 0)
		{
			addEdge(i, T, -N[i].extraIn);
		}
	}

	// 求可行流，满足下界
	int flow = dinic(S, T, n + 2);
  printf("%d\n", flow);
	if (flow < sum) return -1;

	// 直接增广得到最大流
	return dinic(s, t, n + 2);
}

int main()
{
	int n, m, s, t;
	scanf("%d %d %d %d", &n, &m, &s, &t);

	while (m--)
	{
		int u, v, lower, upper;
		scanf("%d %d %d %d", &u, &v, &lower, &upper);
		addEdge(u, v, lower, upper);
	}
	
	int ans = flow(s, t, n);
	if (ans == -1) puts("please go home to sleep");
	else printf("%d\n", ans);

	return 0;
}