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
  ll n; cin >> n;
  ll ans = 0;
  for (int i = 0; i <= 50; i++)
    ans += (n+1)/(1LL<<(i+1))*(1LL<<i)
    + max((n+1)%(1LL<<(i+1))-(1LL<<i), 0LL);
  cout << ans;
  return 0;
}