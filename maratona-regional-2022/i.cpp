#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  bool flag = false;

  for (int i = 0; i < 8; i++) {
    int n; cin >> n;

    if (n == 9) {
      flag = true;
      break;
    }
  }

  if (!flag) {
    cout << "S" << '\n';
  } else {
    cout << "F" << '\n';
  }
}
