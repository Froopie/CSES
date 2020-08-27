#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int cnt[MAXN];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int k; 
    cin >> k;
    cnt[k]++;
  }
  for (int i = 1e6; i >= 1; i--) {
    int cur = 0;
    for (int j = i; j <= 1e6; j += i) cur += cnt[j];
    if (cur > 1) {
      cout << i;
      break;
    }
  }
  return 0;
}
