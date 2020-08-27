#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 5e5 + 5;
 
using namespace std;
 
int arr[MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<int> ve;
  ve.pb(0);
  int next[MAXN], next2[MAXN];
  for (int i = 0; i < n; i++) next[i] = n;
  for (int i = 0; i < n; i++) next2[i] = -1;
  for (int i = 1; i < n; i++) {
    while (!ve.empty() && arr[i] < arr[ve.back()]) {
      next[ve.back()] = i;
      ve.pop_back();
    }
    ve.pb(i);
  }
  ve.clear();
  ve.pb(n-1);
  for (int i = n-2; i >= 0; i--) {
    while (!ve.empty() && arr[i] < arr[ve.back()]) {
      next2[ve.back()] = i;
      ve.pop_back();
    }
    ve.pb(i);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, 1LL*arr[i]*(1LL*next[i]-1LL*next2[i]-1LL));
  cout << ans;
  return 0;
}