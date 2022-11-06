#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define debug(arg...) printf(arg)

int ans;
int in[3][3];

bool magicSquare (vector<vector<int>>& mat)
{
  vector<int> lin(3), col(3), dig(2);
  
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      lin[i] += mat[i][j];
    
  for (int j = 0; j < 3; j++)
    for (int i = 0; i < 3; i++)
      col[j] += mat[i][j];

  for (int i = 0; i < 3; i++)
  {
    dig[0] += mat[i][i];
    dig[1] += mat[i][2 - i];
  }
  
  bool ok = true;
  
  for (int i = 0; i < 3; i++)
    if (dig[0] != lin[i]) 
      ok = false;
    
  for (int j = 0; j < 3; j++)
    if (dig[0] != col[j])
      ok = false;
    
  if (dig[0] != dig[1]) ok = false;
  
  return ok;
}

void ger (int l, int c, int mask, vector<vector<int>>& mat)
{
  if (l == 3 && c == 0)
  {
    for (int i = 0; i < 3; i++)
      if (magicSquare(mat))
      {
        int aux = 0;
      
        for (int i = 0; i < 3; i++)
          for (int j = 0; j < 3; j++)
            aux += abs(mat[i][j] - in[i][j]);
        
        ans = min(ans, aux);
      }
  }
  else
  {  
    int nl = l, nc = c;
    
    nc++;
    if (nc == 3) { nc = 0; nl++; }
    
    for (int i = 0; i < 9; i++)
      if (mask & (1 << i))
      {
        mask ^= (1 << i);
        mat[l][c] = i + 1;        
        ger(nl, nc, mask, mat);
        mask ^= (1 << i);
      }
  }
}

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  ans = INF;
  
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      cin >> in[i][j];
  
  vector<vector<int>> mat(3, vector<int> (3));
  
  ger(0, 0, 511, mat);
  
  cout << ans << '\n';
}
