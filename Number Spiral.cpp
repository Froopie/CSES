#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    ll x, y;
    cin >> y >> x;
    if ((y <= x && x&1) || (y >= x && !(y&1))) {
      if (x < y) swap(x, y);
      cout << x*x-y+1 << '\n';
    }
    else {
      if (x > y) swap(x, y);
      y--;
      cout << y*y+x << '\n';
    }
  }
  return 0;
}