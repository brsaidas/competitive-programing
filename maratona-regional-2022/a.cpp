#include <bits/stdc++.h>

using namespace std;

#define N 100000

char arr[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  for (int i = 0; i < n; i++) cin >> arr[i];

  int ans = 0;

  for (int i = 0; i < n; i++) {
    if (arr[i] == 'a' && ((i - 1 >= 0 && arr[i - 1] == 'a') || (i + 1 <= n - 1 && arr[i + 1] == 'a')))
      ans++;
  }

  cout << ans << '\n';
}
