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
 
int seg[4*MAXN];
 
void update(int p, int l, int r, int i, int v) {
  if (l > i || r < i) return;
  if (l == r) {
    seg[p] = v;
    return;
  }
  update(L(p),l, M(l,r), i, v);
  update(R(p), M(l,r)+1, r, i, v);
  seg[p] = min(seg[L(p)],seg[R(p)]);
}
 
int gets(int p, int l, int r, int i, int j) {
  if (l > j || r < i) return 1e9;
  if (l >= i && r <= j) return seg[p];
  return min(gets(L(p),l,M(l,r),i,j), gets(R(p),M(l,r)+1, r, i, j));
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    update(1, 1, n, i, c);
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << gets(1, 1, n, a, b) << '\n';
  }
  return 0;
}
