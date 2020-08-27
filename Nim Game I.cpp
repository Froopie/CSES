#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int x = 0;
    while (n--) {
      int c;
      cin >> c;
      x ^= c;
    }
    if (x) cout << "first\n";
    else cout << "second\n";
  }
  return 0;
}
