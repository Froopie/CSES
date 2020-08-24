#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> ve(n);
  for (int i = 0; i < n; i++)
    cin >> ve[i].first >> ve[i].second;
  sort(all(ve));
  int cur = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    if (ve[i].first >= cur) {
      cur = ve[i].second;
      ans++;
    } else if (ve[i].second < cur)
      cur = ve[i].second;
  }
  cout << ans;
  return 0;
}