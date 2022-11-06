#include <bits/stdc++.h>

using namespace std;

#define PB push_back

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int n; cin >> n;
  
  vector<int> r(n), rank(n + 1);
  
  for (int i = 0; i < n; i++) cin >> r[i];
  
  rank[0] = 1;
  
  for (int i = 1; i < n; i++)
  {
    if (r[i] == r[i - 1]) rank[i] = rank[i - 1];
    else rank[i] = rank[i - 1] + 1;
  }
  
  rank[n] = rank[n - 1] + 1;
  
  int m; cin >> m;
  
  vector<int> p(m);
  
  for (int i = 0; i < m; i++) cin >> p[i];
  
  for (int i = 0; i < m; i++)
  {
    int beg = 0, end = n - 1;
    
    while (beg <= end)
    {
      int mid = (beg + end) >> 1;
      
      if (r[mid] > p[i]) beg = mid + 1;
      else end = mid - 1;
    }
    
    end++;
    
    cout << rank[end] << '\n';
  }
}
