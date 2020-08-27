#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 5e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int dp[MAXN], last[26];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  dp[0] = 1;
  memset(last, -1, sizeof last);
  for (int i = 0; i < n; i++) {
    dp[i+1] = (2*dp[i])%mod;
    if (last[s[i]-'a'] != -1) {
      dp[i+1] -= dp[last[s[i]-'a']];
      dp[i+1] += mod;
      dp[i+1] %= mod;
    }
    last[s[i]-'a'] = i;
  }
  cout << (dp[n]-1+mod)%mod;
  return 0;
}