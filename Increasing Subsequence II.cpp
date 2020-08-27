#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#define all(c) c.begin(), c.end()
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define ff first
#define ss second
using ll = long long;
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll rand(ll a, ll b) {ll c = rng(); return a+((ll)abs(c))%(b-a+1);}
 
ll BIT[MAXN];
int x[MAXN];
int c;
map<int,int> mp;
 
void upd(int i, ll v) {
  for (; i <= c; i += i&-i) {
    BIT[i] += v;
    BIT[i] %= mod;
  }
}
 
ll gets(int i) {
  ll ret = 0;
  for (; i > 0; i -= i&-i) {
    ret += BIT[i];
    ret %= mod;
  }
  return ret;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    mp[x[i]];
  }
  for (auto &k : mp)
    k.second = ++c;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll t = gets(mp[x[i]]-1);
    ans += t+1;
    ans %= mod;
    upd(mp[x[i]],t+1);
  }
  cout << ans;
  return 0;
}
