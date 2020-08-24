#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll n, ans, a, pre;
map<ll,int> mp;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  mp[0] = 1;
  for (int i = 0; i < n; i++) {
    cin >> a;
    a %= n; a += n;
    pre += a; pre %= n;
    ans += mp[pre];
    mp[pre]++;
  }
  cout << ans;
  return 0;
}