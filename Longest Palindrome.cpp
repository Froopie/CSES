#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;
const ll p1 = 999999797, p2 = 999999937;
 
using namespace std;
 
ll p[2][MAXN];
ll pre[2][MAXN], suf[2][MAXN];
int sz;
 
pair<ll,ll> getpre(int i, int n) {
  pair<ll,ll> h;
  h.first = (pre[0][i+n]-(i>0?pre[0][i-1]:0)+1LL*mod)%mod;
  h.second = (pre[1][i+n]-(i>0?pre[1][i-1]:0)+1LL*mod)%mod;
  h.first = (h.first*p[0][sz-i-1])%mod;
  h.second = (h.second*p[1][sz-i-1])%mod;
  return h;
}
 
pair<ll,ll> getsuf(int i, int n) {
  pair<ll,ll> h;
  h.first = (suf[0][i]-suf[0][i+n+1]+1LL*mod)%mod;
  h.second = (suf[1][i]-suf[1][i+n+1]+1LL*mod)%mod;
  h.first = (h.first*p[0][i+n])%mod;
  h.second = (h.second*p[1][i+n])%mod;
  return h;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string n;
  cin >> n;
  sz = n.size();
  p[0][0] = 1; p[1][0] = 1;
  for (int i = 1; i < sz+5; i++) {
    p[0][i] = (p1*p[0][i-1])%mod;
    p[1][i] = (p2*p[1][i-1])%mod;
  }
  pre[0][0] = (n[0]-'a'+1);
  pre[1][0] = (n[0]-'a'+1);
  for (int i = 1; i < sz; i++) {
    pre[0][i] = (pre[0][i-1]+((n[i]-'a'+1)*p[0][i])%mod)%mod;
    pre[1][i] = (pre[1][i-1]+((n[i]-'a'+1)*p[1][i])%mod)%mod;
  }
  suf[0][sz-1] = (n[sz-1]-'a'+1);
  suf[1][sz-1] = (n[sz-1]-'a'+1);
  for (int i = sz-2; i >= 0; i--) {
    suf[0][i] = (suf[0][i+1]+((n[i]-'a'+1)*p[0][sz-i-1])%mod)%mod;
    suf[1][i] = (suf[1][i+1]+((n[i]-'a'+1)*p[1][sz-i-1])%mod)%mod;
  }
  ll ans = 1, id = 0;
  for (int i = 1; i < sz; i++) {
    int l = 1, r = min(i, sz-i-1);
    while (r >= l) {
      int mid = (r+l)>>1;
      pair<ll,ll> h1 = getsuf(i-mid, mid-1);
      pair<ll,ll> h2 = getpre(i+1, mid-1);
      if (h1 == h2) {
        if (ans < (mid<<1)+1) {
          ans = (mid<<1)+1;
          id = i-mid;
        }
        l = mid+1;
      } else r = mid-1;
    }
    l = 1, r = min(i, sz-i);
    while (r >= l) {
      int mid = (l+r)>>1;
      pair<ll,ll> h1 = getsuf(i-mid, mid-1);
      pair<ll,ll> h2 = getpre(i, mid-1);
      if (h1 == h2) {
        if (ans < (mid<<1)) {
          ans = mid<<1;
          id = i-mid;
        }
        l = mid+1;
      } else r = mid-1;
    }
  }
  cout << n.substr(id, ans);
  return 0;
}
