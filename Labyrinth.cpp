#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2500 + 5;
 
using namespace std;
 
char arr[MAXN][MAXN];
int dist[MAXN][MAXN];
string w = "ULDR";
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int n, m;
 
bool dispo(int i, int j) {
  return (i < n && j < m && min(i,j) >= 0 && arr[i][j] != '#' && !dist[i][j]);
}
 
bool dispo2(int i, int j) {
  return (min(i, j) >= 0 && i < n && j < m && arr[i][j] != '#');
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  pair<int,int> p, e;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 'A') p = {i,j};
      if (arr[i][j] == 'B') e = {i,j};
    }
  queue<pair<int,int>> qe;
  qe.push(p);
  dist[p.first][p.second] = 1;
  while (!qe.empty()) {
    auto cur = qe.front();
    qe.pop();
    if (arr[cur.first][cur.second] == 'B') break;
    for (int f = 0; f < 4; f++)
      if (dispo(cur.first+dir[f][0], cur.second+dir[f][1])) {
        qe.push({cur.first+dir[f][0], cur.second+dir[f][1]});
        dist[cur.first+dir[f][0]][cur.second+dir[f][1]] = 
        dist[cur.first][cur.second]+1;
      }
  }
  if (!dist[e.first][e.second])
    cout << "NO";
  else {
    cout << "YES\n" << dist[e.first][e.second]-1 << '\n';
    string k = "";
    while (e != p) {
      for (int f = 0; f < 4; f++)
        if (dispo2(e.first+dir[f][0], e.second+dir[f][1]) 
          && dist[e.first+dir[f][0]][e.second+dir[f][1]] < dist[e.first][e.second]
          && dist[e.first+dir[f][0]][e.second+dir[f][1]]) {
          e = {e.first+dir[f][0], e.second+dir[f][1]};
          k.pb(w[f]);
          break;
        }
    }
    reverse(all(k));
    cout << k;
  }
  return 0;
}