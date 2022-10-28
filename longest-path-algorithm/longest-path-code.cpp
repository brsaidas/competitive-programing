#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define F first
#define S second
#define PB push_back

#define N 1001

int dist[N];
int max_dist[N];
bool processed[N];
vector<pii> adj[N];

void dfs (int s, int e) {
  dist[s] = 0;

  for (auto x : adj[s]) {
    int u = x.F;

    if (u == e) continue;

    if (dist[u] == -1) dfs(u, s);

    dist[s] = max(dist[s], 1 + dist[u]);
  }
}

void maiorCaminho (int s) {
  memset(max_dist, -1, sizeof(max_dist));
  memset(processed, false, sizeof(processed));

  priority_queue<pii> pq;

  max_dist[s] = 0;
  pq.push({dist[s], s});

  while (!pq.empty()) {
    int u = pq.top().S; pq.pop();

    if (processed[u]) continue;

    processed[u] = true;

    for (auto x : adj[u]) {
      int v = x.F;
      int d = x.S;

      if (max_dist[v] < max_dist[u] + d) {
        max_dist[v] = max_dist[u] + d;
        pq.push({dist[v], v});
      }
    }
  }
}

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, x;
  cin >> n >> m >> x;

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].PB({v, w});
  }

  memset(dist, -1, sizeof(dist));

  dfs(x, 0);

  maiorCaminho(x);

  int maior = -1;
  for (int i = 1; i <= n; i++) {
    maior = max(maior, max_dist[i]);
  }

  cout << "Maior Distancia = " << maior << '\n';
}
