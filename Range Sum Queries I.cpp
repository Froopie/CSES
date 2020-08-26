#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll pre[MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> pre[i];
    pre[i] += pre[i-1];
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    cout << pre[b]-pre[a-1] << '\n';
  }
  return 0;
}