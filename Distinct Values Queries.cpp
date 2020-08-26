#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int BIT[MAXN];
map<int,int> vis;
int x[MAXN], nex[MAXN], ans[MAXN];
 
struct query{
  int i, l, r;
  query(int a, int b, int c) {
    i = a; l = b; r = c;
  }
  bool operator<(const query &c) {
    return l < c.l;
  }
};
vector<query> ve;
 
void update(int i, int v) {
  for (; i < MAXN; i += i&-i)
    BIT[i] += v;
}
 
int gets(int i) {
  int ret = 0;
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
    cin >> x[i];
    if (!vis[x[i]])
      update(i, 1);
    vis[x[i]] = i;
  }
  for (int i = n; i >= 1; i--) {
    if (vis[x[i]] == i)
      nex[i] = n+1;
    else {
      nex[i] = vis[x[i]];
      vis[x[i]] = i;
    }
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    ve.pb(query(i,l,r));
  }
  sort(all(ve));
  int l = 1;
  for (int i = 0; i < q; i++) {
    while (l < ve[i].l) {
      update(nex[l],1);
      l++;
    }
    ans[ve[i].i] = gets(ve[i].r)-gets(ve[i].l-1);
  }
  for (int i = 0; i < q; i++)
    cout << ans[i] << '\n';
  return 0;
}
