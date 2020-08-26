#include <iostream>
#include <string.h>
#include <map>
#include <set>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
string s;
int n, m;
ll pre[MAXN], pp[MAXN], inv[MAXN];
 
void modd(ll &a) {
  if (a >= mod)
    a %= mod;
}
 
ll po(ll a, ll p) {
  if (!p) return 1;
  ll x = po(a,(p>>1));
  x = (x*x);
  modd(x);
  if ((p&1)) x = (a*x);
  modd(x);
  return x;
}
 
ll gets(int i, int w) {
  ll ret = pre[i+w-1];
  if (i) {
    ret -= pre[i-1];
    ret += mod;
    if (ret >= mod)
      ret %= mod;
  }
  ret *= inv[i];
  if (ret >= mod)
    ret %= mod;
  return ret;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  n = s.size();
  pp[0] = 1;
  inv[0] = 1;
  inv[1] = po(1337,mod-2);
  for (int i = 0; i+1 < n; i++) {
    pp[i+1] = (pp[i]*(1337));
    if (pp[i+1] >= mod) pp[i+1] %= mod;
    inv[i+1] = (inv[i]*inv[1]);
    modd(inv[i+1]);
  }
  pre[0] = (s[0]-'a'+1);
  for (int i = 0; i < n-1; i++) {
    pre[i+1] = (pre[i] + (s[i+1]-'a'+1)*pp[i+1]);
    modd(pre[i+1]);
  }
  for(int i = 1; i < n; i++)
    if (gets(0,i) == gets(n-i,i))
      cout << i << ' ';
  return 0;
}
