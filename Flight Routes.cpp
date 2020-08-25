#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<pair<int,ll>> ve[MAXN];
multiset<ll> se[MAXN];
int n, m, k;
 
void fix(int u) {
  if ((int)se[u].size() > k) 
    se[u].erase(se[u].find(*se[u].rbegin())); 
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    ve[a].pb({b, c});
  }
  for (int i = 1; i <= n; i++) se[i].insert(1e16);
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> qe;
  qe.push({0, 1});
  se[1].insert(0);
  fix(1);
  while (!qe.empty()) {
    ll w = qe.top().first;
    int u = qe.top().second;
    qe.pop();
    if ((int)se[u].size() == k && *se[u].rbegin() < w) continue;
    for (auto t : ve[u]) {
      int v = t.first;
      ll d = t.second;
      if (w+d < *se[v].rbegin() || (w+d == *se[v].rbegin() && (int)se[v].size() < k)) {
        se[v].insert(w+d);
        qe.push({w+d, v});
        fix(v);
      }
    }
  }
  for (ll k : se[n]) cout << k << ' ';
  return 0;
}