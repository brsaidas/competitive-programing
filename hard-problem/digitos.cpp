#include <bits/stdc++.h>

using namespace std;

#define N 1000

char a[N];

string nextInt (string num)
{
  reverse(num.begin(), num.end());

  string ans;

  int aux = (num[0] - '0') + 1;

  int dig = aux % 10;
  int carry = aux/10;

  ans.push_back((char) (dig + '0'));

  for (int i = 1; i < (int) num.size(); i++)
  {
    aux = carry + num[i] - '0';

    dig = aux % 10;
    carry = aux/10;

    ans.push_back((char) (dig + '0'));
  }

  if (carry == 1) ans.push_back((char) (1 + '0'));

  reverse(ans.begin(), ans.end());

  return ans;
}

int main ()
{
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < n; i++)
  {
    string num;
    for (int j = 0; j <= i; j++) num += a[j];

    if (i == n - 1)
    {
      cout << num << '\n';
      return 0;
    }

    int saveI = i;
    string aux = num;

    while (1)
    {
      if (i > n - 1)
      {
        break;
      }
      else
      {
        int beg = i - (int) aux.size() + 1;
        int end = i;

        string suc;
        for (int j = beg; j <= end; j++) suc += a[j];

        if (aux == suc)
        {
          if (i == n - 1)
          {
            cout << num << '\n';
            return 0;
          }
        }
        else
        {
          break;
        }
      }

      aux = nextInt(aux);
      i += (int) aux.size();
    }

    i = saveI;
  }
}
