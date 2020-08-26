#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
#define L(p) (p<<1)
#define R(p) (p<<1)+1
#define M(l,r) ((l+r)>>1)
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll BIT[MAXN];
 
void update(int i, ll v) {
  for (; i < MAXN; i += i&-i)
    BIT[i] += v;
}
 
ll gets(int i) {
  ll ret = 0;
  for (; i > 0; i -= i&-i)
    ret += BIT[i];
  return ret;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    update(i, c);
    update(i+1, -c);
  }
  while (q--) {
    int t, a, b, u;
    cin >> t >> a;
    if (t == 2)
    cout << gets(a) << '\n';
    else {
      cin >> b >> u;
      update(a, u);
      update(b+1, -u);
    }
  }
  return 0;
}