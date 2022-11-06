#include <bits/stdc++.h>

using namespace std;

#define N 1000001

int h[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  int ans = 0;

  for (int i = 0; i < n; i++) {
    int x; cin >> x;

    if (h[x] > 0)
      h[x]--;
    else
      ans++;

    h[x - 1]++;
  }

  cout << ans << '\n';
}
