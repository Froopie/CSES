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
  int arr[MAXN];
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr+n);
  int l = 0, r = n-1, ans = 0;
  while (r >= l) {
    if (l == r) {
      ans++;
      break;
    }
    if (arr[r]+arr[l] <= x) l++;
    r--; ans++;
  }
  cout << ans;
  return 0;
}