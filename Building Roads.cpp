#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n, m, p[MAXN];
 
void init() {
  for (int i = 1; i <= n; i++)
    p[i] = i;
}
 
int find(int u) {
  return p[u] = (p[u] == u? u : find(p[u]));
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  init();
  while (m--) {
    int a, b;
    cin >> a >> b;
    p[find(a)] = find(b);
  }
  vector<int> ve;
  for (int i = 2; i <= n; i++)
    if (find(1) != find(i)) {
      ve.pb(i);
      p[find(i)] = find(1);
    }
  cout << ve.size() << '\n';
  for (int k : ve)
    cout << 1 << ' ' << k << '\n';
  return 0;
}