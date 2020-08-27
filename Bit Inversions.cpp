#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
#define L(p) (p<<1)
#define R(p) (p<<1)+1
#define M(l, r) ((l+r)>>1)
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
struct node{
  int lz, lo, rz, ro;
  int maxi;
};
 
string s;
node ve[4*MAXN];
 
void build(int p, int l, int r) {
  if (l == r) {
    ve[p].maxi = 1;
    ve[p].lz = ve[p].lo = ve[p].rz = ve[p].ro = 0;
    if (s[l-1] == '0') ve[p].lz = ve[p].rz = 1;
    else ve[p].lo = ve[p].ro = 1;
    return;
  }
  build(L(p), l, M(l,r));
  build(R(p), M(l,r)+1, r);
  ve[p].lz = ve[L(p)].lz;
  ve[p].rz = ve[R(p)].rz;
  ve[p].lo = ve[L(p)].lo;
  ve[p].ro = ve[R(p)].ro;
  ve[p].maxi = max(max(ve[p].maxi, ve[R(p)].lo+ve[L(p)].ro), ve[R(p)].lz+ve[L(p)].rz);
  if (ve[L(p)].lz == M(l,r)-l+1) ve[p].lz = ve[L(p)].lz+ve[R(p)].lz;
  if (ve[L(p)].lo == M(l,r)-l+1) ve[p].lo = ve[L(p)].lo+ve[R(p)].lo;
  if (ve[R(p)].ro == r-M(l,r)) ve[p].ro = ve[L(p)].ro+ve[R(p)].ro;
  if (ve[R(p)].rz == r-M(l,r)) ve[p].rz = ve[L(p)].rz+ve[R(p)].rz;
  ve[p].maxi = max(ve[p].maxi, max(ve[L(p)].maxi, ve[R(p)].maxi));
}
 
void update(int p, int l, int r, int i) {
  if (l > i || r < i) return;
  if (l == r) {
    ve[p].lz = ve[p].lo = ve[p].rz = ve[p].ro = 0;
    if (s[l-1] == '1') ve[p].lz = ve[p].rz = 1;
    else ve[p].lo = ve[p].ro = 1;
    s[l-1] = (s[l-1]-'0')^1+'0';
    return;
  }
  update(L(p), l, M(l,r), i);
  update(R(p), M(l,r)+1, r, i);
  ve[p].maxi = 0;
  ve[p].lz = ve[L(p)].lz;
  ve[p].rz = ve[R(p)].rz;
  ve[p].lo = ve[L(p)].lo;
  ve[p].ro = ve[R(p)].ro;
  ve[p].maxi = max(max(ve[p].maxi, ve[R(p)].lo+ve[L(p)].ro), ve[R(p)].lz+ve[L(p)].rz);
  if (ve[L(p)].lz == M(l,r)-l+1) ve[p].lz = ve[L(p)].lz+ve[R(p)].lz;
  if (ve[L(p)].lo == M(l,r)-l+1) ve[p].lo = ve[L(p)].lo+ve[R(p)].lo;
  if (ve[R(p)].ro == r-M(l,r)) ve[p].ro = ve[L(p)].ro+ve[R(p)].ro;
  if (ve[R(p)].rz == r-M(l,r)) ve[p].rz = ve[L(p)].rz+ve[R(p)].rz;
  ve[p].maxi = max(ve[p].maxi, max(ve[L(p)].maxi, ve[R(p)].maxi));
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  build(1, 1, (int)s.size());
  int n;
  cin >> n;
  while (n--) {
    int i; 
    cin >> i;
    update(1, 1, (int)s.size(), i);
    cout << ve[1].maxi << ' ';
  }
  return 0;
}
