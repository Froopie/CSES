#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
#define u second
#define w first.first
#define k first.second
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
vector<pair<int,ll>> ve[MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  ll dist[2][MAXN];
  dist[1][0] = dist[1][1] = 0;
  for (int i = 2; i < MAXN; i++)
    dist[0][i] = dist[1][i] = 10000000000000000LL;
  cin >> n >> m;
  while (m--) {
    int a, b; ll c;
    cin >> a >> b >> c;
    ve[a].pb({b, c});
  }
  priority_queue<pair<pair<ll,int>,int>, vector<pair<pair<ll,int>,int>>, greater<pair<pair<ll,int>,int>>> qe;
  qe.push({{0, 1}, 1});
  while (!qe.empty()) {
    auto t = qe.top();
    qe.pop();
    if (t.w > dist[t.k][t.u] || t.w > dist[1][t.u])
      continue;
    for (auto v : ve[t.u]) {
      if (t.w+v.second < dist[t.k][v.first]) {
        dist[t.k][v.first] = t.w+v.second;
        qe.push({{t.w+v.second, t.k}, v.first});
      }
      if (t.k && t.w+v.second/2 < dist[0][v.first]) {
        dist[0][v.first] = t.w+v.second/2;
        qe.push({{t.w+v.second/2, 0}, v.first});
      }
    }
  }
  cout << dist[0][n];
  return 0;
}