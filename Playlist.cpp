#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, arr[MAXN];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  map<int,int> mp;
  int cur = 0;
  int l = 0, r = -1, ans = 0;
  while (r < n-1) {
    while (r < n-1 && cur == 0) {
      r++;
      mp[arr[r]]++;
      if (mp[arr[r]] == 2) {
        ans = max(ans, r-l);
        cur++;
      }
    }
    while (cur && l < r) {
      mp[arr[l]]--;
      if (mp[arr[l]] == 1) cur--;
      l++;
    }
  }
  ans = max(ans, r-l+1);
  cout << ans;
  return 0;
}