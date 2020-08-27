#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
bool win[MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> p(k);
  for (int i = 0; i < k; i++)
    cin >> p[i];
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < k; j++)
      if (i-p[j] >= 0)
        win[i] = (win[i] || !win[i-p[j]]);
  for (int i = 1; i <= n; i++)
    cout << (win[i]? 'W' : 'L');
  return 0;
}