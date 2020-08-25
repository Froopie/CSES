#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2500 + 5;
 
using namespace std;
 
string arr[MAXN];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int n, m;
 
bool dispo(int i, int j) {
  return (i < n && j < m && min(i,j) >= 0 && arr[i][j] == '.');
}
 
void dfs(int i, int j) {
  arr[i][j] = '#';
  for (int m = 0; m < 4; m++)
    if (dispo(i+dir[m][0], j+dir[m][1]))
      dfs(i+dir[m][0], j+dir[m][1]);
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (dispo(i, j)) {
        ans++;
        dfs(i, j);
      }
  cout << ans;
  return 0;
}
