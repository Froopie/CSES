#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll po(ll a, ll b) {
  if (b == 0) return 1;
  ll p = po(a, b/2);
  p = (p*p)%mod;
  if (b&1) return (a*p)%mod;
  return p;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    ll a, b;
    cin >> a >> b;
    cout << po(a, b) << '\n';
  }
  return 0;
}