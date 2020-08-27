#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long()
const int MAXN = 1e2 + 5, MAX = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  int arr[MAXN][3];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[j][i];
  vector<pair<int,int>> ve;
  for (int i = 0; i < n; i++) {
    int j = 1; 
    while (j <= arr[i][2]) {
      ve.pb({arr[i][0]*j, arr[i][1]*j});
      arr[i][2] -= j;
      j *= 2;
    }
    j = arr[i][2];
    if (j) ve.pb({arr[i][0]*j, arr[i][1]*j});
  }
  int maxi[MAX] = {};
  for (auto i : ve)
    for (int j = x-i.first; j >= 0; j--)
      maxi[j+i.first] = max(maxi[j]+i.second, maxi[j+i.first]);
  cout << maxi[x];
  return 0;
}
