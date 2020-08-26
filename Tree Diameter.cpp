#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 5e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<int> ve[MAXN];
 
pair<int,int> dfs(int u, int p) {
  pair<int,int> a = {0, 0}, ret = {0, 0};
  for (int v : ve[u]) {
    if (v == p) continue;
    pair<int,int> t = dfs(v, u);
    t.first++;
    ret.second = max(t.second, ret.second);
    if (a.first < t.first) {
      a.second = a.first;
      a.first = t.first;
      ret.first = a.first;
    }
    else if (a.second < t.first)
      a.second = t.first;
  }
  ret.second = max(ret.second, a.first+a.second);
  return ret;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    ve[u].pb(v);
    ve[v].pb(u);
  }
  cout << dfs(1, 1).second;
  return 0;
}
