#include <bits/stdc++.h>

using namespace std;

int qtd[14];
int pts[14] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  int c1, c2;

  cin >> c1 >> c2;
  int j = pts[c1] + pts[c2];
  qtd[c1]++; qtd[c2]++;

  cin >> c1 >> c2;
  int m = pts[c1] + pts[c2];
  qtd[c1]++; qtd[c2]++;

  while (n--) {
    int c; cin >> c;
    qtd[c]++;

    j += pts[c];
    m += pts[c];
  }

  for (int k = 1; k <= 13; k++) {
    if (qtd[k] < 4 && ((m + pts[k] == 23) || (j + pts[k] > 23 && m + pts[k] < 23))) {
      cout << k << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';
  return 0;
}
