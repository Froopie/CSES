// Had to use randomisation for my base because someone kept hacking my solutions
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e6 + 5;
const int MAXK = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll rand(ll a, ll b) {ll c = rng(); return a+((ll)abs(c))%(b-a+1);}
 
string s, a[MAXK];
int n, m;
ll pre[5005], pp[5005], inv[5005];
int dp[5005];
map<pair<ll,int>,ll> mp;
set<int> sz;
 
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
 
int rec(int id) {
  if (id == m) return 1;
  int &ret = dp[id];
  if (ret != -1) return ret;
  ret = 0;
  for (auto i : sz) {
    if (id+i > m) break;
    ll temp = gets(id,i);
    if (mp.find(make_pair(temp,i)) == mp.end()) continue;
    ret += (mp[{temp,i}]*rec(id+i))%mod;
    ret %= mod;
  }
  return ret;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(dp,-1,sizeof dp);
  cin >> s >> n;
  m = s.size();
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ll diff = rand(1023,534554523349437);
  diff += 31387 + (diff%2);
  pp[0] = 1;
  inv[0] = 1;
  inv[1] = po(diff,mod-2);
  for (int i = 0; i+1 < m; i++) {
    pp[i+1] = (pp[i]*(diff));
    if (pp[i+1] >= mod) pp[i+1] %= mod;
    inv[i+1] = (inv[i]*inv[1]);
    modd(inv[i+1]);
  }
  pre[0] = (s[0]-'a'+1);
  for (int i = 0; i < m-1; i++) {
    pre[i+1] = (pre[i] + (s[i+1]-'a'+1)*pp[i+1]);
    modd(pre[i+1]);
  }
  for (int i = 0; i < n; i++) {
    ll h = a[i][0]-'a'+1;
    for (int j = 0; j+1 < (int)a[i].size(); j++) {
      h = (h + (a[i][j+1]-'a'+1)*pp[j+1]);
      modd(h);
    }
    sz.insert(a[i].size());
    mp[{h,a[i].size()}]++;
  }
  cout << rec(0);
  return 0;
}