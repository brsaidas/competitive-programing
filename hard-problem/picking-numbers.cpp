#include <bits/stdc++.h>

using namespace std;

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector<int> freq(101);

  int n; cin >> n;
  
  for (int i = 0; i < n; i++) 
  {
    int a; cin >> a;
    freq[a]++;
  }
  
  int ans = 0;
  
  for (int i = 0; i + 1 < n; i++)
    ans = max(ans, freq[i] + freq[i + 1]);
  
  cout << ans << '\n';
}
