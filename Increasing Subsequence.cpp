#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 2e5 + 5;
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, arr[MAXN];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<int> ve = {arr[0]};
  for (int i = 1; i < n; i++) {
    if (arr[i] > ve.back()) ve.pb(arr[i]);
    else ve[lower_bound(all(ve), arr[i])-ve.begin()] = arr[i];
  }
  cout << ve.size();
  return 0;
}