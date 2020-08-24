#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll po(ll a, ll p) {
  if (!p) return 1;
  ll x = po(a,p>>1);
  x = (x*x)%mod;
  if (p&1) x = (x*a)%mod;
  return x;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  cout << po(2,n);
  return 0;
}