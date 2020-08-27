#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x, n;
  ll ans = 0;
  multiset<int> se;
  cin >> x >> n;
  for (int i = 0; i < n; i++) {
    int k; cin >> k;
    se.insert(k);
  }
  while (se.size() > 1) {
    int a = *se.begin();
    se.erase(se.begin());
    a += *se.begin();
    se.erase(se.begin());
    ans += 1LL*a;
    se.insert(a);
  }
  cout << ans;
  return 0;
}
