#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define all(c) c.begin(), c.end()
#define pb push_back
#define ll long long
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  long double ans = 0;
  long double kk = pow(k,n);
  for (int i = 1; i <= k; i++)
    ans += i*(pow(i,n)-pow(i-1,n))/kk;
  cout << fixed << setprecision(6) << ans;
  return 0;
}