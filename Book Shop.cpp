#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
 
using namespace std;
 
int dp[MAXN]; 
pair<int,int> arr[1000];
int n, x;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> arr[i].first;
  for (int i = 0; i < n; i++) cin >> arr[i].second;
  dp[0] = 0;
  for (int i = 0; i < n; i++)
    for (int j = x-arr[i].first; j >= 0; j--)
      dp[j+arr[i].first] = max(max(0, dp[j])+arr[i].second, dp[j+arr[i].first]);
  cout << max(dp[x], 0);
  return 0;
}