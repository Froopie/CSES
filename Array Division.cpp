#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 5e5 + 5;
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, arr[MAXN]; cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  ll l = 0, r = 1000000000LL*5*100000, ans = -1;
  while (l <= r) {
    ll mid = (r+l)>>1;
    ll cur = arr[0], us = 0, i = 0;
    while (us < k-1) {
      while (cur+1LL*arr[i+1] <= mid && n-i-1 >= k-us-1)
        cur += 1LL*arr[++i];
      if (cur > mid) break;
      cur = arr[++i];
      us++;
    }
    i++;
    for (; i < n; i++) cur += 1LL*arr[i];
    if (cur <= mid) {
      ans = mid;
      r = mid-1;
    }
    else l = mid+1;
  }
  cout << ans;
  return 0;
}
