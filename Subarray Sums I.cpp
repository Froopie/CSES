#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n, x, a[MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int l = 0, r = -1, ans = 0, s = 0;
  while (l < n) {
    while (s < x && r+1 < n)
      s += a[++r];
    while (s > x)
      s -= a[l++];
    ans += (s == x);
    if (s == x || r+1 == n) s -= a[l++];
  }
  cout << ans;
  return 0;
}