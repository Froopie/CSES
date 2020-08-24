#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e4 + 5;
 
using namespace std;
 
int dir[6][2] = {-2, 1, 1, -2, 2, -1, -1, 2, -2, -1, -1, -2};
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; ll ans[MAXN];
  cin >> n;
  ans[2] = 6;
  cout << 0 << "\n";
  if (n > 1) cout << 6 << '\n';
  for (ll i = 3; i <= n; i++) {
    ans[i] = ans[i-1]+(i-1)*(i-1)*(2*i-1)-2;
    ll toadd = (2*i-1)*(2*i-2);
    for (int j = 1; j < i; j++)
      for (int m = 0; m < 6; m++) {
        int y = j+dir[m][0], x = i+dir[m][1];
        if (y > 0 && y <= i && x > 0 && x <= i) {
          if (y == i) toadd -= 2;
          else ans[i] -= 2;
        }
      }
    ans[i] += toadd>>1;
    cout << ans[i] << '\n';
  }
  return 0;
}