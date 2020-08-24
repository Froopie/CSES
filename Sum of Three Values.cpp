#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 5e3 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll a[MAXN];
map<ll,int> mp;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  ll x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] = i+1;
  }
  for (int i = 0; i < n; i++) {
    if (mp[a[i]] == i+1)
      mp.erase(a[i]);
    for (int j = 0; j < i; j++)
      if (mp.find(x-a[i]-a[j]) != mp.end()) {
        cout << j+1 << ' ' << i+1 << ' ' << mp[x-a[i]-a[j]];
        return 0;
      }
  }
  cout << "IMPOSSIBLE";
  return 0;
}