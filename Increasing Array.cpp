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
  int n; cin >> n;
  int arr[MAXN];
  for (int i = 0; i < n; i++) cin >> arr[i];
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    ans += max(1LL*(arr[i-1]-arr[i]), 0LL);
    arr[i] = max(arr[i], arr[i-1]);
  } 
  cout << ans;
  return 0;
}