#include <bits/stdc++.h>

using namespace std;

#define PB push_back

#define S 201

int h[S];
int max_dist[S];
vector<int> adj[S];

void dfs (int s, int e) {
  max_dist[s] = 0;

  for (auto u : adj[s]) {
    if (u == e) break;

    if (max_dist[u] == -1) dfs(u, s);

    max_dist[s] = max(max_dist[s], 1 + max_dist[u]);
  }
}

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int s, t, p;
  cin >> s >> t >> p;

  for (int i = 1; i <= s; i++) {
    cin >> h[i];
  }

  while (t--) {
    int i, j;
    cin >> i >> j;

    if (h[i] > h[j]) {
      adj[i].PB(j);
    } else if (h[i] < h[j]) {
      adj[j].PB(i);
    }
  }

  memset(max_dist, -1, sizeof(max_dist));

  dfs(p, 0);

  cout << max_dist[p] << '\n';
}
