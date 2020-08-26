#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
#define L(p) (p<<1)
#define R(p) (p<<1)|1
#define M(l,r) ((l+r)>>1)
const int MAXN = 2e5 + 5;
 
using namespace std;
 
struct node{
  ll left, right, maxi, sum;
} seg[4*MAXN];
 
ll arr[MAXN];
 
void f(int p) {
  seg[p].left = max(seg[L(p)].left, seg[L(p)].sum+seg[R(p)].left);
  seg[p].right = max(seg[R(p)].right, seg[R(p)].sum+seg[L(p)].right);
  seg[p].sum = seg[L(p)].sum+seg[R(p)].sum;
  seg[p].maxi = max(seg[p].sum, seg[p].right);
  seg[p].maxi = max(seg[p].maxi, max(seg[L(p)].maxi, seg[R(p)].maxi));
  seg[p].maxi = max(seg[p].maxi, seg[p].left);
  seg[p].maxi = max(seg[p].maxi, seg[R(p)].left+seg[L(p)].right);
}
 
void build(int p, int l, int r) {
  if (l == r) {
    seg[p].maxi = max(0LL, arr[l]);
    seg[p].sum = arr[l];
    seg[p].left = seg[p].maxi;
    seg[p].right = seg[p].maxi;
    return;
  }
  build(L(p), l, M(l,r));
  build(R(p), M(l,r)+1, r);
  f(p);
}
 
void update(int p, int l, int r, int k, ll x) {
  if (l > k || r < k) return;
  if (l == r) {
    seg[p].maxi = max(0LL, x);
    seg[p].sum = x;
    seg[p].left = seg[p].maxi;
    seg[p].right = seg[p].maxi;
    return;
  }
  update(L(p), l, M(l,r), k, x);
  update(R(p), M(l,r)+1, r, k, x);
  f(p);
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  build(1, 1, n);
  while (m--) {
    int k; ll x;
    cin >> k >> x;
    update(1, 1, n, k, x);
    cout << seg[1].maxi << '\n';
  }
  return 0;
}