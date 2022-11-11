#include <bits/stdc++.h>

using namespace std;

#define N 1000

struct Point
{
  int x, y;
};

Point pts[N];

bool visited[N];
vector<int> adj[N];

void bfs (int s)
{
  queue<int> q;

  visited[s] = 1;
  q.push(s);

  while (!q.empty())
  {
    int u = q.front(); q.pop();

    for (int v : adj[u]) if (!visited[v])
    {
      visited[v] = 1;
      q.push(v);
    }
  }
}

int dist (Point a, Point b)
{
  return abs(a.x - b.x) + abs(a.y - b.y);
}

int main ()
{
  ios::sync_with_stdio(0); cin.tie(0);

  int limX, limY, n, a; cin >> limX >> limY >> n >> a;

  for (int i = 0; i < n; i++)
  {
    int x, y; cin >> x >> y;
    pts[i] = {x, y};
  }

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (dist(pts[i], pts[j]) * 100 <= a)
      {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  int cnt = 0;

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      cnt++;
      bfs(i);
    }
  }

  cout << --cnt << '\n';
}
