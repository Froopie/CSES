#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e3 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
char a[MAXN][MAXN];
char dir[3][3];
int n, m;
 
struct pt{
  int x, y;
  bool safe;
  pt(int i=0, int j=0, bool c=0) {
    y = i; x = j;
    safe = c;
  }
  bool operator!=(pt b) {
    return !(b.y == y && b.x == x && b.safe == safe);
  }
};
 
pt par[MAXN][MAXN];
 
bool dispo(int i, int j) {
  return min(i,j) >= 0 && i <n && j < m && a[i][j] != 'M' && a[i][j] != '#';
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  dir[2][1] = 'U';
  dir[0][1] = 'D';
  dir[1][2] = 'L';
  dir[1][0] = 'R';
  cin >> n >> m;
  pt man;
  queue<pt> qe;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'M')
        qe.push(pt(i,j,0));
      if (a[i][j] == 'A')
        man = pt(i,j,1);
    }
  qe.push(man);
  pt start;
  bool can = 0;
  while (qe.size()) {
    auto c = qe.front();
    qe.pop();
    if ((c.y == 0 || c.y == n-1 || c.x == 0 || c.x == m-1) && c.safe) {
      can = 1;
      start = c;
    }
    for (int i = -1; i <= 1; i++)
      for (int j = -1; j <= 1; j++) {
        if (abs(i)+abs(j) != 1) continue;
        if (dispo(c.y+i,c.x+j)) {
          qe.push(pt(c.y+i, c.x+j, c.safe));
          if (c.safe)
            par[i+c.y][j+c.x] = pt(c.y,c.x,1);
          a[c.y+i][c.x+j] = '#';
        }
      }
  }
  if (can) {
    cout << "YES\n";
    vector<char> mov;
    while (start != man) {
      int yy = par[start.y][start.x].y-start.y+1;
      int xx = par[start.y][start.x].x-start.x+1;
      mov.pb(dir[yy][xx]);
      start = par[start.y][start.x];
    }
    reverse(all(mov));
    cout << mov.size() << '\n';
    for (char c : mov)
      cout << c;
  }
  else cout << "NO";
  return 0;
}