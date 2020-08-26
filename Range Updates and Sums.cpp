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
 
ll seg[4*MAXN], lazy[4*MAXN], lz[4*MAXN];
 
void prop(int p, int l, int r) {
  if (lz[p] != 0) {
    seg[p] = (r-l+1)*lz[p];
    if (l != r) {
      lz[L(p)] = lz[R(p)] = lz[p];
      lazy[L(p)] = lazy[R(p)] = 0;
    }
    lz[p] = 0;
  }
  if (lazy[p] != 0) {
    seg[p] += (r-l+1)*lazy[p];
    if (l != r) {
      lazy[L(p)] += lazy[p];
      lazy[R(p)] += lazy[p];
    }
    lazy[p] = 0;
  }
}
 
void upd(int p, int l, int r, int i, int j, ll x) {
  prop(p,l,r);
  if (l > j || r < i) return;
  if (l >= i && r <= j) {
    lz[p] = x;
    lazy[p] = 0;
    prop(p,l,r);
    return;
  }
  upd(L(p),l,M(l,r),i,j,x);
  upd(R(p),M(l,r)+1,r,i,j,x);
  seg[p] = seg[L(p)]+seg[R(p)];
}
 
void incr(int p, int l, int r, int i, int j, ll x) {
  prop(p,l,r);
  if (l > j || r < i) return;
  if (l >= i && r <= j) {
    lazy[p] = x;
    prop(p,l,r);
    return;
  }
  incr(L(p),l,M(l,r),i,j,x);
  incr(R(p),M(l,r)+1,r,i,j,x);
  seg[p] = seg[L(p)]+seg[R(p)];
}
 
ll gets(int p, int l, int r, int i, int j) {
  prop(p,l,r);
  if (l > j || r < i) return 0;
  if (l >= i && r <= j) return seg[p];
  return gets(L(p),l,M(l,r),i,j)+gets(R(p),M(l,r)+1,r,i,j);
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    incr(1,1,n,i+1,i+1,x);
  }
  while (q--) {
    int t, a, b;
    ll x;
    cin >> t >> a >> b;
    if (t == 1) {
      cin >> x;
      incr(1,1,n,a,b,x);
    } else if (t == 2) {
      cin >> x;
      upd(1,1,n,a,b,x);
    } else
      cout << gets(1,1,n,a,b) << '\n';
  }
  return 0;
}
