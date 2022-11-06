#include <bits/stdc++.h>

using namespace std;

typedef int C;
typedef complex<C> P;
typedef pair<int, int> pii;

#define F first
#define S second
#define X real()
#define Y imag()
#define PB push_back
#define INF 0x3f3f3f3f

#define N 1002

struct Rectangle { P pi, ps; };

int w[N];
bool visited[N];

Rectangle r[N];
vector<pii> adj[N];

int distance (Rectangle a, Rectangle b)
{
  int d = 0;
  d += max(0, b.pi.X - a.ps.X) + max(0, a.pi.X - b.ps.X);
  d += max(0, b.pi.Y - a.ps.Y) + max(0, a.pi.Y - b.ps.Y);
  return d;
}

void dijkstra (int s, int t)
{
  memset(w, INF, sizeof(w));
  
  priority_queue<pii> pq;

  w[s] = 0;
  pq.push({0, s});
  
  while (!pq.empty())
  {
    int u = pq.top().S; pq.pop();
    
    if (visited[u]) continue;
    
    if (u == t) return;
    
    visited[u] = 1;
    
    for (pii x : adj[u])
    {
      int v = x.F, d = x.S;
      
      if (!visited[v] && w[v] > w[u] + d)
      {
        w[v] = w[u] + d;
        pq.push({-w[v], v});
      }
    }
  }
}

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int xi, yi, xf, yf;
  cin >> xi >> yi >> xf >> yf;
  
  int n; cin >> n;
  
  r[0] = {{xi, yi}, {xi, yi}}, r[n + 1] = {{xf, yf}, {xf, yf}};
  
  for (int i = 1; i <= n; i++)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    r[i] = {{x1, y1}, {x2, y2}};
  }
  
  for (int i = 0; i <= n; i++)
    for (int j = i + 1; j <= n + 1; j++)
    {
      int d = distance(r[i], r[j]);
      adj[i].PB({j, d});
      adj[j].PB({i, d});
    }
  
  dijkstra(0, n + 1);
  
  cout << w[n + 1] << '\n';
}
