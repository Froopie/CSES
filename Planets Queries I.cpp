#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int p[MAXN][30];
int n;
 
void build() {
  for (int j = 1; j < 30; j++)
    for (int i = 1; i <= n; i++)
      p[i][j] = p[p[i][j-1]][j-1];
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> p[i][0];
  build();
  while (q--) {
    int x, k;
    cin >> x >> k;
    for (int i = 0; i < 30; i++)
      if (((1<<i)&k))
        x = p[x][i];
    cout << x << '\n';
  }
  return 0;
}
