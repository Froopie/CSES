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
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    int cnt = 0;
    for (int i = 1; i*i <= x; i++) {
      if (x%i == 0 && x/i == i) {
        cnt += 1;
        break;
      }
      cnt += 2*(x%i == 0);
    }
    cout << cnt << '\n';
  }
  return 0;
}