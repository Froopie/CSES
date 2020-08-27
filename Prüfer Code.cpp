#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 5e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  set<int> se;
  int cur[MAXN] = {}, arr[MAXN], n;
  cin >> n;
  vector<pair<int,int>> ans;
  for (int i = 0; i < n-2; i++) {
    cin >> arr[i];
    cur[arr[i]]++;
  }
  for (int i = 1; i <= n; i++)
    if (cur[i] == 0) se.insert(i);
  for (int i = 0; i < n-3; i++) {
    int t = *se.begin();
    se.erase(se.begin());
    ans.pb({t, arr[i]});
    cur[arr[i]]--;
    if (cur[arr[i]] == 0) se.insert(arr[i]);
  }
  ans.pb({*se.begin(), arr[n-3]});
  se.erase(se.begin());
  ans.pb({*se.begin(), arr[n-3]});
  for (auto k : ans) cout << k.first << ' ' << k.second << '\n';
  return 0;
}