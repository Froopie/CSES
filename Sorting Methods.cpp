#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
#define M(l,r) ((l+r)>>1)
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
ll ans1, ans2, ans3, ans4, n;
int arr[MAXN];
 
vector<int> m1(int l, int r) {
  if (l == r) return {arr[l]};
  auto v1 = m1(l, M(l,r));
  auto v2 = m1(M(l,r)+1, r);
  int p1 = 0, p2 = 0;
  vector<int> ret;
  while (p1 < (int)v1.size() || p2 < (int)v2.size()) {
    if (p1 == (int)v1.size()) ret.pb(v2[p2++]);
    else if (p2 == (int)v2.size() || v1[p1] < v2[p2]) ret.pb(v1[p1++]);
    else {
      ans1 += (int)v1.size()-p1;
      ret.pb(v2[p2++]);
    }
  }
  return ret;
}
 
void m2() {
  int all[MAXN], temp[MAXN];
  memcpy(all, arr, sizeof arr);
  memcpy(temp, arr, sizeof arr);
  sort(all, all+n);
  for (int i = 0; i < n; i++)
    while (temp[i] != all[i]) {
      swap(temp[i], temp[lower_bound(all, all+n, temp[i])-all]);
      ans2++;
    }
}
 
void m3() {
  vector<int> cur = {arr[0]};
  for (int i = 1; i < n; i++) {
    if (arr[i] > cur.back()) cur.pb(arr[i]);
    else cur[lower_bound(all(cur), arr[i])-cur.begin()] = arr[i];
  }
  ans3 = n-(int)cur.size();
}
 
void m4() {
  int cur = n;
  for (int i = n-1; i >= 0; i--)
    if (arr[i] == cur) cur--;
  ans4 = cur;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  m1(0, n-1); m2(); m3(); m4();
  cout << ans1 << ' ' << ans2 << ' ' << ans3 << ' ' << ans4;
  return 0;
}