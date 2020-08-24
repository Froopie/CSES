#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int arr[5*MAXN];
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr+n);
  int mid = arr[n/2];
  ll ans = 0;
  for (int i = 0; i < n; i++) ans += abs(1LL*mid-1LL*arr[i]);
  cout << ans;
  return 0;
}
