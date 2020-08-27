#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll po(ll a, ll p, ll md) {
  if (!p) return 1;
  ll x = po(a,p>>1,md);
  x = (x*x)%md;
  if ((p&1))
    x = (x*a)%md;
  return x;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    ll a,b,c;
    cin >> a >> b >> c;
    cout << po(a,po(b,c,mod-1),mod) << '\n';
  }
  return 0;
}