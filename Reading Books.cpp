#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
  int n;
  ll t[(int)2e5+5], s = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    s += t[i];
  }
  sort(t,t+n);
  ll ans = s+abs(2*t[n-1]-s);
  if (s-t[n-1] >= t[n-1])
    ans = s;
  cout << ans;
}