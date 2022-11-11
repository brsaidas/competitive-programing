#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

#define N 501
#define K 501

int dp[N][K];
int arr[N], s[N];

int sum(int l, int r) {
  return s[r] - s[l - 1];
}

int join(int l, int r) {
  return (r - l + 1) * arr[r] - sum(l, r);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, k; cin >> n >> k;

  for (int i = 1; i <= n; i++) cin >> arr[i];

  sort(arr + 1, arr + n + 1);

  s[0] = 0;
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + arr[i];

  memset(dp, INF, sizeof(dp));

  dp[0][0] = 0;

  for (int i = 1; i <= n; i++) {
    for (int s = 1; s <= k; s++) {
      for (int j = 1; j <= i; j++) {
        dp[i][s] = min(dp[i][s], dp[i - j][s - 1] + join(i - j + 1, i));
      }
    }
  }

  cout << dp[n][k] << '\n';
}
