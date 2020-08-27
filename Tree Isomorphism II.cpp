#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 13;
const int mdd = 999999989;
const int mdc = 1e9 + 7;
using namespace std;
 
vector<int> ve[MAXN][2];
ll base, bb, bt = 1337;
int n;
 
pair<ll,pair<ll,ll>> Hash(int u, int p, int i, int et) {
  ll ra = base<<et, rb = bb<<et, rc = bt<<et;
  vector<pair<ll,pair<ll,ll>>> hashes;
  for (int v : ve[u][i])
    if (v != p)
      hashes.pb(Hash(v,u,i,et+1));
  sort(all(hashes));
  ll pa = base, pb = bb, pc = bt;
  for (auto k : hashes) {
    // Weird way to do this but it's chaotic and it worked
    ra = (ra+(k.first*pa))%mod;
    rb = (rb+(k.second.first*pb))%mdd;
    rc = (rc+(k.second.second)*pc)%mdc;
    pa = (pa*base)%mdc;
    pb = (pb*bb)%mod;
    pc = (pc*bt)%mdd;
    pc = (pc*(ra+rb-rc))%mdc;
  }
  return {ra,{rb,rc}};
}
 
vector<int> center(int id) {
  queue<int> qe;
  vector<int> ret;
  int dist[MAXN] = {}, deg[MAXN], maxi = 0;
  for (int i = 1; i <= n; i++) {
    deg[i] = ve[i][id].size();
    if (ve[i][id].size() == 1)
      qe.push(i);
  }
  while (qe.size()) {
    int t = qe.front();
    qe.pop();
    if (dist[t] == maxi)
      ret.pb(t);
    if (dist[t] > maxi) {
      maxi = dist[t];
      ret = {t};
    }
    for (int v : ve[t][id]) {
      deg[v]--;
      if (deg[v] == 1) {
        qe.push(v);
        dist[v] = dist[t]+1;
      }
    }
  }
  return ret;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  ll add = uniform_int_distribution<int>(0,100000)(rng);
  bt += add;
  if (bt%2 == 0) bt++;
  int t;
  cin >> t;
  for (int i = 100000; !base && !bb; i++) {
    bool pr = 1;
    for (int j = 2; j*j <= i && pr; j++)
      if (i%j == 0) pr = 0;
    if (pr) {
      ll rnd = uniform_int_distribution<int>(0,100)(rng);
      if (rnd > 75) {
        base = i;
      }
      if (rnd < 25) bb = i;
    }
  }
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++)
      ve[i][0].clear(), ve[i][1].clear();
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      ve[u][0].pb(v);
      ve[v][0].pb(u);
    }
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      ve[u][1].pb(v);
      ve[v][1].pb(u);
    }
    int c = center(0).back();
    vector<int> cc = center(1);
    auto hh = Hash(c,0,0,0);
    bool can = (Hash(cc[0],0,1,0) == hh || Hash(cc.back(),0,1,0) == hh);
    cout << (can? "YES\n" : "NO\n");
  }
  return 0;
}