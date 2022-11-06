#include <bits/stdc++.h>

using namespace std;

#define N 100000

int lazy[4*N];
int tree[4*N][9];
bool hasLazy[4*N];

void build (int no, int i, int j)
{
  if (i == j)
  {
    tree[no][1] = 1;
    return;
  }
  
  int mid = (i + j) >> 1;
  
  build(2*no, i, mid);
  build(2*no + 1, mid + 1, j);
  
  for (int k = 0; k < 9; k++)
    tree[no][k] = tree[2*no][k] + tree[2*no + 1][k];
}

void propagation (int no, int i, int j)
{
  if (hasLazy[no])
  {
    vector<int> tmp(9);
    
    for (int k = 0; k < 9; k++)
      tmp[(k + lazy[no]) % 9] += tree[no][k];
    
    for (int k = 0; k < 9; k++)
      tree[no][k] = tmp[k];
    
    if (i != j)
    {
      lazy[2*no] += lazy[no];
      lazy[2*no + 1] += lazy[no];
      
      hasLazy[2*no] = true;
      hasLazy[2*no + 1] = true;
    }      
    
    lazy[no] = 0;
    hasLazy[no] = false;
  }
}

void update (int no, int i, int j, int a, int b, int v)
{
  propagation(no, i, j);
  
  if (b < i || j < a) return;
  
  if (a <= i && j <= b)
  {
    lazy[no] = v;
    hasLazy[no] = true;
    
    propagation(no, i, j);
    
    return;
  }
  
  int mid = (i + j) >> 1;
  
  update(2*no, i, mid, a, b, v);
  update(2*no + 1, mid + 1, j, a, b, v);

  for (int k = 0; k < 9; k++)
    tree[no][k] = tree[2*no][k] + tree[2*no + 1][k];
}

vector<int> query (int no, int i, int j, int a, int b)
{
  propagation(no, i, j);
  
  if (b < i || j < a) return vector<int> (9);
  
  if (a <= i && j <= b)
  {
    vector<int> ret(9);
    
    for (int k = 0; k < 9; k++)
      ret[k] = tree[no][k];
    
    return ret;
  }
  
  int mid = (i + j) >> 1;

  vector<int> l = query(2*no, i, mid, a, b);
  vector<int> r = query(2*no + 1, mid + 1, j, a, b);
  
  vector<int> ret(9);
  
  for (int k = 0; k < 9; k++) ret[k] = l[k] + r[k];

  return ret;
}

int maxFreq (vector<int> v)
{
  int qtd = 0, f = -1;
    
  for (int i = 0; i < v.size(); i++)
    if (qtd <= v[i]) { qtd = v[i]; f = i; }
    
  return f;
}

int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int n, q; cin >> n >> q;
  
  build(1, 1, n);
  
  while (q--)
  {
    int a, b; cin >> a >> b;
    update(1, 1, n, a, b, maxFreq(query(1, 1, n, ++a, ++b)));
  }
  
  for (int i = 1; i <= n; i++)
    cout << maxFreq(query(1, 1, n, i, i)) << '\n';
}
