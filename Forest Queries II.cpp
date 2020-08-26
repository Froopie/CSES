#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e3 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n, q, BIT[MAXN][MAXN];
 
void up(int i, int j, int v) {
  for (; i <= n; i += i&-i)
    for (int jj = j; jj <= n; jj += jj&-jj)
      BIT[i][jj] += v;
}
 
int gets(int i, int j) {
  int ret = 0;
  for (; i > 0; i -= i&-i)
    for (int jj = j; jj > 0; jj -= jj&-jj)
      ret += BIT[i][jj];
  return ret;
}
 
int getr(int x, int y, int a, int b) {
  int ret = gets(a,b);
  ret -= gets(x-1,b) + gets(a,y-1);
  ret += gets(x-1,y-1);
  return ret;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      if (c == '*')
        up(i,j,1);
    }
  while (q--) {
    int t, x, y, a, b;
    cin >> t >> x >> y;
    if (t == 1) {
      int v = (getr(x,y,x,y)?-1:1);
      up(x,y,v);
    } else {
      cin >> a >> b;
      cout << getr(x,y,a,b) << '\n';
    }
  }
  return 0;
}