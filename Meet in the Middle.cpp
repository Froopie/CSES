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
 
ll a[MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; ll x;
  cin >> n >> x;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  map<ll,ll> mp;
  for (int i = 0; i < (1<<(n/2)); i++) {
    ll cur = 0;
    for (int j = 0; j < n/2; j++) {
      if ((1<<j)&i)
        cur += a[j];
    }
    if (cur > x) continue;
    mp[cur]++;
  }
  ll ans = 0;
  for (int i = 0; i < (1<<((n+1)/2)); i++) {
    ll cur = 0;
    for (int j = n/2; j < n; j++) {
      if ((1<<(j-n/2))&i)
        cur += a[j];
    }
    if (mp.find(x-cur) != mp.end())
      ans += mp[x-cur];
  }
  cout << ans;
  return 0;
}
