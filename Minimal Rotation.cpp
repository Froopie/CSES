#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;
ll p1 = 31, p2 = 53;
 
using namespace std;
 
ll p[2][MAXN]; int sz, mid;
pair<ll,ll> _hash[MAXN];
 
void calc() {
  p[0][0] = p[1][0] = 1;
  for (int i = 1; i <= 1e6; i++) {
    p[0][i] = (p[0][i-1]*p1)%mod;
    p[1][i] = (p[1][i-1]*p2)%mod;
  }
}
 
pair<ll,ll> get(int i) {
  pair<ll,ll> h;
  h.fi = _hash[min(sz-1, i+mid-1)].fi-(i > 0? _hash[i-1].fi : 0)+mod;
  h.fi %= mod;
  if (mid+i-1-sz > 0) { 
    h.fi += (_hash[mid-(sz-i+1)].fi*p[0][sz])%mod;
    h.fi %= mod;
  }
  h.se = _hash[min(sz-1, i+mid-1)].se-(i > 0? _hash[i-1].se : 0)+mod;
  h.se %= mod;
  if (mid+i-1-sz > 0) {
    h.se += (_hash[mid-(sz-i+1)].se*p[1][sz])%mod;
    h.se %= mod;
  }
  return h;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  sz = s.size();
  int cur = 0;
  calc();
  _hash[0].fi = _hash[0].se = s[0]-'a'+1;
  for (int i = 1; i < sz; i++) {
    _hash[i].fi = ((p[0][i]*(s[i]-'a'+1))%mod+_hash[i-1].fi)%mod;
    _hash[i].se = ((p[1][i]*(s[i]-'a'+1))%mod+_hash[i-1].se)%mod;
  }
  for (int i = 1; i < sz; i++) {
    int l = 1, r = sz;
    int n = sz;
    while (l <= r) {
      mid = (l+r)>>1;
      pair<ll,ll> h1 = get(i);
      pair<ll,ll> h2 = get(cur);
      h2.fi = (h2.fi*p[0][i-cur])%mod;
      h2.se = (h2.se*p[1][i-cur])%mod;
      if (h1 != h2) {
        n = mid;
        r = mid-1;
      }
      else l = mid+1;
    }
    if (n == sz) continue;
    if (s[(i+n-1)%sz] < s[(cur+n-1)%sz]) cur = i;
  }
  cout << s.substr(cur) << s.substr(0, cur);
  return 0;
}