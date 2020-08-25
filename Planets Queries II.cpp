#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
pair<bool,int> in[MAXN];
int len[MAXN], vis[MAXN], succ[MAXN][(const int)log2(MAXN)+2];
 
void build(int i) {
  vis[i] = 1;
  int s = succ[i][0];
  if (vis[s] == 2) {
    len[i] = len[s]+1;
    if (!in[s].first) in[i].second = in[s].second;
    else in[i].second = s;
  }
  else if (vis[s] == 1) {
    len[i] = 0;
    in[i].first = 1; 
    in[i].second = s;
  }
  else {
    build(s);
    len[i] = len[s]+1;
    in[i] = in[s];
    if (in[s].second == s) {
      in[i].first = 0;
      in[i].second = s;
    }
  }
  for (int j = 1; (1<<j) <= len[i]+1; j++)
    succ[i][j] = succ[succ[i][j-1]][j-1];
  vis[i] = 2;
}
 
int su(int a, int l) {
  if (l < 0) return -1;
  for (int i = 18; i >= 0; i--)
    if (((1<<i)&l)) a = succ[a][i];
  return a;
}
 
int f(int a, int b) {
  if ((in[in[a].second].second != in[in[b].second].second)) 
    return -1;
  if (len[b] > len[a] && !in[b].first) return -1;
  if (in[a].first && !in[b].first) return -1;
  if (!in[b].first && !in[a].first && su(a, len[a]-len[b]) != b) return -1;
  if (in[b].first && !in[a].first) return len[a]-len[in[a].second]+f(in[a].second, b);
  if (len[a] >= len[b]) return len[a]-len[b];
  return len[in[a].second]-len[b]+1+len[a];
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> succ[i][0];
  for (int i = 1; i <= n; i++)
    if (vis[i] != 2) build(i);
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << f(a, b) << '\n';
  }
  return 0;
}