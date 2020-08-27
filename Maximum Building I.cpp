#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e3 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
string a[MAXN];
int pre[MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (a[i][j] == '*')
        pre[j] = 0;
      else pre[j]++;
    vector<int> ve = {0};
    ans = max(ans, pre[0]);
    for (int j = 1; j < m; j++) {
      while (ve.size() && pre[j] < pre[ve.back()]) {
        int id = ve.back();
        ve.pop_back();
        int cur = pre[id]*j;
        if (ve.size())
          cur = pre[id]*(j-ve.back()-1);
        ans = max(ans, cur);
      }
      ve.pb(j);
    }
    while (ve.size()) {
        int id = ve.back();
        ve.pop_back();
        int cur = pre[id]*m;
        if (ve.size())  
          cur = pre[id]*(m-ve.back()-1);
        ans = max(ans, cur);
      }
  }
  cout << ans;
  return 0;
}