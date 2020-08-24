#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll n, ans=-1e15, a, b, x, pre[MAXN];
multiset<ll> se;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    pre[i] = x+pre[i-1];
    if (i-a >= 0) se.insert(pre[i-a]);
    if (i >= a)
      ans = max(ans,pre[i]-*se.begin());
    if (i-b >= 0)
      se.erase(se.find(pre[i-b]));
  }
  cout << ans;
  return 0;
}