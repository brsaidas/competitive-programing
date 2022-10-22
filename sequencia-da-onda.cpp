#include <bits/stdc++.h>

using namespace std;

void lis (vector<int>& arr, vector<int>& aux) {
  vector<int> top;

  for (auto x : arr) {
    auto it = lower_bound(top.begin(), top.end(), x);

    aux.push_back((it - top.begin()) + 1);

    if (it == top.end()) top.push_back(x);
    else *it = x;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int m; cin >> m;

  vector<int> v(m);
  vector<int> u(m);

  for (int i = 0; i < m; i++) cin >> v[i];
  for (int i = 0; i < m; i++) u[i] = v[m - 1 - i];

  vector<int> lisV, lisU;

  lis(v, lisV);
  lis(u, lisU);

  reverse(lisU.begin(), lisU.end());

  int ans = 0;

  for (int i = 0; i < m; i++)
    if (lisV[i] == lisU[i] && ((lisV[i] + lisU[i] - 1) % 2 != 0))
      ans = max(ans, lisV[i] + lisU[i] - 1);

  cout << ans << '\n';
}
