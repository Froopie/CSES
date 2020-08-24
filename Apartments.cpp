#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int>a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(all(a));
  sort(all(b));
  int app = 0, h = 0, ans = 0;
  while (h < m && app < n) {
    if (abs(a[app]-b[h]) <= k) {
      ans++;
      h++;
      app++;
    }
    while (abs(a[app]-b[h]) > k && b[h] < a[app] && h+1 <= m) h++;
    while (abs(a[app]-b[h]) > k && b[h] > a[app] && app+1 <= n) app++;
  }
  cout << ans;
  return 0;
}