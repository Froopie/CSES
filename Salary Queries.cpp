#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
struct pt{
  char a;
  int l, r;
};
 
int BIT[6*MAXN];
vector<int> se;
 
void update(int i, int v) {
  for (; i <= (int)se.size(); i += i&-i) BIT[i] += v;
}
 
int get(int i) {
  int v = 0;
  for (; i > 0; i -= i&-i) v += BIT[i];
  return v;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q, arr[2*MAXN], N = 0;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    se.pb(arr[i]);
  }
  vector<pt> ve;
  for (int i = 0; i < q; i++) {
    pt k;
    cin >> k.a >> k.l >> k.r;
    ve.pb(k);
    if (k.a == '!') se.pb(k.r);
    else {
      se.pb(k.l);
      se.pb(k.r);
    }
  }
  sort(all(se));
  unique(all(se));
  for (int i = 1; i <= n; i++)
    update(lower_bound(all(se), arr[i])-se.begin()+1, 1);
  for (int i = 0; i < q; i++) {
    if (ve[i].a == '!') {
      update(lower_bound(all(se), arr[ve[i].l])-se.begin()+1, -1);
      arr[ve[i].l] = ve[i].r;
      update(lower_bound(all(se), ve[i].r)-se.begin()+1, 1);
    }
    else cout << get(lower_bound(all(se), ve[i].r)-se.begin()+1)-get(lower_bound(all(se), ve[i].l)-se.begin()) << '\n';
  }
  return 0;
}