#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
#define L(p) p<<1
#define R(p) (p<<1)+1
#define M(l,r) ((l+r)>>1)
const int MAXN = 2e5 + 5;
 
using namespace std;
 
int arr[MAXN], seg[4*MAXN];
 
void build(int p, int l, int r) {
  if (l == r) seg[p] = arr[l];
  else {
    build(L(p), l, M(l,r));
    build(R(p), M(l,r)+1, r);
    seg[p] = max(seg[L(p)], seg[R(p)]); 
  }
}
 
void update(int p, int l, int r, int i, int v) {
  if (l > i || r < i) return;
  if (l == r) seg[p] += v;
  else {
    update(L(p), l, M(l,r), i, v);
    update(R(p), M(l,r)+1, r, i, v);
    seg[p] = max(seg[L(p)], seg[R(p)]);
  }
}
 
int get(int p, int l, int r, int i, int j) {
  if (l > j || r < i) return -1;
  if (l >= i && r <= j) return seg[p];
  return max(get(L(p), l, M(l,r), i, j), get(R(p), M(l,r)+1, r, i, j));
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr[i];
  build(1, 0, n-1);
  while (m--) {
    int k; cin >> k;
    int l = 0, r = n-1, ans = -1;
    while (r-l >= 0) {
      int mid = M(l,r);
      if (get(1, 0, n-1, 0, mid) >= k) {
        ans = mid;
        r = mid-1;
      }
      else l = mid+1;
    }
    cout << ans+1 << ' ';
    update(1, 0, n-1, ans, -k);
  }
  return 0;
}
