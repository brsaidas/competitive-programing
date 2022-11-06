#include <bits/stdc++.h>

using namespace std;

#define int long long

int pot10[19], acc[19];

int32_t main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  pot10[0] = 1;
  for (int i = 1; i <= 18; i++) pot10[i] = 10*pot10[i - 1];

  acc[0] = 0; acc[1] = 10;
  for (int i = 2; i < 18; i++) acc[i] = acc[i - 1] + i*9*pot10[i - 1];
  
  int q; cin >> q;
  
  while (q--)
  {
    int k; cin >> k;
    
    if (k > 9)
    {
      int d;
      for (d = 0; d < 18; d++) if (k < acc[d]) break;
      
      int x = (k - acc[d - 1] + d*pot10[d - 1] - d)/d;
            
      int sx = acc[d - 1] + d*(x - pot10[d - 1] + 1);
      
      string u = "";
      int i = sx, num = x + 1;
      
      while (i <= k)
      {
        string aux = to_string(num);
        
        u += aux;
        i += aux.size();
      
        num++;
      }
      
      cout << u[k - sx];
    }
    else
    {
      cout << k;
    }
    
    cout << '\n';
  }
}
