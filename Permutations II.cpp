#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e3 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll ans[MAXN];
 
ll f(ll n) {
  ll &ret = ans[n];
  if (ret != -1) return ret;
  return ret = (((((n+1)*f(n-1))%mod-((n-2)*f(n-2))%mod)%mod+
  (-((n-5)*f(n-3))%mod+((n-3)*f(n-4))%mod)%mod+mod)%mod+mod)%mod;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  memset(ans, -1, sizeof ans);
  ans[2] = ans[3] = 0;
  ans[1] = ans[0] = 1;
  cout << f(n);
  return 0;
}
