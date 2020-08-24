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
  int n, m;
  cin >> n >> m;
  multiset<int> se;
  while (n--) {
    int k; cin >> k;
    se.insert(k);
  }
  while (m--) {
    int k; cin >> k;
    auto l = se.lower_bound(k+1);
    if (l == se.begin())
      cout << -1;
    else {
      l--;
      cout << *l;
      se.erase(l);
    }
    cout << '\n';
  }
  return 0;
}