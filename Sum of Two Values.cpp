#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n, x, a[MAXN];
map<int,int> mp;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] = i+1;
  }
  for (int i = 0; i < n; i++)
    if (mp[x-a[i]] != 0 && i+1 != mp[x-a[i]]) {
      cout << i+1 << ' ' << mp[x-a[i]];
      return 0;
    }
  cout << "IMPOSSIBLE";
  return 0;
}