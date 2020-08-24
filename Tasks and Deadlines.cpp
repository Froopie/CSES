#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int n;
struct pt{
  int a, d;
  bool operator<(pt &b) {
    return (b.a != a? a < b.a : d > b.d);
  }
};
vector<pt> ve;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  while (n--) {
    pt c;
    cin >> c.a >> c.d;
    ve.pb(c);
  }
  sort(all(ve));
  ll cur = 0, ans = 0;
  for (auto p : ve) {
    cur += p.a;
    ans += (p.d-cur);
  }
  cout << ans;
  return 0;
}